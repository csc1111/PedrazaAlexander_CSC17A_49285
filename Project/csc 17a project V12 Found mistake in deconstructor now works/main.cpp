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
#include "Hands.h"
#include "Player.h"

/*
 * 
 */
bool game(int, string, string);

int main(int argc, char** argv) 
{
    
    int my;               //money
    string nm;              //name
    string dn;              //dealers name
    bool b=1;

    
    cout << "Welcome to my black jack only casino!\n";
    cout << "The game has the same rules as normal black jack with one deck of"
            << " cards.\n";
    cout << "What is your name: ";
    getline(cin, nm);
    cout << "How much money do you have to gamble?($10 minimum bet): $";
    cin >> my;
    cin.ignore();
    cout << "Enter dealers name: ";
    getline(cin, dn);

    
    while(b)
        b=game(my, nm, dn);
    
    

    return 0;
}

bool game(int my, string nm, string dn)
{    
    Deck<Card> dec;
    //dec.dsply();

    bool ch;
    Player y(nm, my);    
    Player d(dn);
    
    int bet=1;
    char hCrd=1;          //dealers hidden card
    

    bet=0;
    dec.shfl();
    cout << "Would you like to be a dirty cheater and see the shuffled deck?"
            << "(enter 1 for yes or 0 for no): ";
    cin >> ch;
    if(ch)
        dec.dsply();
    cout << endl;

    cout << y.getNm()<<"'s Money: $"<<y.getMny()<<endl;
    cout << "How much would you like to bet?(min $10 or enter 0 to end): ";
    cin >> bet;
   // if(bet!=0)
    //{
    y.setHand(dec.deal());
    d.setHand(dec.deal());

    //}

    return 1;
}


