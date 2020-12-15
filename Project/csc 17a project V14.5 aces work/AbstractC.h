/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AbstractC.h
 * Author: alexf
 *
 * Created on December 13, 2020, 12:27 AM
 */

#ifndef ABSTRACTC_H
#define ABSTRACTC_H

#include <string>
using namespace std;

#include "Hands.h"
#include "CardDeck.h"

class AbstractC
{
    public:
        virtual void setHand(unsigned char )= 0;
        virtual string getNm()= 0;
        virtual int getMny()= 0;
        virtual void LoGMny(int)= 0;        
        virtual void dsply()= 0;
        virtual void dsply(char)= 0;
        virtual int getVal()= 0;

};



#endif /* ABSTRACTC_H */

