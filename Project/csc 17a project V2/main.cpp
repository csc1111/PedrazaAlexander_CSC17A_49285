/* 
 * File:   main.cpp
 * Author: Alexander PEdraza
 * Created on November 5th, 2019, 12:36 PM
 * Purpose:  Game of black jack.
 *           
 */

#include <iostream>
#include <iomanip>

using namespace std;

#include "Deck.h"
/*
 * 
 */
void game();
void dHand(Card *x[], int c);


int main(int argc, char** argv) 
{

    game();

    

    return 0;
}

void game()
{    
    Deck dec;
    int n=11;               //max number
    dec.dsply();
    cout << "\n shuffle \n";
    dec.shfl();
    dec.dsply();
    cout << endl;
    
    Card *plyr[n];
    Card *house[n];
    
    plyr[0]=dec.deal();
    
    plyr[1]=dec.deal();
    dHand(plyr, 2);

}

void dHand(Card *x[], int c)
{
    char val=0;
    int y=0;
    cout << "______________\n";
    while(y<c)
    {
        cout << "|" << x[y]->Suit();
        cout << setw(5) << "|";

        y++;
    }
    cout << endl;
    y=0;
    while(y<c)
    {
        cout << "|  " << x[y]->Face();
        cout << setw(3) << "|";
        y++;
    }
    cout << "\n______________\n";

}