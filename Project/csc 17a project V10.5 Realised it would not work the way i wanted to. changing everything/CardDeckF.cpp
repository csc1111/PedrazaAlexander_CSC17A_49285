/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "CardDeck.h"


Card::Card(unsigned char n)
{
    cNum=n;
    cout << "Card C";
}

unsigned char Card::Face()
{
    char f[]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    unsigned char n=cNum%13;
    return f[n];
}

unsigned char Card::Suit()
{
    char s[]={'S','D','C','H'};
    unsigned char n=cNum/13;
    return s[n];
}

unsigned char Card::Val()
{
    unsigned char n=cNum%13;
    n++;
    if(n>10)
        n=10;
    
    return n;
}

unsigned char Card::gtCNum()
{
    return cNum;
}

