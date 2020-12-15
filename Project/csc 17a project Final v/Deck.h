/* 
 * 
 * File:   Deck.h
 * Author: Alexander Pedraza
 * Purpose: Deck header file for template 
 *          class Deck
 * Created on December 14, 2020, 7:44 PM
 */

#ifndef DECK_H
#define DECK_H

using namespace std;
#include "CardDeck.h"
#include "Hands.h"

template <class T>
class Deck
{
private:
    unsigned char crds; //cards
    unsigned char shf;  //times shuffled
    unsigned char dlt;  //Cards dealt
    T **dk;             //pointer to a pointer of a T(Card)
    
public:
    Deck();
    ~Deck();
    void shfl();
    unsigned char deal();
    void dsply();
    unsigned char gtDlt();
    
    
};

/****************************************************************************
 *  Deck<T>::Deck()
 *      Default constructor of Deck. Sets Crds to 52, randomn number, shf to 20
 *  and dlt to 0; It also puts together the deck of cards into dk using a loop
 ****************************************************************************/
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

/****************************************************************************
 *  Deck<T>::~Deck
 *      Deconstructor for deck. It deallocates the memory of dk[] and dk
 ****************************************************************************/
template <class T>
Deck<T>::~Deck()
{
    for(unsigned char c=0;c<crds;++c)
    {
        delete dk[c];
    }
    delete []dk;
}

/****************************************************************************
 *  void Deck<T>::shfl()
 *      Shuffles the deck of cards in dk depending on times shuffled
 ****************************************************************************/
template <class T>
void Deck<T>::shfl()
{
    for(int x=1;x<=shf;++x)
    {
        for(int y=0;y<shf;++y)
        {
            unsigned char tmpRnd=rand()%crds;   //random number
            Card* temp=dk[y];
            dk[y]=dk[tmpRnd];
            dk[tmpRnd]=temp;
        }
    }
    cout << "\n|Cards Shuffled|\n";
}

/****************************************************************************
 *  unsigned char Deck<T>::deal()
 *      Deals the deck of cards and increments the cards delt to avoid repeats.
 *  If the number of cards dealt exceeds the cards in the deck it will shuffle
 *  the cards and make dlt 0;
 ****************************************************************************/
template <class T>
unsigned char Deck<T>::deal()
{
    
    if(dlt>=crds)
    {
        dlt=0;
        shfl();
    }
    ++dlt;
    
    return dk[dlt-1]->gtCNum(); //only returns the card number
}

/****************************************************************************
 *  Void Deck<T>::dsply()
 *      Displays the deck of cards. it outputs the card number, suit, face,
 *  and value
 ****************************************************************************/
template <class T>
void Deck<T>::dsply()
{
    cout << "#\tSuit\tFace\tValue\n";
    for(unsigned char c=0;c<crds;c++)       //loops through all cards
    {
        cout << static_cast<int>(dk[c]->gtCNum());
        cout << "\t" << dk[c]->Suit();
        cout << "\t" << dk[c]->Face();
        cout << "\t" << static_cast<int>(dk[c]->Val()) << endl;
    }
}

/****************************************************************************
 *  Unsigned char Deck<T>::gtDlt()
 *      returns the number of cards dealt
 ****************************************************************************/
template <class T>
unsigned char Deck<T>::gtDlt()
{
    return dlt;
}


#endif /* DECK_H */

