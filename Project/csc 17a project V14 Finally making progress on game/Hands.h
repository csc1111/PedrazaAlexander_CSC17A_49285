/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hands.h
 * Author: alexf
 *
 * Created on December 12, 2020, 4:48 PM
 */

#ifndef HANDS_H
#define HANDS_H

#include "CardDeck.h"

class Hands
{
    protected:
        unsigned char ncrd;
        unsigned char val;
        unsigned char ind[11];
        Card* h[11];
    public:
        Hands();
        ~Hands();
        void Deal(unsigned char );
        void dsply(string);
        void dsply(string, char);
        void setNCRD(int);
        unsigned char getV();
            
};

#endif /* HANDS_H */

