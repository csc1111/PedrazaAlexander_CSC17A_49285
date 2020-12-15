/* 
 * File:   Hands.h
 * Author: Alexander Pedraza
 * Purpose: Header file for class Hands
 * Created on December 14, 2020, 7:44 PM
 */

#ifndef HANDS_H
#define HANDS_H

#include "CardDeck.h"

class Hands
{
    protected:
        unsigned char ncrd; //number of cards in hand
        unsigned char val;  //value of cards in hand
        Card* h[11];        //Card in hand
        bool ace;           //tells if there's an ace
        bool ac;            //tells if an ace has already changed the value
        bool hA;            //tells if the dealer's showing an ace
    public:
        Hands();
        ~Hands();
        void Deal(unsigned char );
        void dsply(string);
        void dsply(string, char);
        void setNCRD(int);
        unsigned char getV();
        bool getF();
        void ifA();
        bool getA();
        unsigned char getCNum();
            
};

#endif /* HANDS_H */

