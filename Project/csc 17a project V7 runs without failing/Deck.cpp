/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Deck.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>

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
    cout << "\n|Cards Shuffled|\n";
}

Card *Deck::deal()
{
    
    if(dlt>=crds)
    {
        dlt=0;
        shfl();
    }
    ++dlt;
    
    return dk[dlt-1];
}

void Deck::dsply()
{
    cout << "#\tSuit\tFace\tValue\n";
    for(unsigned char c=0;c<crds;c++)
    {
        cout << static_cast<int>(dk[c]->gtCNum());
        cout << "\t" << dk[c]->Suit();
        cout << "\t" << dk[c]->Face();
        cout << "\t" << static_cast<int>(dk[c]->Val()) << endl;
    }
}

unsigned char Deck::gtDlt()
{
    return dlt;
}
