//
//  ftroika.h
//  troika-test
//
//  Created by he on 21.12.18.
//  Copyright © 2018 he. All rights reserved.
//

#ifndef ftroika_h
#define ftroika_h

#include <stdio.h>
#include "general.h"
#include "t27.h"

void fSubTrytes(T27 *state);
void fShiftRows(T27 *state);
void fShiftLanes(T27 *state);
void fAddColumnParity(T27 *state);
void fPrintRoundConstants();
void fAddRoundConstant(T27 *state, int round);
void fTroikaPermutation(T27 *state, unsigned long long num_rounds);
void fTroikaNullifyState(T27* state);
void fTroikaNullifyRate(T27* state);
void fTroikaNullifyCapacity(T27* state);
void fTroikaTritsToRate(T27* state, const uint8_t* trits, int len);
void fTroikaRateToTrits(const T27* state, uint8_t* trits, int len);
int fTroikaTrytesToState(T27* state, const uint8_t* trytes, int len);
int fTroikaCompareStates(T27* state, T27* other);
void fTroikaIncreaseState(T27* state);
void fTroikaAbsorb(T27 *state, unsigned int rate, const uint8_t *message,
                          unsigned long long message_length,
                          unsigned long long num_rounds);
void fTroikaSqueeze(uint8_t *hash, unsigned long long hash_length,
                           unsigned int rate, T27 *state,
                           unsigned long long num_rounds);
void fTroika(uint8_t *out, unsigned long long outlen,
             const uint8_t *in, unsigned long long inlen);
void fTroikaVarRounds(uint8_t *out, unsigned long long outlen,
                      const uint8_t *in, unsigned long long inlen,
                      unsigned long long num_rounds);
void fTroika243repeated(uint8_t *out, const uint8_t *in, int repeat);


#endif /* ftroika_h */
