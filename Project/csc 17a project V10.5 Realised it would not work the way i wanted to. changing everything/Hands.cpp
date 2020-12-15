/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Hands.h"

#include <iostream>
#include <iomanip>

Hands::Hands()
{
    ncrd=0;
    cout<<"handC";
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

void Hands::dsply(char x)
{

    for(int i=0;i<ncrd;++i)
        cout << "_______";
    cout << endl;
    
    cout << "|" << cr[0]->Suit();
    cout << setw(5) << "|";
    cout << "|" << setw(5) << "|";

    
    cout << endl;


    cout << "|  " << cr[0]->Face();
    cout << setw(3) << "|";
    cout << "|" << setw(5) << "|";

    cout << endl;
    
    for(int i=0;i<ncrd;++i)
        cout << "_______";
    cout << endl;
}


void Hands::Deal(Card *y)
{
    cr[ncrd]=y;
    ++ncrd;

}

/*unsigned char Hands::getV(int x)
{
    return cr[x]->Val();
}*/