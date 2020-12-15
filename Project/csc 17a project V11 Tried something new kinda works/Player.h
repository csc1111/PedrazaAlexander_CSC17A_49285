/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: alexf
 *
 * Created on December 12, 2020, 4:45 PM
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;
#include "AbstractC.h"

class Player : public AbstractC
{
protected:
    Hands *hnd;
    unsigned char *h;
    string nm;
    int mny;
    int vl;
    bool ace;
    
public:
    Player(string, int);
    void setHand(unsigned char *);
    void LoGMny(int);
    string getNm();
    int getMny();
    //int getVal();
    
};


#endif /* PLAYER_H */

