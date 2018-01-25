//
//  testLab1.cpp
//  SafeDataCPP
//
//  Created by TONY on 07/10/2017.
//  Copyright © 2017 TONY COMPANY. All rights reserved.
//
#include "testLab1.hpp"


void testLab1 () {
    
    long long p;
    long long g;
    
    long long a = getRand(pow(10, 16), pow(10, 18));
    long long b = getRand(pow(10, 16), pow(10, 18));
    
    getGP(&p, &g);
    printf("p & g %lld %lld\n", p, g);
    
    int fDF = algDifHell(a, b, g, p);
    
    printf("test dif-hell %s\n", fDF ? "TRUE" : "FALSE");
    
    long long  fBG = babyStepGiantStep(2, 512, 100);
    printf("baby step check %lld\n\n", fBG);

    
}
