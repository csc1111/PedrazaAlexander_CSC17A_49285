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

int Player::getVal()
{
    for(int x=0; x<ncrd;++x)
    {
        vl+=cr[x]->Val();
    }
    return vl;
}