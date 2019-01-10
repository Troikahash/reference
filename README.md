# fTroika

based on the original implementation, but with differently organized data.
The functions do just the same, just on different structures. 
Lanes are the basic trit vecors of type T27, see t27.h which has the low level stuff.
For basic usage, look at the tests in main.c.
Clone it, go to the folder with the .c files, run
```
gcc -O3 *.c -o troika
./troika
```
to see it running


original README.md:
# Troika

This repository contains the reference implementation of the Troika hash
function. Troika is a cryptographic hash function operating on ternary messages
for the use in IOTA’s distributed ledger technology designed. 

For further information see the [Troika website](https://www.cyber-crypt.com/troika).
