//
//  general.h
//  troika-test
//
//  Created by he on 27.12.18.
//  Copyright © 2018 he. All rights reserved.
//

#ifndef general_h
#define general_h

#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>


#define PRINT(x) printf("%s",#x)
#define STR_EXPAND(tok) #tok
#define STR(tok) STR_EXPAND(tok)

#define COLUMNS 9
#define ROWS 3
#define SLICES 27
#define SLICESIZE (COLUMNS*ROWS)
#define STATESIZE (COLUMNS*ROWS*SLICES)
#define NUM_SBOXES (SLICES*ROWS*COLUMNS/3)

#define NUM_ROUNDS 24
#define TROIKA_RATE 243

#define PADDING 0x1

#define _1(a) (a->p)
#define _2(a) (a->n)
#define _0(a) (~a->p & ~a->n)

#endif /* general_h */
