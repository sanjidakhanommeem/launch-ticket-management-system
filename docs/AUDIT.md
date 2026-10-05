# Source audit and restoration

## Evidence

The uploaded Project.zip contains four C source variants: `31.c`, `Final project.c`, `Launch ticket management system.c`, and `surja.c`. `Final project.c` was selected as the historical baseline because of its explicit final filename; it differs from `31.c` only by a commented email field. This is a reasoned choice, not proof of which version was submitted.

Two reports (`LAB REPORT02.pdf`, `LAB REPORTfinal.pdf`) identify the launch management project. The final report identifies CSE115L-17, instructor Mustafizur Rahaman, students Ibrahim Adham Surja and Sanjida Khanom, and submission date 1 January 2023. Demo dates in the source are 20 and 21 December 2022. Thus “December 2022; submitted January 2023” is the supported portfolio date.

The nested `project final.zip` contains `bus.c` and `bst_output.txt`. Despite that filename, the source is another launch-ticket implementation. It is not evidence of a separate bus project.

## Original implementation

- Accounts stored in an array of structs; maximum intended size 100.
- Eight seat arrays for two routes × two dates × two classes.
- Economy price 500 and business price 900, entered as simulated payment.
- Attempts to load and save accounts using `bst_output.txt`.
- Compiles with GCC C11, but compilation alone does not establish safe runtime behavior.

## Important original defects

| Defect | Effect | Restoration |
|---|---|---|
| fopen result not checked | Missing data file can crash | Missing file starts an empty demo; other errors stop clearly |
| `while (!feof(...))` and unchecked fscanf | Extra/invalid account count | Explicit validated record parsing |
| Unbounded `%s` input | Buffer overflow and names lose spaces | Bounded line input with overflow rejection |
| No account/seat bounds | Out-of-bounds array access | Numeric range checks |
| `strcmp(...) == 1` for failure | Some wrong passwords not reported | Check all nonzero results |
| Opening data for write at startup | Existing data truncated before normal exit | Temporary-file save after changes |
| Bookings only in memory | Seats become free after restart | Persist seat owners |
| `total_bill` never updated | No useful running total | Update bill after successful booking |
| Repeated route/date branches | Some labels show wrong date/route | Shared indexed implementation |
| No account capacity check | Overflow after 100 signups | Reject signups at the limit |

## Packaging decisions

- Keep one original final source and the restored source, clearly separated.
- Exclude old Windows executables and object files: build from source instead.
- Exclude empty data.txt/file.txt and local account data (including passwords/contact details).
- Do not publish the original reports by default: they contain student identifiers and are unnecessary to run the application. The user's original ZIP retains them.
- Do not invent individual contribution percentages, grades, successful deployment claims or a license.
- No fabricated Git history: the new upload should carry its actual upload date.

## Next possible improvements

Ticket cancellation, editable schedules, secure authentication, and database storage would be separate future work. They are not implemented here.
