#include <stdio.h>
#include <string.h>
FILE *f;
int day1eco[100] = {0};
int day1busi[100] = {0};
int day2eco[100] = {0};
int day2busi[100] = {0};
char date1[100] = "20/12/22";
char date2[100] = "21/12/22";
int rday1eco[100] = {0};
int rday1busi[100] = {0};
int rday2eco[100] = {0};
int rday2busi[100] = {0};

struct account
{
    char name[100];
    int age;
    char phone_number[100];
    // char email[100];
    char password[100];
    int acno;
    int total_bill;
};
struct account ac[100];
void create_ac(int x)
{
    ac[x].acno = x + 1;
    ac[x].total_bill = 0;
    printf("please enter your name:");
    scanf("%s", ac[x].name);
    printf("\n");
    printf("please enter your age:");
    scanf("%d", &ac[x].age);
    printf("\n");
    printf("please enter your phone number:");
    scanf("%s", ac[x].phone_number);
    printf("\n");
    printf("please enter a password:");
    scanf("%s", ac[x].password);
    printf("\n");
    printf("your account no is:%d\n", ac[x].acno);
    ac[x].total_bill = 0;
    printf("Your account has been created!!\n");
}
void date(char d1[], char d2[])
{
}
void login(int x)
{
    while (1)
    {
        printf("-------Menu--------\n");
        printf("1.Available launch ticket[Dhaka-Barishal-Bhola]\n");
        printf("2.Available launch ticket[Bhola-Barishal-Dhaka]\n");
        printf("3.Buy Ticket\n");
        printf("4.logout");
        int ch;
        printf("\n");
        printf("please enter an option:");
        scanf("%d", &ch);
        printf("\n");
        if (ch == 1)
        {
            int a;
            printf("1. %s\n", date1);
            printf("2. %s\n", date2);
            printf("Select Date:");
            scanf("%d", &a);

            if (a == 1)
            {
                printf("Economy Class Seats--->>Route[Dhaka-Barishal-Bhola]--->>Date: %s\n", date1);
                for (int i = 0; i < 100; i++)
                {
                    if (day1eco[i] == 0)
                        printf("Seat No:%d----->>Available.\n", i + 1);
                    else
                        printf("Seat No:%d----->>Booked.\n", i + 1);
                }
                printf("Business Class Seats--->>Route[Dhaka-Barishal-Bhola]--->>Date: %s\n", date1);
                for (int i = 0; i < 100; i++)
                {
                    if (day1busi[i] == 0)
                        printf("Seat No:%d----->>Available.\n", i + 1);
                    else
                        printf("Seat No:%d----->>Booked.\n", i + 1);
                }
            }
            else if (a == 2)
            {
                printf("Economy Class Seats--->>Route[Dhaka-Barishal-Bhola]--->>Date: %s\n", date2);
                for (int i = 0; i < 100; i++)
                {
                    if (day2eco[i] == 0)
                        printf("Seat No:%d----->>Available.\n", i + 1);
                    else
                        printf("Seat No:%d----->>Booked.\n", i + 1);
                }
                printf("Business Class Seats--->>Route[Dhaka-Barishal-Bhola]--->>Date: %s\n", date2);
                for (int i = 0; i < 100; i++)
                {
                    if (day2busi[i] == 0)
                        printf("Seat No:%d----->>Available.\n", i + 1);
                    else
                        printf("Seat No:%d----->>Booked.\n", i + 1);
                }
            }
        }
        else if (ch == 2)
        {
            int a;
            printf("1. %s\n", date1);
            printf("2. %s\n", date2);
            printf("Select Date:");
            scanf("%d", &a);
            printf("\n");

            if (a == 1)
            {
                printf("Economy Class Seats--->>Route[Bhola-Barishal-Dhaka]--->>Date: %s\n", date1);
                for (int i = 0; i < 100; i++)
                {
                    if (rday1eco[i] == 0)
                        printf("Seat No:%d----->>Available.\n", i + 1);
                    else
                        printf("Seat No:%d----->>Booked.\n", i + 1);
                }
                printf("Business Class Seats--->>Route[Bhola-Barishal-Dhaka]--->>Date: %s\n", date1);
                for (int i = 0; i < 100; i++)
                {
                    if (rday1busi[i] == 0)
                        printf("Seat No:%d----->>Available.\n", i + 1);
                    else
                        printf("Seat No:%d----->>Booked.\n", i + 1);
                }
            }
            else if (a == 2)
            {
                printf("Economy Class Seats--->>Route[Bhola-Barishal-Dhaka]--->>Date: %s\n", date2);
                for (int i = 0; i < 100; i++)
                {
                    if (rday2eco[i] == 0)
                        printf("Seat No:%d----->>Available.\n", i + 1);
                    else
                        printf("Seat No:%d----->>Booked.\n", i + 1);
                }
                printf("Business Class Seats--->>Route[Bhola-Barishal-Dhaka]--->>Date: %s\n", date2);
                for (int i = 0; i < 100; i++)
                {
                    if (rday2busi[i] == 0)
                        printf("Seat No:%d----->>Available.\n", i + 1);
                    else
                        printf("Seat No:%d----->>Booked.\n", i + 1);
                }
            }
        }
        else if (ch == 3)
        {
            int a;
            printf("1.Dhaka-Barishal-Bhola\n");
            printf("2.Bhola-Barishal-Dhaka\n");
            printf("Select Route:");
            scanf("%d", &a);
            printf("\n");
            if (a == 1)
            {
                int c;
                printf("1. %s\n", date1);
                printf("2. %s\n", date2);
                printf("Select Date:");
                scanf("%d", &c);
                if (c == 1)
                {
                    int b;
                    printf("1.Economy Class Seats--->>Route[Dhaka-Barishal-Bhola]--->>Date: %s ---->Price:500/-\n", date1);
                    printf("2.Business Class Seats--->>Route[Dhaka-Barishal-Bhola]--->>Date: %s ---->Price:900/-\n", date1);
                    printf("Select One of them:");
                    scanf("%d", &b);
                    if (b == 1)
                    {
                        int seat;
                        printf("please Select an available Economy Class  seat:");
                        scanf("%d", &seat);
                        if (day1eco[seat - 1] == 0)
                        {
                            int taka;
                            printf("YES!!! This seat is availabel now... \n");
                            printf("please pay 500tk :");
                            scanf("%d", &taka);
                            if (taka == 500)
                            {
                                printf("payment successfully completed!!\n");
                                day1eco[seat - 1] = 1;
                            }
                            else
                            {
                                printf("Please pay exact 500/- \n!!!TRY AGAIN!!!\n");
                                continue;
                            }
                        }
                        else
                            printf("seat:%d is booked...please try another one ", seat);
                    }
                    else if (b == 2)
                    {
                        int seat;
                        printf("please Select an available Business Class seat:");
                        scanf("%d", &seat);

                        if (day1busi[seat - 1] == 0)
                        {
                            int taka;
                            printf("YES!!! This seat is availabel now... \n");
                            printf("please pay 900tk :");
                            scanf("%d", &taka);
                            if (taka == 900)
                            {
                                printf("payment successfully completed!!\n");
                                day1busi[seat - 1] = 1;
                            }
                            else
                            {
                                printf("Please pay exact 900/- \n!!!TRY AGAIN!!!\n\n");
                                continue;
                            }
                        }
                        else
                            printf("seat:%d is booked...please try another one ", seat);
                    }
                }
                else if (c == 2)
                {
                    int b;
                    printf("1.Economy Class Seats--->>Route[Dhaka-Barishal-Bhola]--->>Date: %s ---->Price:500/-\n", date1);
                    printf("2.Business Class Seats--->>Route[Dhaka-Barishal-Bhola]--->>Date: %s ---->Price:900/-\n", date1);
                    printf("Select One of them:");
                    scanf("%d", &b);
                    if (b == 1)
                    {
                        int seat;
                        printf("please Select an available Economy Class  seat:");
                        scanf("%d", &seat);
                        if (day2eco[seat - 1] == 0)
                        {
                            int taka;
                            printf("YES!!! This seat is availabel now... \n");
                            printf("please pay 500tk :");
                            scanf("%d", &taka);
                            if (taka == 500)
                            {
                                printf("payment successfully completed!!\n");
                                day2eco[seat - 1] = 1;
                            }
                            else
                            {
                                printf("Please pay exact 500/- \n!!!TRY AGAIN!!!\n\n");
                                continue;
                            }
                        }
                        else
                            printf("seat:%d is booked...please try another one ", seat);
                    }
                    else if (b == 2)
                    {
                        int seat;
                        printf("please Select an available Business Class seat:");
                        scanf("%d", &seat);

                        if (day2busi[seat - 1] == 0)
                        {
                            int taka;
                            printf("YES!!! This seat is availabel now... \n");
                            printf("please pay 900tk :");
                            scanf("%d", &taka);
                            if (taka == 900)
                            {
                                printf("payment successfully completed!!\n");
                                day2busi[seat - 1] = 1;
                            }
                            else
                            {
                                printf("Please pay exact 900/- \n!!!TRY AGAIN!!!\n");
                                continue;
                            }
                        }
                        else
                            printf("seat:%d is booked...please try another one ", seat);
                    }
                }
            }
            else if (a == 2)
            {
                int c;
                printf("1. %s\n", date1);
                printf("2. %s\n", date2);
                printf("Select Date:");
                scanf("%d", &c);
                if (c == 1)
                {
                    int b;
                    printf("1.Economy Class Seats--->>Route[Bhola-Barishal-Dhaka]--->>Date: %s ---->Price:500/-\n", date1);
                    printf("2.Business Class Seats--->>Route[Bhola-Barishal-Dhaka]--->>Date: %s ---->Price:900/-\n", date1);
                    printf("Select One of them:");
                    scanf("%d", &b);
                    if (b == 1)
                    {
                        int seat;
                        printf("please Select an available Economy Class  seat:");
                        scanf("%d", &seat);
                        if (rday1eco[seat - 1] == 0)
                        {
                            int taka;
                            printf("YES!!! This seat is availabel now... \n");
                            printf("please pay 500tk :");
                            scanf("%d", &taka);
                            if (taka == 500)
                            {
                                printf("payment successfully completed!!\n");
                                rday1eco[seat - 1] = 1;
                            }
                            else
                            {
                                printf("Please pay exact 500/- \n!!!TRY AGAIN!!!\n\n");
                                continue;
                            }
                        }
                        else
                            printf("seat:%d is booked...please try another one ", seat);
                    }
                    else if (b == 2)
                    {
                        int seat;
                        printf("please Select an available Business Class seat:");
                        scanf("%d", &seat);
                        if (rday1busi[seat - 1] == 0)
                        {
                            int taka;
                            printf("YES!!! This seat is availabel now... \n");
                            printf("please pay 900tk :");
                            scanf("%d", &taka);
                            if (taka == 900)
                            {
                                printf("payment successfully completed!!\n");
                                rday1busi[seat - 1] = 1;
                            }
                            else
                            {
                                printf("Please pay exact 900/- \n!!!TRY AGAIN!!!\n\n");
                                continue;
                            }
                        }
                        else
                            printf("seat:%d is booked...please try another one ", seat);
                    }
                }
                else if (c == 2)
                {
                    int b;
                    printf("1.Economy Class Seats--->>Route[Dhaka-Barishal-Bhola]--->>Date: %s ---->Price:500/-\n", date1);
                    printf("2.Business Class Seats--->>Route[Dhaka-Barishal-Bhola]--->>Date: %s ---->Price:900/-\n", date1);
                    printf("Select One of them:");
                    scanf("%d", &b);
                    if (b == 1)
                    {
                        int seat;
                        printf("please Select an available Economy Class  seat:");
                        scanf("%d", &seat);
                        if (rday2eco[seat - 1] == 0)
                        {
                            int taka;
                            printf("YES!!! This seat is availabel now... \n");
                            printf("please pay 500tk :");
                            scanf("%d", &taka);
                            if (taka == 500)
                            {
                                printf("payment successfully completed!!\n");
                                rday2eco[seat - 1] = 1;
                            }
                            else
                            {
                                printf("Please pay exact 500/- \n!!!TRY AGAIN!!!\n");
                                continue;
                            }
                        }
                        else
                            printf("seat:%d is booked...please try another one ", seat);
                    }
                    else if (b == 2)
                    {
                        int seat;
                        printf("please Select an available Business Class seat:");
                        scanf("%d", &seat);

                        if (rday2busi[seat - 1] == 0)
                        {
                            int taka;
                            printf("YES!!! This seat is availabel now... \n");
                            printf("please pay 900tk :");
                            scanf("%d", &taka);
                            if (taka == 900)
                            {
                                printf("payment successfully completed!!\n");
                                rday2busi[seat - 1] = 1;
                            }
                            else
                            {
                                printf("Please pay exact 900/- \n!!!TRY AGAIN!!!\n");
                                continue;
                            }
                        }
                        else
                            printf("seat:%d is booked...please try another one ", seat);
                    }
                }
            }
        }
        else if (ch == 4)
            break;
    }
}
void writeFile(FILE *fptr, int c)
{
    int i = 0;
    while (i < c)
    {
        fprintf(fptr, "%d %s %s %d %s %d\n", ac[i].acno, ac[i].name, ac[i].password, ac[i].age, ac[i].phone_number, ac[i].total_bill);
        i++;
    }
}
void readFile(FILE *fptr, int *c)
{
    while (!feof(fptr))
    {
        fscanf(fptr, "%d %s %s %d %s %d", &ac[*c].acno, ac[*c].name, ac[*c].password, &ac[*c].age, ac[*c].phone_number, &ac[*c].total_bill);
        (*c)++;
    }
}
int main()
{

    f = fopen("bst_output.txt", "r");
    int c = 0;
    readFile(f, &c);
    printf("%d %s %s %d %s %d\n", ac[0].acno, ac[0].name, ac[0].password, ac[0].age, ac[0].phone_number, ac[0].total_bill);
    fclose(f);
    f = fopen("bst_output.txt", "w");
    for (int i = c; i < 100; i++)
        ac[i].acno = 0;
    while (1)
    {
        printf("-------choice list--------\n");
        printf("1.sign up\n");
        printf("2.login\n");
        printf("3.Exit\n");
        int ch;
        printf("please enter an option:");
        scanf("%d", &ch);
        printf("\n");
        if (ch == 1)
        {
            create_ac(c);
            c++;
        }
        else if (ch == 2)
        {
            int acc;
            char pass[100];
            printf("please enter your account no:");
            scanf("%d", &acc);
            if (ac[acc - 1].acno == 0)
            {
                printf("invalid account no!!.....%d\n", ac[acc - 1].acno);
                continue;
            }
            printf("please enter your password:");
            scanf("%s", pass);
            if (strcmp(pass, ac[acc - 1].password) == 0)
            {
                printf("login successfully!!\n");
                printf("\nWelcome %s\n\n", ac[acc - 1].name);
                login(acc - 1);
            }
            else if (strcmp(pass, ac[acc - 1].password) == 1)
            {
                printf("password is wrong!! \n try again!!\n");
                continue;
            }
        }
        else if (ch == 3)
        {
            writeFile(f, c);
            break;
        }
        else
            printf("please enter a right option\n");
    }
    fclose(f);
    return 0;
}
