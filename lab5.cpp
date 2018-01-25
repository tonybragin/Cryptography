//
//  lab5.cpp
//  SafeDataCPP
//
//  Created by TONY on 19/11/2017.
//  Copyright © 2017 TONY COMPANY. All rights reserved.
//
#include "lab5.hpp"

long long func(long long n, long long N) {
    return powFast(n, N % n, N);
}

bool checkBanknote(long long s, long long d, long long N, long long n) {
    return powFast(s, d, N) == func(n, N);
}
