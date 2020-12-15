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
    float my;
    char ch;                //cheat mode
    dec.dsply();
    cout << "Welcome to my black jack only casino!\n";
    cout << "The game has the same rules as normal black jack with one deck of"
            << " cards.\n";
    cout << "How much money do you have to gamble?($10 minimum bet): $";
    cin >> my;
    
    dec.shfl();
    cout << "Would you like to be a dirty cheater and see the shuffled deck?"
            << "(enter y for yes or enter anything else for no): ";
    cin >> ch;
    if(ch=='y')
        dec.dsply();

    
    cout << endl;
    
    Card *plyr[n];
    Card *hous[n];
    
    
    plyr[0]=dec.deal();
    hous[0]=dec.deal();
    plyr[1]=dec.deal();
    hous[1]=dec.deal();
    cout << "Dealers Hand";
    dHand(hous, 2);
    cout << "Players Hand";
    dHand(plyr, 2);

}

void dHand(Card *x[], int c)
{
    int y=0;
    for(int i=0;i<c;++i)
        cout << "_______";
    cout << endl;
    
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
    cout << endl;
    
    for(int i=0;i<c;++i)
        cout << "_______";
    cout << endl;
}

