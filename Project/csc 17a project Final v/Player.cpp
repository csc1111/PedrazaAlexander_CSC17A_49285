/* 
 * File:   Player.cpp
 * Author: Alexander Pedraza
 * Purpose: source file for class Player
 * Created on December 14, 2020, 7:44 PM
 */

#include "Player.h"
#include <iostream>


/****************************************************************************
 *  Player::Player(string, int)
 *      constructor for player. Sets name to n and money to m
 ****************************************************************************/
Player::Player(string n, int m)
{
    nm=n;
    mny=m;

}
/****************************************************************************
 *  Player::Player(string)
 *      constructor for dealer. Sets name to n and sets money to 0
 ****************************************************************************/
Player::Player(string n)
{
    nm=n;
    mny=0;
}

/****************************************************************************
 *  Player::Player()
 *      default constructor. Meant to be used when splitting. sets name and
 *  money to 0.
 ****************************************************************************/
Player::Player()
{
    nm="0";
    mny=0;
    
}

/****************************************************************************
 *  Player::Player(const Player &)
 *      copy constructor for Player. Could be used when splitting
 ****************************************************************************/
Player::Player(const Player &x)
{
    hnd=x.hnd;
    nm=x.nm;
    mny=x.mny;

}

/****************************************************************************
 *  void Player::setHand(unsigned char)
 *      calls Hands class function Deal() to set hnds card
 ****************************************************************************/
void Player::setHand(unsigned char d)
{
    hnd.Deal(d);
}

/****************************************************************************
 *  string Player::getNm()
 *      returns players name
 ****************************************************************************/
string Player::getNm()
{
    return nm;
}

/****************************************************************************
 *  void Player::setMny(int)
 *      mny is incremented by x
 ****************************************************************************/
void Player::setMny(int x)
{
    mny+=x;
}

/****************************************************************************
 *  int Player::getMny()
 *      returns the players money
 ****************************************************************************/
int Player::getMny()
{
    return mny;
}

/****************************************************************************
 *  void Player::dsply()
 *      calls hands function hnd.dsply(nm). It displays the players hand
 ****************************************************************************/
void Player::dsply()
{
    hnd.dsply(nm);
}

/****************************************************************************
 *  void Player::dsply(char)
 *      calls hands function hnd.dsply(nm,a). It displays the dealers hand
 *  with a hidden card
 ****************************************************************************/
void Player::dsply(char a)
{
    hnd.dsply(nm,a);
}

/****************************************************************************
 *  int Player::getVal()
 *      returns teh calue of the players hand
 ****************************************************************************/
int Player::getVal()
{
    return hnd.getV();
}

/****************************************************************************
 *  bool Player::getHA()
 *      returns hnd.getA(). tells if the dealer has a visible ace
 ****************************************************************************/
bool Player::getHA()
{
    return hnd.getA();
}

/****************************************************************************
 *  bool Player::splt()
 *      returns hnd.getF(). Tells whether the player's hand is elligible of being
 *  split.
 ****************************************************************************/
bool Player::splt()
{
    return hnd.getF();
}

/****************************************************************************
 *  unsigned char Player::spltC()
 *      returns hnd.getCNum(); if the player decides to split the card is taken
 *  from original hand and placed in new
 ****************************************************************************/
unsigned char Player::spltC()
{
    return hnd.getCNum();
}