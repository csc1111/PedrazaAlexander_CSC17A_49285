/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Player.h"
#include <iostream>

Player::Player(string n, int m)
{
    vl=0;
    nm=n;
    mny=m;
    ace=0;
    cout << "Plyr made";
}

void Player::setHand(Card *d)
{
    hnd->Deal(d);
    cout << "set hnd";
}

void Player::LoGMny(int x)
{
    mny+=x;
}

string Player::getNm()
{
    return nm;
}

int Player::getMny()
{
    return mny;
}

/*int Player::getVal()
{
    vl=0;
    int tval;    
    for(int x=0;x<ncrd;++x)
    {
        vl+=cr[x]->Val();
        if(cr[x]->Val()==1)
            ace=1;
    }
    tval=vl;
    if(tval+11<=21&&ace)
    {
        tval+=11;
    }
    
    return tval;
}*/