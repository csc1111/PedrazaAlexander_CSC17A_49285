/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/*
#include <iostream>
#include "Dealer.h"


#include <iostream>

Dealer::Dealer(string n)
{
    vl=0;
    nm=n;
    ace=0;
    cout << "Dealer made";
    
}

void Dealer::setHand(unsigned char d)
{
    hnd.Deal(d);
    hnd.dsply();

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