# Verification

Checked in a Linux environment during the September 2026 restoration.

- Original final source compiles in C11; warns about unused parameters.
- Restored source compiles with `-std=c11 -Wall -Wextra -Werror -pedantic` without warnings.
- Automated integration checks pass for fresh startup, signup with a spaced name, valid and invalid login, invalid menu/seat input, successful booking, duplicate-seat rejection, incorrect payment, reverse-route business booking, running bills, persistence across restarts, closed input, and corrupted-file rejection.
- Historical dates and original fares are retained deliberately.

Windows commands are supplied, but Windows/Code::Blocks execution was not performed in this environment. The program is a single-process teaching demo, not a production reservation service. On Windows, replacing an existing data file requires removing the old file first; this is not crash-atomic. Keep backups if demo data matters.
