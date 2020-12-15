/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dealer.h
 * Author: alexf
 *
 * Created on December 12, 2020, 8:41 PM
 */
/*
#ifndef DEALER_H
#define DEALER_H
#include <iostream>
using namespace std;
#include "AbstractC.h"

class Dealer : public AbstractC
{
protected:
    Hands hnd;
    string nm;
    int vl;
    bool ace;
    
public:
    Dealer(string);
    void setHand(unsigned char );
    string getNm();
    //int getVal();
    
};


#endif /* DEALER_H */

