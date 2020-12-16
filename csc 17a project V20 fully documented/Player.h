/* 
 * File:   Player.h
 * Author: Alexander Pedraza
 * Purpose: Header file for class Player
 * Created on December 14, 2020, 7:44 PM
 */
 

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;
#include "AbstractC.h"

class Player : public AbstractC //derived from AbstractC
{
protected:
    Hands hnd;      //players hand
    string nm;      //players name
    int mny;        //players money
    
public:
    Player(string, int);
    Player(string);
    Player();
    Player(const Player&);
    void setHand(unsigned char );
    string getNm();
    int getMny();
    void setMny(int);
    void dsply();
    void dsply(char);
    int getVal();
    bool getHA();
    bool splt();
    unsigned char spltC();
    friend void LoGMny(Player &, int);
};


#endif /* PLAYER_H */

