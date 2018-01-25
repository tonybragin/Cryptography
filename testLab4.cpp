//
//  testLab4.cpp
//  SafeDataCPP
//
//  Created by TONY on 27/10/2017.
//  Copyright © 2017 TONY COMPANY. All rights reserved.
//
#include "testLab4.hpp"

//0 - Spades, 1 - Clubs, 2 - Hearts, 3 - Diamonds

//11 - Jack, 12 - Queen, 13 - King, 14 - Ace

//0 - high card, 1 - one pair, 2 - two pairs, 3 - set, 4 - straight, 5 - flush
//6 - full house, 7 - quads, 8 - straight flush, 9 - royal flush

char *getCardNumber (long long fromNum) {
    switch (fromNum) {
        case 11:
            return "Jack";
            break;
        case 12:
            return "Queen";
            break;
        case 13:
            return "King";
            break;
        case 14:
            return "Ace";
            break;
            
        default: {
            char *str = new char[2];
            sprintf(str, "%lld", fromNum);
            return str;
            break;
        }
    }
}

char *getCardSuit (long long fromNum) {
    switch (fromNum) {
        case 0:
            return "Spades";
            break;
        case 1:
            return "Clubs";
            break;
        case 2:
            return "Hearts";
            break;
        case 3:
            return "Diamonds";
            break;
            
        default:
            return NULL;
            break;
    }
}

char *getResult(int fromCombsCode) {
    switch (fromCombsCode) {
        case 1:
            return "one pair";
            break;
        case 2:
            return "two pairs";
            break;
        case 3:
            return "set";
            break;
        case 4:
            return "straight";
            break;
        case 5:
            return "flush";
            break;
        case 6:
            return "full house";
            break;
        case 7:
            return "quads";
            break;
        case 8:
            return "straight flush";
            break;
        case 9:
            return "royal flush";
            break;
            
        default:
            return "may be high card";
            break;
    }
}

int whatCombs (long long fromCardsNumber[], long long fromCardsSuit[], int size) {
    int numOfSuits[4] = {0};
    int numOfNums[15] = {0};
    
    for (int i = 0; i < size; i++) {
        numOfSuits[fromCardsSuit[i]] += 1;
        numOfNums[fromCardsNumber[i]] += 1;
    }
    
    //check for
    //royal flush, straight flush, flush
    //
    for (int i = 0; i < 4; i++) {
        if (numOfSuits[i] >= 5) {
            //check for royal flush
            int fRoyal = 1;
            for (int j = 14; j > 9; j--) {
                if (numOfNums[j] == 0) {
                    fRoyal = 0;
                    break;
                }
            }
            if (fRoyal == 1) return 9;
            
            //check for straight flush
            int fStraight = 0;
            for (int j = 14; j > 1; j--) {
                if (numOfNums[j] > 0) {
                    fStraight++;
                }
                else if (fStraight == 5) {
                    return 8;
                }
                else fStraight = 0;
            }
            
            //it's flush!
            return 5;
        }
    }
    
    //check for straight
    int fStraight = 0;
    if (numOfNums[2] > 0) {
        if (numOfNums[14] > 0) fStraight = 2;
        else fStraight = 1;
    }
    for (int i = 3; i < 15; i++) {
        if (numOfNums[i] > 0) fStraight++;
        else if (fStraight == 5) return 4;
        else fStraight = 0;
    }
    
    //
    //check for pairs and sets
    //
    int pair = 0;
    int set = 0;
    for (int i = 0; i < 15; i++) {
        //check for quads
        if (numOfNums[i] == 4) return 7;
        
        if (numOfNums[i] == 3) set++;
        if (numOfNums[i] == 2) pair++;
    }
    
    //chech for full house and set
    if (set > 0) {
        if (pair > 0) return 6;
        else return 3;
    }
    
    //check for pairs
    if (pair == 2) return 2;
    if (pair == 1) return 1;
    
    return 0;
}

void testLab4 () {
    
    int gamersNumber = 3;
    int n = gamersNumber * 2 + 5;
    long long p = getLargeNum();
    
    long long cardsCipher[n];
    long long cardsCode[n];
    long long cardsNumber[n];
    long long cardsSuit[n];
    
    
    allGamers *gamer[gamersNumber];

    //choose cards for game
    for (int i = 0; i < n; i++) {
        cardsCode[i] = getRand(1, p - 1);
        cardsNumber[i] = getRand(1, 14);
        cardsCipher[i] = cardsNumber[i] ^ cardsCode[i];
        cardsSuit[i] = getRand(0, 4);
    }
    
    //give 2 cards to gamers
    for (int i = 0; i < gamersNumber; i++) {
        gamer[i] = new allGamers;
        
        while (1) {
            long long r = getRand(0, n);
            if (cardsCipher[r] != 0) {
                gamer[i]->card1Cipher = cardsCipher[r];
                gamer[i]->card1Code = cardsCode[r];
                cardsCipher[r] = 0;
                break;
            }
        }
        
        while (1) {
            long long r = getRand(0, n);
            if (cardsCipher[r] != 0) {
                gamer[i]->card2Cipher = cardsCipher[r];
                gamer[i]->card2Code = cardsCode[r];
                cardsCipher[r] = 0;
                break;
            }
        }
    }
    
    //gamers look at cards
    for (int i = 0; i < gamersNumber; i++) {
        gamer[i]->card1Number =  gamer[i]->card1Cipher ^ gamer[i]->card1Code;
        gamer[i]->card2Number =  gamer[i]->card2Cipher ^ gamer[i]->card2Code;
        
        for (int j = 0; j < n; j++) {
            if (cardsCode[j] == gamer[i]->card1Code) {
                gamer[i]->card1Suit = cardsSuit[j];
            }
            if (cardsCode[j] == gamer[i]->card2Code) {
                gamer[i]->card2Suit = cardsSuit[j];
            }
        }
    }
    
    long long funcCardsNumber[7];
    long long funcCardsSuit[7];
    int z = 0;
    
    //show board cards
    cout << "Cards on the board: ";
    for (int i = 0; i < n; i++) {
        if (cardsCipher[i] != 0) {
            funcCardsNumber[z] = cardsNumber[i];
            funcCardsSuit[z] = cardsSuit[i];
            z++;
            
            cout << getCardNumber(cardsNumber[i]) << getCardSuit(cardsSuit[i]) << " ";
        }
    }
    cout << "\n\n";
    
    //gamers look what they got
    for (int i = 0; i < gamersNumber; i++) {
        funcCardsNumber[z] = gamer[i]->card1Number;
        funcCardsSuit[z] = gamer[i]->card1Suit;
        funcCardsNumber[z + 1] = gamer[i]->card2Number;
        funcCardsSuit[z + 1] = gamer[i]->card2Suit;
        
        gamer[i]->result = whatCombs(funcCardsNumber, funcCardsSuit, 7);
    }

    //show up
    for (int i = 0; i < gamersNumber; i++) {
        cout << "Gamer N" << i << ".\nHis cards: "
            << getCardNumber(gamer[i]->card1Number)
            << getCardSuit(gamer[i]->card1Suit) << " "
            << getCardNumber(gamer[i]->card2Number)
            << getCardSuit(gamer[i]->card2Suit) << "\nHis result: "
            << getResult(gamer[i]->result) << "\n\n";
    }
    
    //who's win
    int maxResult = 0, winner = gamersNumber;
    for (int i = 0; i < gamersNumber; i++) {
        if (gamer[i]->result > maxResult) {
            maxResult = gamer[i]->result;
            winner = i;
        }
    }
    
    cout << "Winner is Gamer N" << winner << endl;
    
}
