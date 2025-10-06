# Format String Vulnerability Lab (COMP 352/452 - Lab 8)

This lab demonstrates how format string vulnerabilities can be used to:

- Leak memory addresses and secrets
- Modify program variables in memory
- Execute privilege escalation techniques

## Lab Tasks

Based on the COMP 352/452 Fall 2024 syllabus (adapted from SEED Labs):

1. Crash the program using format string injection
2. Leak the value of the `secret` variable
3. Modify `secret` to a user-defined value (e.g. `0x42454546`)
4. Attempt privilege escalation (get a root shell)

## Files

- `Lab8.c` — vulnerable C program with format string issue
- `exploit.py` — Python script that:
  - Extracts the secret variable address
  - Crafts format string payload
  - Writes to `vulfile`
  - Runs the exploit
- `Lab8.pdf` — official instructions with scoring and tasks

## Setup (inside SEED VM)

```bash
gcc -z execstack -o vul_prog Lab8.c
sudo chown root vul_prog
sudo chmod +s vul_prog
```

Then run the exploit using:

```bash
python3 exploit.py
```

## Notes

- The binary prints helpful info like the address of `secret`
- All exploit attempts are run by feeding payloads via a file (`vulfile`)
- You are **not allowed to modify `Lab8.c`**
- Include screenshots and explanations in the PDF report
