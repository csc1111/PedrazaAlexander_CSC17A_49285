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

}

Player::Player(string n)
{
    vl=0;
    nm=n;
    mny=0;
    ace=0;

    
}

void Player::setHand(unsigned char d)
{
    hnd.Deal(d);
}

string Player::getNm()
{
    return nm;
}

int Player::getMny()
{
    return mny;
}

void Player::LoGMny(int x)
{
    mny+=x;
}

void Player::dsply()
{
    hnd.dsply(nm);
}

void Player::dsply(char a)
{
    hnd.dsply(nm,a);
}

int Player::getVal()
{
    hnd.getV();
}