//
//  lab3.cpp
//  SafeDataCPP
//
//  Created by TONY on 25/10/2017.
//  Copyright © 2017 TONY COMPANY. All rights reserved.
//
#include "lab3.hpp"

//MARK: Hash-function
long long h (char *filename) {
    char ch;
    unsigned long long res = 0, flen = 0, p = 1;
    
    FILE *fp;
    fp = fopen(filename, "r");
    
    if (!fp) {
        puts("File doesn't exist.\n");
        return -1;
    }
    
    fseek(fp, 0, SEEK_END);
    flen = ftell(fp);
    rewind(fp);
    
    for (unsigned long long i = 0; i < flen; ++i, p *= MAGIC) {
        ch = fgetc(fp);
        res += ((int) ch * p) % ULONG_MAX;
    }
    
    fclose(fp);
    
    return res;
}


//MARK: RSA
long long singRSA (long long y, long long c, long long N) {
    return powFast(y, c, N);
}

bool checkSingRSA (long long y, long long s, long long d, long long N) {
    long long w = powFast(s, d, N);
    
    return w == y;
}

//MARK: Эль-Гамаль
void generateKeysForAlGamal (unsigned long long *c, unsigned long long *d, long long p, long long g) {
    *c = getRand(2, p - 2);
    *d = powFastUnsigned(g, *c, p);
}

long long getKForAlGamal (long long k, long long p) {
    
    long long k1;
    
    do {
        k1 = getRand(1, p - 1);
    } while ((k1*k) % (p - 1) == 1);
    
    return k1;
}

bool checkSingAlGamal (long long w, long long r, long long s, long long g, unsigned long long h, long long p) {
    long long fa, fb, f;
    
    fa = powFastUnsigned(w, r, p);
    fb = powFastUnsigned(r, s, p);
    
    f = powFastUnsigned(g, h, p);
    
    return ((fa * fb) % p) == f;
}
