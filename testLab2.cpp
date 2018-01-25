//
//  testLab2.cpp
//  SafeDataCPP
//
//  Created by TONY on 06/10/2017.
//  Copyright © 2017 TONY COMPANY. All rights reserved.
//

#include "testLab2.hpp"

void testLab2 () {
    
    //MARK: P G M INIT
    long long p;
    long long g;
    getGP(&p, &g);
    long long m = 11111;
    
    //MARK: SHAMIR TEST
    long long SHAMIRcA, SHAMIRdA, SHAMIRcB, SHAMIRdB;
    
    findForCipherShamira(&SHAMIRcA, &SHAMIRdA, p);
    findForCipherShamira(&SHAMIRcB, &SHAMIRdB, p);
    
    long long fShimir = cipherShamira(m, SHAMIRcA, SHAMIRcB, SHAMIRdA, SHAMIRdB, p);
    printf("test cipher shamira %s\n", fShimir ? "TRUE" : "FALSE");
    
    //MARK: FILE TEST
    
    FILE *testInFile = fopen("/Users/Tony/Documents/SafeData/SafeDataCPP/SafeDataCPP/testIn.txt", "rb");
    FILE *testOutFile = fopen("/Users/Tony/Documents/SafeData/SafeDataCPP/SafeDataCPP/testOut.txt", "wb");
    
    if (testInFile == NULL && testOutFile == NULL) {
        fputs("Ошибка файла\n", stderr);
        exit(1);
    }
    
    fseek(testInFile , 0 , SEEK_END);
    long lSize = ftell(testInFile);
    rewind (testInFile);
    
    int sizeOfLong = 2;
    long n = lSize / sizeOfLong;
    int lastSize = lSize % sizeOfLong;
    
    for (long i = 0; i < n; i++) {
        long long *numFile = (long long*) malloc (sizeof(long long) * sizeOfLong);
        long long *numDeFile = (long long*) malloc (sizeof(long long) * sizeOfLong);
        
        fread(numFile, 1, sizeOfLong, testInFile);
        
        //MARK: Al-GAMAL FILE TEST
        //  rand in getLargeNum 20000 - 30000
        //  sizeOfLong   2
        /*
        long long r, e, dB, cB;
        cB = getRand(1, p - 1);
        dB = powFast(g, cB, p);
        cipherAlGamal(*numFile, p, g, &r, &e, dB);
        *numDeFile = decipherAlGamal(e, r, p, cB);
        */
        
        //MARK: RSA FILE TEST
        //  rand in getLargeNum 2000 - 3000
        //  sizeOfLong  1
        /*
        long long q = genLargeNum();
        long long NB =  p * q;
        long long fi = (p - 1) * (q - 1);
        long long e, dB, cB;
        findCD(&cB, &dB, fi);
        e = cipherRSA(*numFile, dB, NB);
        *numDeFile = decipherRSA(e, cB, NB);
        */
        
        //MARK: Vernam FILE TEST
        
        long long e, k = getRand(pow(10, 16), pow(10, 18));
        e = cipherVernam(*numFile, k);
        *numDeFile = decipherVernam(e, k);
        
         
        fwrite(numDeFile, 1, sizeof(numDeFile), testOutFile);
    }
    
    long long *lastNumFile = (long long*) malloc (sizeof(long long) * lastSize);
    long long *lastNumDeFile = (long long*) malloc (sizeof(long long) * lastSize);
    fread(lastNumFile, 1, lastSize, testInFile);
    
    
    //MARK: Al-GAMAL FILE LAST TEST
    /*
    long long r, e, dB, cB;
    cB = getRand(1, p - 1);
    dB = powFast(g, cB, p);
    cipherAlGamal(*lastNumFile, p, g, &r, &e, dB);
    *lastNumFile = decipherAlGamal(e, r, p, cB);
    */
    
    
    //MARK: RSA FILE LAST TEST
    /*
    long long q = genLargeNum();
    long long NB =  p * q;
    long long fi = (p - 1) * (q - 1);
    long long e, dB, cB;
    findCD(&cB, &dB, fi);
    e = cipherRSA(*lastNumFile, dB, NB);
    *lastNumDeFile = decipherRSA(e, cB, NB);
    */
    
    //MARK: Vernam FILE LAST TEST
    
    long long e, Vk = getRand(pow(10, 16), pow(10, 18));
    e = cipherVernam(*lastNumFile, Vk);
    *lastNumDeFile = decipherVernam(e, Vk);
    
    
    fwrite(lastNumDeFile, 1, sizeof(lastNumDeFile), testOutFile);
     
    fclose(testInFile);
    fclose(testOutFile);
}
