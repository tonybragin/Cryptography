//
//  lab2.hpp
//  SafeDataCPP
//
//  Created by TONY on 29/09/2017.
//  Copyright © 2017 TONY COMPANY. All rights reserved.
//

#ifndef lab2_hpp
#define lab2_hpp

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void findCD (long long *c, long long *d, long long withP);

void findForCipherShamira (long long *c, long long *d, long long withP);
long long cipherShamira (long long m, long long ca, long long cb,
                          long long da, long long db, long long p);

void cipherAlGamal (long long m, long long p, long long g, long long *r, long long *e, long long db);
long long decipherAlGamal (long long e, long long r, long long p, long long cb);

long long cipherVernam (long long m, long long k);
long long decipherVernam (long long e, long long k);

long long cipherRSA (long long m, long long db, long long Nb);
long long decipherRSA (long long e, long long cb, long long Nb);

#endif /* lab2_hpp */
