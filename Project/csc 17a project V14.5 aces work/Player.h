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
    Hands hnd;
    string nm;
    int mny;
    int vl;
    bool ace;
    
public:
    Player(string, int);
    Player(string);
    void setHand(unsigned char );
    string getNm();
    int getMny();
    void LoGMny(int);
    void dsply();
    void dsply(char);
    int getVal();
    
};


#endif /* PLAYER_H */

