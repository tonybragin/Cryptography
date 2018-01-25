//
//  lab3.hpp
//  SafeDataCPP
//
//  Created by TONY on 25/10/2017.
//  Copyright © 2017 TONY COMPANY. All rights reserved.
//

#ifndef lab3_hpp
#define lab3_hpp

#include <limits.h>
#include <unistd.h>

#include "lab1.hpp"
#include "lab2.hpp"

#define MAGIC 3733

long long h (char *filename);

long long singRSA (long long y, long long c, long long N);
bool checkSingRSA (long long y, long long s, long long d, long long N);

void generateKeysForAlGamal (unsigned long long *c, unsigned long long *d, long long p, long long g);
long long getKForAlGamal (long long k, long long p);
void singAlGamal (long long p, long long g, long long h, long long k);
bool checkSingAlGamal (long long w, long long r, long long s, long long g, unsigned long long h, long long p);

#endif /* lab3_hpp */
