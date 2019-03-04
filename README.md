update 2019-03-04

added a branch "streaming", which picks up improvement ideas by shufps.
If you want to see ongoing dev, go there.

_______________________________

# fTroika

based on the original implementation, but with differently organized data.
The functions do just the same, only on different structures. 
Lanes are the basic trit vecors of type T27, containig 27 trits, see t27.h, which has the low level stuff.

T27 state[27] is the troika state.

state[0] is row 0, colum 0, with all slice0 ... slice26

state[1] is row 0, colum 1, again the whole lane.

For basic usage, look at the tests in main.c.
Clone it, go to the folder with the .c files, run
```
gcc -O3 *.c -o troika
./troika
```
to see it running.

_____________________________

original README.md:
# Troika

This repository contains the reference implementation of the Troika hash
function. Troika is a cryptographic hash function operating on ternary messages
for the use in IOTA’s distributed ledger technology designed. 

For further information see the [Troika website](https://www.cyber-crypt.com/troika).
