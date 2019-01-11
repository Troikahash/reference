//  Created c-mnd he on 11.01.19.
//  MIT License, see LICENSE

// by now unused and left here for completeness
// but was very important for writing
// void fSubTrytes(T27 *state);

#ifndef sbox_lookup_h
#define sbox_lookup_h

static const int sbox_lookup[27] = {
    6, //  020 <-  0 0 000
    25, // 122 <-  1 A 100
    17, // 221 <-  2 B 200
    5, //  210 <-  3 C 010
    15, // 021 <-  4 D 110
    10, // 101 <-  5 E 210
    4, //  110 <-  6 F 020
    20, // 202 <-  7 G 120
    24, // 022 <-  8 H 220
    0, //  000 <-  9 I 001
    1, //  100 <- 10 J 101
    2, //  200 <- 11 K 201
    9, //  001 <- 12 L 011
    22, // 112 <- 13 M 111
    26, // 222 <- 14 N 211
    18, // 002 <- 15 O 021
    16, // 121 <- 16 P 121
    14, // 211 <- 17 Q 221
    3,  // 010 <- 18 R 002
    13, // 111 <- 19 S 102
    23, // 212 <- 20 T 202
    7,  // 120 <- 21 U 012
    11, // 201 <- 22 V 112
    12, // 011 <_ 23 W 212
    8,  // 220 <- 24 X 022
    21, // 012 <- 25 Y 122
    19  // 102 <- 26 Z 222
};

#endif /* sbox_lookup_h */
