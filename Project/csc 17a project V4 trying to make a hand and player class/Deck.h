/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Deck.h
 * Author: alexf
 *
 * Created on December 11, 2020, 6:07 PM
 */

#ifndef DECK_H
#define DECK_H

#include "CardDeck.h"

class Deck
{
private:
    unsigned char crds;
    unsigned char shf;
    unsigned char dlt;
    Card **dk;
    
public:
    Deck();
    ~Deck();
    void shfl();
    Card *deal();
    void dsply();
    unsigned char gtDlt();
    
    
};


#endif /* DECK_H */

