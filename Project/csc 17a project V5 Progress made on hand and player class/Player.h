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
#include "Hands.h"

class Player : public Hands
{
private:
    string nm;
    int mny;
    
public:
    Player(string, int);
    void LoGMny(int);
    string getNm();
    int getMny();
    
};


#endif /* PLAYER_H */

