/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Deck.h
 * Author: alexf
 *
 * Created on December 11, 2020, 6:07 PM
 */

#ifndef DECK_H
#define DECK_H

#include "CardDeck.h"

template <class T>
class Deck
{
private:
    unsigned char crds;
    unsigned char shf;
    unsigned char dlt;
    T **dk;
    
public:
    Deck();
    ~Deck();
    void shfl();
    T *deal();
    void dsply();
    unsigned char gtDlt();
    
    
};

template <class T>
Deck<T>::Deck()
{
    srand(time(0));
    crds=52;
    shf=20;
    dlt=0;
    
    dk=new T*[crds];
    for(unsigned char c=0;c<crds;++c)
        dk[c]=new T(c);
}

template <class T>
Deck<T>::~Deck()
{
    for(unsigned char c=0;c<crds;++c)
    {
        delete dk[c];
    }
    delete []dk;
}

template <class T>
void Deck<T>::shfl()
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

template <class T>
T *Deck<T>::deal()
{
    
    if(dlt>=crds)
    {
        dlt=0;
        shfl();
    }
    ++dlt;
    
    return dk[dlt-1];
}

template <class T>
void Deck<T>::dsply()
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

template <class T>
unsigned char Deck<T>::gtDlt()
{
    return dlt;
}


#endif /* DECK_H */

