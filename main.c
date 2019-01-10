//
//  main.c
//  troika-test
//
//  Created by he on 20.12.18.
//  Copyright © 2018 he. All rights reserved.
//

#include "troika.h"
#include "ftroika.h"

#define TRITMAX (729)

long getMicrotime(){
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);
    return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

void stateToFstate(Trit* state, T27* fstate){
    const int slices = 27, colums = 9, rows = 3, slicesize = rows*colums;
    for (int slice = 0; slice < slices; ++slice){
        for (int row = 0; row < rows; ++row){
            for (int colum = 0; colum < colums; ++colum){
                Trit t = state[slicesize * slice + colums * row + colum];
                t27_set(&fstate[colums * row + colum], slice, t);
            }
        }
    }
}
int compareStates(Trit* state, T27* fstate){
    const int slices = 27, colums = 9, rows = 3, slicesize = rows*colums;
    for (int slice = 0; slice < slices; ++slice){
        for (int row = 0; row < rows; ++row){
            for (int colum = 0; colum < colums; ++colum){
                Trit t = state[slicesize * slice + colums * row + colum];
                Trit ft = t27_get(&fstate[colums * row + colum], slice);
                if (t != ft){
                    return 0;
                }
            }
        }
    }
    return 1;
}
int testAbsorb(){
    int times = 729, rounds = 24, i, retval = 1;
    Trit state[SLICES * SLICESIZE], in[729];
    memset(state, 0, SLICES * SLICESIZE * sizeof(Trit));
    memset(in, 0, 729 * sizeof(Trit));
    T27 fstate[SLICES];
    uint8_t fin[729];
    memset(fstate, 0, SLICESIZE * sizeof(T27));
    memset(fin, 0, 729 * sizeof(uint8_t));
    for (i = 1; i < times; i++) {
        TroikaAbsorb(state, 243, in, i, rounds);
        fTroikaAbsorb(fstate, 243, fin, i, rounds);
        if (! compareStates(state, fstate)){
            retval = 0;
        }
        memcpy(in, state, 729);
        memcpy(fin, in, 729);
    }
    printf("test Absorb: %s\n",retval?"PASS":"FAIL");
    return retval;
}
int testPermutations(){
    int times = 1000, rounds = 24, i, retval = 1;
    Trit state[SLICES * SLICESIZE];
    memset(state, 0, SLICES * SLICESIZE * sizeof(Trit));
    T27 fstate[SLICES];
    memset(fstate, 0, SLICESIZE * sizeof(T27));
    for (i = 0; i < times; i++) {
        TroikaPermutation(state, rounds);
        fTroikaPermutation(fstate, rounds);
        if (! compareStates(state, fstate)){
            retval = 0;
        }
    }
    printf("test Permutations: %s\n",retval?"PASS":"FAIL");
    return retval;
}
int testRepeated(int times){
    int i, retval = 1;
    Trit in[243], out[243];
    memset(in, 0, 243 * sizeof(Trit));
    memset(out, 0, 243 * sizeof(Trit));
    uint8_t fin[243], fout[243];
    memset(fin, 0, 243 * sizeof(uint8_t));
    memset(fout, 0, 243 * sizeof(uint8_t));
    for (i = 0; i < times; i++) {
        Troika(out, 243, in, 243);
        memcpy(in, out, 243 * sizeof(Trit));
    }
    fTroika243repeated(fout, fin, times);
    if (memcmp(fout, out, 243 * sizeof(uint8_t))){
        retval = 0;
    }
    printf("test Repeated: %s\n",retval?"PASS":"FAIL");
    return retval;
}
void speedTroika(int times){
    long mt1 = getMicrotime();
    int retval = 1;
    Trit in[243], out[243];
    memset(in, 0, 243 * sizeof(Trit));
    memset(out, 0, 243 * sizeof(Trit));
    for (int i = 0; i < times; i++) {
        Troika(out, 243, in, 243);
        memcpy(in, out, 243 * sizeof(Trit));
    }
    long mt2 = getMicrotime();
    int ms = (int)(mt2-mt1)/1000;
    printf("original Troika: %d ms per %d\n",ms,times);
}
void speedFTroika(int times){
    long mt1 = getMicrotime();
    uint8_t fin[243], fout[243];
    memset(fin, 0, 243 * sizeof(uint8_t));
    memset(fout, 0, 243 * sizeof(uint8_t));
    for (int i = 0; i < times; i++) {
        fTroika(fout, 243, fin, 243);
        memcpy(fin, fout, 243 * sizeof(uint8_t));
    }
    long mt2 = getMicrotime();
    int ms = (int)(mt2-mt1)/1000;
    printf("fTroika: %d ms per %d\n",ms,times);
}
void speedRepeated(int times){
    long mt1 = getMicrotime();
    int i, retval = 1;
    uint8_t fin[243], fout[243];
    memset(fin, 0, 243 * sizeof(uint8_t));
    memset(fout, 0, 243 * sizeof(uint8_t));
    fTroika243repeated(fout, fin, times);
    long mt2 = getMicrotime();
    int ms = (int)(mt2-mt1)/1000;
    printf("fTroika243Repeated: %d ms per %d\n",ms,times);
}

int main(int argc, const char * argv[]){
    int test[10];
    test[0] = testAbsorb();
    test[1] = testPermutations();
    test[2] = testRepeated(1000);
    speedTroika(10000);
    speedFTroika(10000);
    speedRepeated(10000);
    return 0;
}
