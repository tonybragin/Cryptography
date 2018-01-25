//
//  lab2.hpp
//  SafeDataCPP
//
//  Created by TONY on 29/09/2017.
//  Copyright © 2017 TONY COMPANY. All rights reserved.
//

#ifndef lab1_hpp
#define lab1_hpp

#include <stdio.h>
#include <iostream>
#include <map>
#include <math.h>
#include <time.h>

using namespace std;

long long getRand (long long min, long long max);
bool isPrime(long long n);
long long getLargeNum ();
void getGP (long long *p, long long *g);

long long powFast (long long x, long long a, long long n);
unsigned long long powFastUnsigned (unsigned long long x, unsigned long long a, unsigned long long n);
long long coprime(long long withP);
unsigned long long inverse (unsigned long long withP, unsigned long long c);

void algEvk (unsigned long long a, unsigned long long b, long long *x, long long *y, long long *d);
bool algDifHell (long long a, long long b, long long g, long long p);
long long babyStepGiantStep (long long g, long long h, long long n);

#endif /* lab1_hpp */
