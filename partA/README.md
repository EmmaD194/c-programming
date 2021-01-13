This is a c program that takes the four letters of Neucleic Acid Notation (NAN), G, C, A, T and compresses or decompresses 
the string of letters into a string of 0's and 1's.
 G is 00, C is 01, A is 10, and T is 11.
The length of the compressed string is also returned.


I have this progrma working on both my raspberry pi machine and my windows pc with
gcc installed. However the program
only works with spaces in between the characters.
Compile using:
gcc partA.c
and then run the program with:
./a.exe encode G A T C
or
./a.exe decode 01 11 10 00