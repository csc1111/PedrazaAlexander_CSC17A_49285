

/* 
 * File:   CardDeck.h
 * Author: Alexander Pedraza
 * Purpose: Header file for class Card
 * Created on December 14, 2020, 11:38 PM
 */

#ifndef CARDDECK_H
#define CARDDECK_H

#include <iostream>
using namespace std; 

class Card
{
private:
    unsigned char cNum;     //index of what card it is
public:
    Card(unsigned char n);
    unsigned char Face();
    unsigned char Suit();
    unsigned char Val();
    unsigned char gtCNum();
};

#endif /* CARDDECK_H */

