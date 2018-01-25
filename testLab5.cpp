//
//  testLab5.cpp
//  SafeDataCPP
//
//  Created by TONY on 19/11/2017.
//  Copyright © 2017 TONY COMPANY. All rights reserved.
//
#include "testLab5.hpp"

void testLab5 () {
    int shopWallet = 0, buyerWallet = 10000;
    long long p, q, N, fi;
    long long c[100], d[100], n[100], ns[100], s[100], ss[100], denom[100];
    
    long long staffToBuy = getRand(10, 10000);
    
    printf("shop wallet %d, buyer wallet %d price %lld\n\n", shopWallet, buyerWallet, staffToBuy);
    
    long long denomination[] = {5000, 2000, 1000, 500, 200, 100, 50, 10};
    int jr = 0, nr = 0;
    
    while (staffToBuy > 0) {
        if (staffToBuy - denomination[jr] > 0) {
            denom[nr] = denomination[jr];
            staffToBuy -= denomination[jr];
            nr++;
        } else {
            if (jr + 1 < 11) jr++;
            if (staffToBuy < 10) {
                denom[nr++] = staffToBuy;
                break;
            }
        }
    }
    
    p = getLargeNum();
    q = getLargeNum();
    N = p * q;
    fi = (p - 1) * (q - 1);
    
    int pay = 0;
    for (int i = 0; i < nr; i++) {
        d[i] = coprime(fi);
        c[i] = inverse(fi, d[i]);
        n[i] = getRand(2, N - 1);
        
        long long r = coprime(N);
        long long r1 = inverse(N, r);
        
        ns[i] = (func(n[i], N) * (powFast(r, d[i], N))) % N;
        
        ss[i] = powFast(ns[i], c[i], N);
        
        buyerWallet -= denom[i];
        pay += denom[i];
        
        s[i] = (ss[i] * r1) % N;
        
        printf("banknote: denomination %lld number %lld\n", denom[i], s[i]);
        
        int f = checkBanknote(s[i], d[i], N, n[i]);
        
        for (int j = 0; j < i; j++) {
            if (n[j] == n[i]) {
                f = 0;
                printf("\ngot this banknote\n");
                break;
            }
        }
        
        printf("check banknote: %s\n", f ? "TRUE\n" : "FALSE\n");
    
        if (f == 1) shopWallet += denom[i];
        else {
            buyerWallet += pay;
            shopWallet -= pay;
        }
    }
    
    printf("shop wallet %d, buyer wallet %d\n", shopWallet, buyerWallet);
}
