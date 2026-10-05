# Launch Ticket Management System

A console application in C for booking passenger seats on a river launch (passenger vessel). Originally developed for **CSE115 / CSE115L — Programming Language I** at **North South University**, around December 2022; the supplied report records submission on **1 January 2023**.

**Status:** Working educational prototype, restored for a portfolio in September 2026. No real payment processing.

## Original team

- Ibrahim Adham Surja
- Sanjida Khanom

The original report lists both students. Individual implementation responsibilities cannot be established from the supplied files, so this repository credits the team without claiming sole authorship.

## Features

- Create an account and sign in using an account number and password.
- Check seat availability on Dhaka–Barishal–Bhola and the reverse route.
- Select either of two historical demo dates: 20/12/22 and 21/12/22.
- Book economy (BDT 500) or business (BDT 900) seats.
- Maintain 100 seats for each route, date and class combination.
- Prevent booking an occupied seat.
- View your bookings and total bill.
- Save accounts and seat ownership locally, preserving bookings across restarts.

## Concepts demonstrated

C structs, arrays, strings, functions, loops, conditions, standard input/output, file handling and input validation. The seat array is indexed by route, date, class and seat; each entry stores the booking owner's account number.

## Build and run

Requires a C compiler supporting C11 (GCC or Clang). No third-party C dependencies.

From the repository root on Linux/macOS:

```sh
mkdir -p build
gcc -std=c11 -Wall -Wextra -pedantic src/main.c -o build/launch-ticket
./build/launch-ticket
```

On Windows with GCC/MinGW, run these separately in PowerShell:

```powershell
New-Item -ItemType Directory -Force build
gcc -std=c11 -Wall -Wextra -pedantic src/main.c -o build/launch-ticket.exe
.\build\launch-ticket.exe
```

For Code::Blocks, create a C console project and replace its generated main.c with `src/main.c`. Build and run. The compiler must be installed separately if your Code::Blocks package does not include one.

The program writes `launch_data.txt` in its **working directory**. Use the same directory to keep the same demo data. To reset the demo, close the program and remove that file. The restored version does not import the old `bst_output.txt` format.

## Example walkthrough

1. Sign up using fictional details; note the generated account number.
2. Log in with that account number and demo password.
3. Choose Buy ticket → route 1 → date 1 → economy → seat 7 → payment amount 500.
4. Choose My bookings to see the ticket and BDT 500 total.
5. Log out and exit. Restart and log in again to confirm the booking is retained.

## Repository layout

| Path | Purpose |
|---|---|
| `src/main.c` | Restored, runnable version |
| `archive/original_final_project.c` | Unmodified original final source |
| `docs/AUDIT.md` | ZIP inventory, original issues and restoration notes |
| `docs/VERIFICATION.md` | Checks performed and platform limitations |
| `tests/smoke_test.py` | Automated integration checks (Python 3 and GCC) |

## Original work and later restoration

The original source already contained account creation, login, route/date/class selection, seat availability and simulated purchases. It attempted account file persistence.

The September 2026 restoration was prepared with **AI assistance**: repeated booking branches were consolidated; unsafe input and indexes were corrected; missing-file handling, reliable record counting, booking persistence, ownership tracking, total bills and a bookings view were added. These later changes are not presented as features completed in 2022. The original source is preserved for comparison.

## Limitations

- A single-process local teaching demo, with a maximum of 100 accounts.
- Passwords are visible when entered and stored in plaintext. Use fictional details and disposable passwords only. Not suitable for production authentication.
- Payment is a typed amount, not a payment gateway.
- Dates and fares are fixed historical examples, not a current schedule.
- No cancellation, live schedule management, database, encryption or concurrent booking support.
- New data uses a different file format from the original.
- No license has been selected; team ownership should be considered before choosing one.

## Verification

```sh
python3 tests/smoke_test.py
```

See [verification notes](docs/VERIFICATION.md). The archive contains known bugs and is provided as historical evidence, not the recommended executable version.
