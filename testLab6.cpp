//
//  testLab6.cpp
//  SafeDataCPP
//
//  Created by TONY on 19/11/2017.
//  Copyright © 2017 TONY COMPANY. All rights reserved.
//
#include "testLab6.hpp"

void testLab6 () {
    FILE *test = fopen("/Users/Tony/Documents/SafeData/SafeDataCPP/SafeDataCPP/testIn.txt", "rb");
    
    if (test == NULL) {
        fputs("Ошибка файла\n", stderr);
        exit(1);
    }
    
    int tops, lines;
    int a, b;
    long long p, q, fi, c, d, N;
    long long G[MIL][MIL], H1[MIL][MIL], H2[MIL][MIL], F[MIL][MIL], r[MIL][MIL];
    
    
    for (int i = 0; i < MIL; i++) {
        for (int j = 0; j < MIL; j++) {
            G[i][j] = 0;
            H1[i][j] = 0;
            H2[i][j] = 0;
            F[i][j] = 0;
        }
    }
    
    p = getLargeNum();
    q = getLargeNum();
    N = p * q;
    fi = (p - 1) * (q - 1);
    d = coprime(fi);
    c = inverse(fi, d);
     
    fscanf(test, "%d %d", &tops, &lines);
    
    int gam[] = {8, 2, 4, 6, 3, 5, 7, 1};
    
    for (int i = 0; i < lines; i++) {
        fscanf(test, "%d %d", &a, &b);
        G[a][b] = 1;
        a = (a + 3) % tops + 1;
        b = (b + 3) % tops + 1;
        H1[a][b] = 1;
    }
    
    for (int i = 0; i <= tops; i++) {
        for (int j = 0; j <= tops; j++) {
            H2[i][j] = H1[i][j] + r[i][j];
            F[i][j] = powFast(H2[i][j], d, N);
        }
    }
    
    //Hamiltonian cycle
    int f1 = 1;
    for (int i = 0; i < tops - 1; i++) {
        a = (gam[i] + 3) % tops + 1;
        b = (gam[i + 1] + 3) % tops + 1;
        if (H1[a][b] == 0) {
            f1 = 0;
            break;
        }
    }
    
    if (f1 == 1) printf("Q1: TRUE\n");
    else printf("Q1: FALSE\n");
    
    
    //G == H
    int f2 = 1;
    for (int i = 1; i <= tops; i++) {
        for (int j = 1; j <= tops; j++) {
            a = (i + 3) % tops + 1;
            b = (j + 3) % tops + 1;
            if (G[a][b] != H1[i][j]) {
                f2 = 0;
                    break;
            }
        }
    }
    
    if (f2 == 1) printf("Q2: TRUE\n");
    else printf("Q2: FALSE\n");
    
    fclose(test);
}
