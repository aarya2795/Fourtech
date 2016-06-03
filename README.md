Programming assignments for L3Cube Sponsorship


1. Is Birthday paradox really valid?

Write a code that verifies - birthday paradox is indeed correct.
(Note : Think of ways you could run 'random experiments'. We agree this problem is hard.)


2. Simple version control

GOAL: Create a simple version control (svc) program called svc.

DETAILS: We have a text file that needs version control i.e., ability to revert back to any previous version.

    The text that is composed of one or more lines.
    Each line has a maximum character width of 10 characters (including newline).
    The total number of lines is 20.

The following operations are permitted:
1. Appending a new line at the end of the file.
2. Deleting any existing line.

Only one of the above operations can be done at a given time i.e., the user can either append a line -or- delete a line.
After each operation, the file is commited using the svc.

The usage of svc is the following
svc filename : To commit
svc N : Output Nth version of the file. 
