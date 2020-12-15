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
bool game(int&, string, string);

int main(int argc, char** argv) 
{
    
    int my;               //money
    string nm;              //name
    string dn;              //dealers name
    bool b=0;

    
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

    
    do
    {
        b=game(my, nm, dn);
    }
    while(b);
    

    return 0;
}

bool game(int &my, string nm, string dn)
{    
    Deck<Card> dec;
    //dec.dsply();

    bool ch;
    bool L=1;
    char HoP;
    Player y(nm, my);    
    Player d(dn);
    int bet=0;

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
    y.LoGMny(-bet);
    
    if(bet!=0)
    {
        y.setHand(dec.deal());
        d.setHand(dec.deal());
        y.setHand(dec.deal());
        d.setHand(dec.deal());
        d.dsply(1);
        y.dsply();
        if(y.getVal()==21)
        {
            cout << "21!!!\n";
            cout <<"you won: $" << (bet+bet/2) << endl;
            y.LoGMny(bet/2);
        }
        else
        {
            do
            {
                cout << "Would you like to hit(h) or pass(p)?: ";
                cin >> HoP;
                while(HoP!='h'&&HoP!='p')
                {
                    cout << "Error. Must enter h or p: ";
                    cin >> HoP;
                }
                if(HoP=='h')
                {
                    y.setHand(dec.deal());
                    d.dsply(1);
                    y.dsply();
                    if(y.getVal()>21)
                    {
                        cout << "You went over 21:(\n";
                        L=0;
                    }
                }
            }while(HoP=='h'&&L);
        }
                
    }

    my=y.getMny();
    cout << my;
    return bet;
}


