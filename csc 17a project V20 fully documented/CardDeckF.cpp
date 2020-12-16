/* 
 * File:   CardDeckF.cpp
 * Author: Alexander Pedraza
 * Purpose: source file for class Card
 * Created on December 14, 2020, 7:44 PM
 */

#include "CardDeck.h"


/****************************************************************************
 *  Card constructor(unsigned char)
 *      sets cNum to the number in function call
 ****************************************************************************/
Card::Card(unsigned char n)
{
    cNum=n;
    //cout << "Card C";
}

/****************************************************************************
 *  unsigned char Card::Face()
 *      returns the face of the card depending on the cNum
 ****************************************************************************/
unsigned char Card::Face()
{
    char f[]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    unsigned char n=cNum%13;    //cNum%13 makes sure cNum is <14
    return f[n];
}

/****************************************************************************
 *  unsigned char Card::Suit()
 *      returns the Suit of the card depending on the cNum
 ****************************************************************************/
unsigned char Card::Suit()
{
    char s[]={'S','D','C','H'};
    unsigned char n=cNum/13;
    return s[n];
}

/****************************************************************************
 *  unsigned char Card::Val()
 *      returns the value of the card depending on the cNum
 ****************************************************************************/
unsigned char Card::Val()
{
    unsigned char n=cNum%13;
    n++;        //n wont be 0
    if(n>10)    //when n is more than 10 its 10
        n=10;
    
    return n;
}

/****************************************************************************
 *  unsigned char Card::gtCNum()
 *      returns the cNum
 ****************************************************************************/
unsigned char Card::gtCNum()
{
    return cNum;
}

