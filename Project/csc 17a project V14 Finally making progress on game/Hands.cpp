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
    val=0;
    ncrd=0;  
}

Hands::~Hands()
{
    for(unsigned char i=0;i<ncrd;++i)
        delete h[i];
}

void Hands::dsply(string z)
{
    cout << z << "'s deck\n";

    int y=0;
    for(int i=0;i<ncrd;++i)
        cout << "_______";
    cout << static_cast<int>(val) << endl;
    
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
}


void Hands::Deal(unsigned char y)
{
    
    h[ncrd]=new Card(y);
    val+=h[ncrd]->Val();
    
    ++ncrd;
}
void Hands::setNCRD(int x)
{
    ncrd=x;
}
unsigned char Hands::getV()
{
    return val;
}