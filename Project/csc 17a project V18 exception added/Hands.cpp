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
    ace=0;
    hA=0;
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

void Hands::dsply(string z, char x)
{
    
    cout << "WHAT";
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
    if(h[0]->Suit()=='A')
    {
        ifA();
    }
}


void Hands::Deal(unsigned char y)
{
    
    h[ncrd]=new Card(y);
    if(h[ncrd]->Face()=='A')
        ace=1;
    val+=h[ncrd]->Val();
    ++ncrd;
}
void Hands::setNCRD(int x)
{
    ncrd=x;
}
unsigned char Hands::getV()
{

    if(val<=11&&ace)
    {
        val+=10;
        ac=1;
    }
    else if(val>21&&ace&&ac)
    {
        val-=10;
        ac=0;
    }
    return val;
}
bool Hands::getF()
{
    if(h[0]->Face()==h[1]->Face())
        return 1;
    else
        return 0;
}

void Hands::ifA()
{
    cout <<"fdhddd";
    hA=1;
}

bool Hands::getA()
{
    return hA;
}

unsigned char Hands::getCNum()
{
    --ncrd;
    return h[1]->gtCNum();
}