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
#include "Dealer.h"
/*
 * 
 */
void game(int, string, string);

int main(int argc, char** argv) 
{
    
    int my;               //money
    string nm;              //name
    string dn;              //dealers name


    
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

    
    
    game(my, nm, dn);
    
    

    return 0;
}

void game(int my, string nm, string dn)
{    
    Deck<Card> dec;
    bool ch;
    Player you(nm, my);
    Dealer d(dn);
    int bet=1;
    
    //dec.dsply();
    while(bet!=0||you.getMny()<10)
    {
        bet=0;
        dec.shfl();
        cout << "Would you like to be a dirty cheater and see the shuffled deck?"
                << "(enter 1 for yes or 0 for no): ";
        cin >> ch;
        if(ch)
            dec.dsply();
        cout << endl;

        cout << you.getNm()<<"'s Money: $"<<you.getMny()<<endl;
        cout << "How much would you like to bet?(min $10 or enter 0 to end): ";
        cin >> bet;
        if(bet!=0)
        {
            you.Deal(dec.deal());
            d.Deal(dec.deal());
            you.Deal(dec.deal());
            d.Deal(dec.deal());
            cout << d.getNm()<<"'s Hand";
            d.dsply();
            cout << you.getNm()<<"'s Hand";
            you.dsply();
        }
    }
}


