/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Deck.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

Deck::Deck()
{
    srand(time(0));
    crds=52;
    shf=20;
    dlt=0;
    
    dk=new Card*[crds];
    for(unsigned char c=0;c<crds;++c)
        dk[c]=new Card(c);
}

Deck::~Deck()
{
    for(unsigned char c=0;c<crds;++c)
    {
        delete dk[c];
    }
    delete []dk;
}

void Deck::shfl()
{
    for(int x=1;x<=shf;++x)
    {
        for(int y=0;y<shf;++y)
        {
            unsigned char tmpRnd=rand()%crds;
            Card* temp=dk[y];
            dk[y]=dk[tmpRnd];
            dk[tmpRnd]=temp;
        }
    }
}

unsigned char *Deck::deal(unsigned char nD)
{
    if(nD>=crds-dlt)
    {
        dlt=0;
        shfl();
    }
    
    return 0;
}

void Deck::dsply()
{
    for(unsigned char c=0;c<crds;c++)
    {
        cout<<static_cast<int>(c)<<" "<<dk[c]->Face();
        cout<<dk[c]->Suit()<<" "<<static_cast<int>(dk[c]->Val())<<endl;
    }
}