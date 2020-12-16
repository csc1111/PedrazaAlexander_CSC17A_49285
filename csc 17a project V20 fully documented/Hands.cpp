/* 
 * File:   Hands.cpp
 * Author: Alexander Pedraza
 * Purpose: Hands Source File
 * Created on December 14, 2020, 7:44 PM
 */

#include "Hands.h"

#include <iostream>
#include <iomanip>

/****************************************************************************
 *  Hands::Hands()
 *      Hands constructor. Sets value, ncrd, ace, and hA to 0
 ****************************************************************************/
Hands::Hands()
{
    val=0;
    ncrd=0;  
    ace=0;
    hA=0;
}

/****************************************************************************
 *  Hands::~Hands()
 *      destructor for hands. Deletes created cards.
 ****************************************************************************/
Hands::~Hands()
{
    for(unsigned char i=0;i<ncrd;++i)
        delete h[i];
}

/****************************************************************************
 *  void Hands::dsply(string)
 *      Displays a players hand 
 ****************************************************************************/
void Hands::dsply(string z)
{
    cout << z << "'s deck\n";

    int y=0;
    for(int i=0;i<ncrd;++i)
        cout << "_______";
    cout << static_cast<int>(getV()) << endl;
    
    while(y<ncrd)
    {
        cout << "|" << h[y]->Suit();
        cout << setw(5) << "|";
        y++;
    }
    cout << endl;
    y=0;
    
    while(y<ncrd)
    {
        cout << "|  " << h[y]->Face();
        cout << setw(3) << "|";
        y++;
    }
    cout << endl;
    
    for(int i=0;i<ncrd;++i)
        cout << "_______";
    cout << endl;
}

/****************************************************************************
 *  void Hands::dsply(string, char)
 *      Displays dealers hand. Does not show second card. If the visible card
 *  is an ace hA=1;
 ****************************************************************************/
void Hands::dsply(string z, char x)
{

    cout << z << "'s deck\n";
    for(int i=0;i<ncrd;++i)
        cout << "_______";
    cout << endl;
    
    cout << "|" << h[0]->Suit();
    cout << setw(5) << "|";
    cout << "|" << setw(5) << "|";

    
    cout << endl;


    cout << "|  " << h[0]->Face();
    cout << setw(3) << "|";
    cout << "|" << setw(5) << "|";

    cout << endl;
    
    for(int i=0;i<ncrd;++i)
        cout << "_______";
    cout << endl;
    if(h[0]->Face()=='A')
    {
        hA=1;
    }
}

/****************************************************************************
 *  void Hands::Deal(unsigned char)
 *      Deals a hand to h[]. If there is an ace, ace=1; Value is incremented
 *  by h[ncrd] and ncrd is incremented by 1
 ****************************************************************************/
void Hands::Deal(unsigned char y)
{
    
    h[ncrd]=new Card(y);
    if(h[ncrd]->Face()=='A')
        ace=1;
    val+=h[ncrd]->Val();
    ++ncrd;
}

/****************************************************************************
 *  void Hands::setNCRD(int)
 *      sets number of cards dealt
 ****************************************************************************/
void Hands::setNCRD(int x)
{
    ncrd=x;
}

/****************************************************************************
 *  unsigned char Hands::getV()
 *      If value is less than or = to 11 and there is an ace, val+=10 and ac=1.
 *  If val is more than 21 and there is an ace and ac is 1 the value is val-=10
 * and ac=0. returns value. 
 *      
 ****************************************************************************/
unsigned char Hands::getV()
{

    if(val<=11&&ace)
    {
        val+=10;
        ac=1;           //if an ace is being used as 11 ac is 1
    }
    else if(val>21&&ace&&ac)    //if ac is 0 then no ace is being used as 11
    {                           //therefore can subtract 10
        val-=10;
        ac=0;           
    }
    return val;
}

/****************************************************************************
 *  bool Hands::getF()
 *      if the players 2 cards match return 1 else return 0. Necessary for
 *  splitting
 ****************************************************************************/
bool Hands::getF()
{
    if(h[0]->Face()==h[1]->Face())
        return 1;
    else
        return 0;
}

/****************************************************************************
 *  void Hands::ifA()
 *      if the dealers first card is an ace then hA=1
 ****************************************************************************/
void Hands::ifA()
{
    hA=1;
}

/****************************************************************************
 *  bool Hands::getA()
 *      return hA(hA tells if the dealers first card is an ace)
 ****************************************************************************/
bool Hands::getA()
{
    return hA;
}

/****************************************************************************
 *  unsigned char Hands::getCNum()
 *      Removes a card from a player. Val is lowered by their second cards value
 *  and number of cards is decremented. It is important for splitting
 ****************************************************************************/
unsigned char Hands::getCNum()
{
    val-=h[1]->Val();
    --ncrd;
    return h[1]->gtCNum();
}