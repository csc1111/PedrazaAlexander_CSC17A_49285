/* 
 * File:   AbstractC.h
 * Author: Alexander Pedraza
 * Purpose: Abstract Base class used by Player
 * Created on December 14, 2020, 7:44 PM
 */
#ifndef ABSTRACTC_H
#define ABSTRACTC_H

#include <string>
using namespace std;

#include "Hands.h"
#include "CardDeck.h"
//Abstract Class
class AbstractC
{
    public:

        virtual void setHand(unsigned char )= 0;
        virtual string getNm()= 0;
        virtual int getMny()= 0;  
        virtual void setMny(int)=0;
        virtual void dsply()= 0;
        virtual void dsply(char)= 0;
        virtual int getVal()= 0;
        virtual bool getHA()=0;
        virtual bool splt()=0;
        virtual unsigned char spltC()=0;

};

#endif /* ABSTRACTC_H */

