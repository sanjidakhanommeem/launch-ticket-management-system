/* Portfolio restoration (2026); original student source is in archive/. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#define MAX 100
#define TEXT 100
struct Account { char name[TEXT], phone[TEXT], password[TEXT]; int age, bill; };
static struct Account accounts[MAX];
static int count;
/* Each cell stores the account number owning this seat; zero means free. */
static int seats[2][2][2][MAX];
static const char *routes[] = {"Dhaka-Barishal-Bhola", "Bhola-Barishal-Dhaka"};
static const char *dates[] = {"20/12/22", "21/12/22"};
static const char *classes[] = {"Economy", "Business"};
static const int fares[] = {500, 900};
static void line(const char *prompt, char *out, size_t size) {
    for (;;) {
        printf("%s", prompt); fflush(stdout);
        if (!fgets(out, (int)size, stdin)) { puts("\nInput closed."); exit(0); }
        char *end = strchr(out, '\n');
        if (end) *end = '\0';
        else { int c = getchar(); if (c != EOF) { while (c != '\n' && c != EOF) c = getchar(); puts("Input too long. Try again."); continue; } }
        size_t n = strlen(out); if (n && out[n-1] == '\r') out[--n] = '\0';
        if (n) return;
        puts("Input cannot be empty.");
    }
}
static int number(const char *prompt, int min, int max) {
    char buffer[TEXT], *end;
    for (;;) {
        line(prompt, buffer, sizeof buffer); errno = 0;
        long value = strtol(buffer, &end, 10);
        if (!errno && end != buffer && *end == '\0' && value >= min && value <= max) return (int)value;
        printf("Enter a whole number from %d to %d.\n", min, max);
    }
}
static int save(void) {
    FILE *f = fopen("launch_data.tmp", "w");
    if (!f) { perror("Save failed"); return 0; }
    fprintf(f, "LAUNCH_V1\n%d\n", count);
    for (int i=0; i<count; i++) fprintf(f, "%s\n%s\n%s\n%d %d\n", accounts[i].name, accounts[i].phone, accounts[i].password, accounts[i].age, accounts[i].bill);
    for (int r=0;r<2;r++) for(int d=0;d<2;d++) for(int c=0;c<2;c++) for(int s=0;s<MAX;s++) fprintf(f,"%d\n", seats[r][d][c][s]);
    int failed = ferror(f); if (fclose(f)) failed=1;
    if (failed) { puts("Save failed; previous data retained."); return 0; }
#ifdef _WIN32
    /* C rename on Windows cannot replace an existing destination. */
    if (remove("launch_data.txt") && errno != ENOENT) { perror("Save failed"); return 0; }
#endif
    if (rename("launch_data.tmp", "launch_data.txt")) { perror("Save failed"); return 0; }
    return 1;
}
static int read_text(FILE *f, char *out) {
    if (!fgets(out, TEXT, f)) return 0;
    char *p=strchr(out,'\n'); if(!p) return 0; *p='\0'; return out[0] != '\0';
}
static void load(void) {
    FILE *f=fopen("launch_data.txt","r");
    if(!f) { if(errno==ENOENT) return; perror("Cannot read data"); exit(1); }
    char header[TEXT]; int ok=read_text(f,header) && !strcmp(header,"LAUNCH_V1") && fscanf(f,"%d\n",&count)==1 && count>=0 && count<=MAX;
    for(int i=0;ok && i<count;i++) {
        ok=read_text(f,accounts[i].name) && read_text(f,accounts[i].phone) && read_text(f,accounts[i].password) && fscanf(f,"%d %d\n",&accounts[i].age,&accounts[i].bill)==2 && accounts[i].age>=1 && accounts[i].age<=120 && accounts[i].bill>=0;
    }
    for(int r=0;ok && r<2;r++) for(int d=0;ok && d<2;d++) for(int c=0;ok && c<2;c++) for(int s=0;ok && s<MAX;s++) ok=fscanf(f,"%d",&seats[r][d][c][s])==1 && seats[r][d][c][s]>=0 && seats[r][d][c][s]<=count;
    fclose(f);
    if(!ok) { fputs("Invalid data file. Restore a backup or move it aside before starting.\n",stderr); exit(1); }
}
static int choose_date(void) {
    printf("1. %s\n2. %s\n",dates[0],dates[1]); return number("Date: ",1,2)-1;
}
static void session(int user) {
    printf("Welcome %s!\n",accounts[user].name);
    for(;;) {
        puts("1. Outbound availability\n2. Return availability\n3. Buy ticket\n4. Logout\n5. My bookings");
        int option=number("Option: ",1,5);
        if(option==4) return;
        if(option<=2) {
            int r=option-1,d=choose_date();
            printf("%s | %s\n",routes[r],dates[d]);
            for(int c=0;c<2;c++) { printf("%s (BDT %d)\n",classes[c],fares[c]); for(int s=0;s<MAX;s++) printf("Seat %d: %s\n",s+1,seats[r][d][c][s]?"Booked":"Available"); }
        } else if(option==3) {
            printf("1. %s\n2. %s\n",routes[0],routes[1]);
            int r=number("Route: ",1,2)-1,d=choose_date();
            puts("1. Economy (BDT 500)\n2. Business (BDT 900)");
            int c=number("Class: ",1,2)-1,s=number("Seat (1-100): ",1,MAX)-1;
            if(seats[r][d][c][s]) { puts("Seat already booked. Choose another."); continue; }
            int payment=number("Simulated payment amount (BDT): ",0,INT_MAX);
            if(payment!=fares[c]) { puts("Incorrect amount; booking not made."); continue; }
            if(accounts[user].bill>INT_MAX-fares[c]) { puts("Bill limit reached."); continue; }
            seats[r][d][c][s]=user+1; accounts[user].bill+=fares[c];
            if(!save()) { seats[r][d][c][s]=0; accounts[user].bill-=fares[c]; puts("Booking rolled back."); continue; }
            printf("Booking confirmed: %s | %s | %s | Seat %d | BDT %d\n",routes[r],dates[d],classes[c],s+1,fares[c]);
        } else {
            for(int r=0;r<2;r++) for(int d=0;d<2;d++) for(int c=0;c<2;c++) for(int s=0;s<MAX;s++) if(seats[r][d][c][s]==user+1) printf("%s | %s | %s | Seat %d\n",routes[r],dates[d],classes[c],s+1);
            printf("Total bill: BDT %d\n",accounts[user].bill);
        }
    }
}
int main(void) {
    load(); puts("Launch Ticket Management System\nHistorical demo dates; simulated payment only.");
    for(;;) {
        puts("1. Sign up\n2. Login\n3. Exit"); int option=number("Option: ",1,3);
        if(option==3) return 0;
        if(option==1) {
            if(count==MAX) { puts("Account limit reached."); continue; }
            struct Account *a=&accounts[count];
            line("Name: ",a->name,TEXT); a->age=number("Age: ",1,120);
            line("Phone: ",a->phone,TEXT); line("Demo password (do not reuse a real password): ",a->password,TEXT); a->bill=0;
            count++; if(!save()) { count--; puts("Account creation rolled back."); continue; }
            printf("Account created. Your account number: %d\n",count);
        } else {
            int id=number("Account number: ",1,MAX); char password[TEXT];
            line("Password: ",password,TEXT);
            if(id>count || strcmp(password,accounts[id-1].password)!=0) { puts("Invalid account number or password."); continue; }
            session(id-1);
        }
    }
}
