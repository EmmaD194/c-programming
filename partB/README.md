a program that reads in simple boolean expressions in postfix notation, evaluates the expression and writes out the result. The input is "TRUE" and "FALSE" and the operators "AND", "OR" and "NOT".
For example, if the input is:


TRUE  TRUE  AND FALSE OR  NOT

the output is:       FALSE

I have this program working on both my raspberry pi machine and my windows pc with
gcc installed.
Compile using:
gcc partB.c
and then run the program with:
./a.exe TRUE FALSE AND