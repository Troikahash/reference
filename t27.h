//
//  Created by c-mnd on 27.12.18.
//  MIT License, see LICENSE

#ifndef t27_h
#define t27_h

#include <stdio.h>
#include "general.h"

// trits are stored as two bits, one inside p, the other inside n, both have the same 'index'
// names 'p' (positive) and 'n' (negative) result from using these functions in a lib for balanced ternary before
// so i just left them here

typedef struct {
    uint32_t p;
    uint32_t n;
} T27;

static T27 t27_new(const uint32_t a, const uint32_t b){
    T27 r;
    r.p = a;
    r.n = b;
    return  r;
}

static int t27_eq(const T27 a, const T27 b){
    if (a.p == b.p && a.n == b.n){
        return 1;
    }
    return 0;
}

static T27 t27_clean(T27 a){
    T27 r;
    r.p = a.p & 0x07ffffff;
    r.n = a.n & 0x07ffffff;
    return r;
}

static T27 t27_sum(const T27* a, const T27* b){
    T27 r;
    r.p = (_1(a) & _0(b)) | (_0(a) & _1(b)) | (_2(a) & _2(b));
    r.n = (_2(a) & _0(b)) | (_0(a) & _2(b)) | (_1(a) & _1(b));
    return r;
}

static T27 t27_roll(T27 a, const int n){
    T27 r;
    r.p = ((a.p << n) | (a.p >> (27-n))) & 0x07ffffff;
    r.n = ((a.n << n) | (a.n >> (27-n))) & 0x07ffffff;
    return r;
}

static uint8_t t27_get(const T27 * a, const int pos){
    const uint32_t mask = 1 << pos;
    if (a->p & mask){
        return 1;
    } else if (a->n & mask){
        return 2;
    }
    return 0;
}

static void t27_set(T27 * a, const int pos, const uint8_t val){
    if (val > 2)
        return;
    const uint32_t mask = 1 <<pos;
    const uint32_t unmask = ~mask;
    a->p = a->p & unmask;
    a->n = a->n & unmask;
    if (val == 1){
        a->p |= mask;
    } else if (val == 2){
        a->n |= mask;
    } else {
        return;
    }
}

#endif /* t27_h */
