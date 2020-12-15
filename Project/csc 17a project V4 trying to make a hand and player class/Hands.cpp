/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Hands.h"

#include <iostream>

Hands::Hands(unsigned char x, Card *y)
{
    ncrd=x;
}

Hands::~Hands()
{
    for(unsigned char c=0;c<11;++c)
    {
        delete cr[c];
    }
    //delete []cr;
}

void Hands::dsply()
{
    for(int x=0; x<ncrd+1; ++x)
    {
        //cout << cr->gtCNum();
    }
}

void Hands::Deal(unsigned char x, Card *y)
{
    for(int i=0; i<x; ++i)
        cr[x]=y;
}