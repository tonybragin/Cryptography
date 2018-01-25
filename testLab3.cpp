//
//  testLab3.cpp
//  SafeDataCPP
//
//  Created by TONY on 25/10/2017.
//  Copyright © 2017 TONY COMPANY. All rights reserved.
//

#include "testLab3.hpp"

void testLab3() {
    char filename[] = "/Users/Tony/Documents/SafeData/SafeDataCPP/SafeDataCPP/testIn.txt";
    
    //MARK: RSA SING
    long long pRSA = getLargeNum();
    long long q = getLargeNum();
    long long N =  pRSA * q;
    long long fi = (pRSA - 1) * (q - 1);
    long long c, d;
    
    findCD(&c, &d, fi);
    long long yRSA = h(filename) % pRSA;
    long long sRSA = singRSA(yRSA, c, N);
    
    bool fRSA = checkSingRSA(yRSA, sRSA, d, N);
    
    printf("RSA SING: %llu %s\n", sRSA, fRSA ? "TRUE" : "FALSE");
    
    
    //MARK: Эль-Гамаль SING
    long long pAl, gAl;
    unsigned long long z, w, u;
    unsigned long long hAl, k, r, sAl;
    
    getGP(&pAl, &gAl);
    generateKeysForAlGamal(&z, &w, pAl, gAl);
    
    hAl = h(filename) % pAl;
    k = coprime(pAl - 1);
    r = powFast(gAl, k, pAl);
    u = (hAl - z*r) % (pAl - 1);
    
    sAl = (inverse(pAl - 1, k) * u) % (pAl - 1);
    
    int fAl = checkSingAlGamal(w, r, sAl, gAl, hAl, pAl);
    
    printf("Al-Gamal SING: %lli %s\n", sAl, fAl ? "TRUE" : "FALSE");
    
}
