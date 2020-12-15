/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Hands.h"

#include <iostream>

Hands::Hands()
{
    ncrd=0;
}

Hands::~Hands()
{
    for(unsigned char c=0;c<ncrd;++c)
    {
        delete cr[c];
    }
    //delete []cr;
}

void Hands::dsply()
{
    int y=0;
    for(int i=0;i<ncrd;++i)
        cout << "_______";
    cout << endl;
    
    while(y<ncrd)
    {
        cout << "|" << cr[y]->Suit();
        cout << setw(5) << "|";
        y++;
    }
    cout << endl;
    y=0;
    
    while(y<ncrd)
    {
        cout << "|  " << cr[y]->Face();
        cout << setw(3) << "|";
        y++;
    }
    cout << endl;
    
    for(int i=0;i<ncrd;++i)
        cout << "_______";
    cout << endl;
}

void Hands::Deal(unsigned char x, Card *y)
{
    for(int i=0; i<x; ++i)
    {
        cr[ncrd]=y;
        ++ncrd;
    }
    
}