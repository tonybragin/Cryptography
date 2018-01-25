//
//  lab2.cpp
//  SafeDataCPP
//
//  Created by TONY on 29/09/2017.
//  Copyright © 2017 TONY COMPANY. All rights reserved.
//
#include "lab1.hpp"
#include "lab2.hpp"

void findCD (long long *c, long long *d, long long withP) {
    *c = coprime(withP);
    *d = inverse(withP, *c);
}

//MARK:   Шифр Шамира
void findForCipherShamira (long long *c, long long *d, long long withP) {
    
    while (1) {
        *c = getRand(2, 1000);
        *d = getRand(2, 1000);
        if (((*c) * (*d)) % (withP - 1) == 1) {
            break;
        }
    }
}

long long cipherShamira (long long m, long long ca, long long cb,
                          long long da, long long db, long long p) {
    long long x1, x2, x3, x4;
    
    x1 = powFast(m, ca, p);
    x2 = powFast(x1, cb, p);
    x3 = powFast(x2, da, p);
    x4 = powFast(x3, db, p);
    
    return m == x4;
}


//MARK:    Шифр Эль-Гамаля
void cipherAlGamal (long long m, long long p, long long g, long long *r, long long *e, long long db) {
    
    long long k = getRand(0, p - 2);
    *r = powFast(g, k, p);
    *e = (powFast(db, k, p) * m) % p;
}

long long decipherAlGamal (long long e, long long r, long long p, long long cb) {
    return (powFast(r, p - 1 - cb, p) * e) % p;
}


//MARK:    Шифр Вернама
long long cipherVernam (long long m, long long k) {
    return m ^ k;
}

long long decipherVernam (long long e, long long k) {
    return e ^ k;
}


//MARK:    Шифр RSA
long long cipherRSA (long long m, long long db, long long Nb) {
    return powFast(m, db, Nb);
}

long long decipherRSA (long long e, long long cb, long long Nb) {
    return powFast(e, cb, Nb);
}
