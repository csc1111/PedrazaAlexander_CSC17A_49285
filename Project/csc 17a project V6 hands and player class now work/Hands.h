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
    private:
        unsigned char ncrd;
        Card *cr[11];
    public:
        Hands();
        ~Hands();
        void Deal(Card *y);
        void dsply();
            
};

#endif /* HANDS_H */

