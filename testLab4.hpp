//
//  testLab4.hpp
//  SafeDataCPP
//
//  Created by TONY on 27/10/2017.
//  Copyright © 2017 TONY COMPANY. All rights reserved.
//

#ifndef testLab4_hpp
#define testLab4_hpp

#include "lab1.hpp"

struct allGamers {
    
    long long card1Cipher, card1Code, card2Cipher, card2Code;
    long long card1Number, card1Suit, card2Number, card2Suit;
    int result;
};

char *getCardNumber (int fromNum);
char *getCardSuit (int fromNum);
char *getResult(int fromCombsCode);
int whatCombs (long long fromCardsNumber[], long long fromCardsSuit[], int size);
void testLab4 ();

#endif /* testLab4_hpp */
