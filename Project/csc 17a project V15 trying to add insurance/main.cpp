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
bool game(Deck<Card> &, int&, string, string);
bool HorP(Deck<Card> &, Player &, Player &);


int main(int argc, char** argv) 
{
    Deck<Card> dec;
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

    dec.shfl();
    do
    {
        b=game(dec, my, nm, dn);
    }
    while(b);
    

    return 0;
}

bool game(Deck<Card> &dec, int &my, string nm, string dn)
{    
    
    //dec.dsply();

    bool ch;
    bool ins;           //insurance
    bool L=1;
    char HoP;
    Player y(nm, my);    
    Player d(dn);
    int bet=0;
    int insb=0;

    
    cout << "\nWould you like to be a dirty cheater and see the shuffled deck?"
            << "(enter 1 for yes or 0 for no): ";
    cin >> ch;
    if(ch)
        dec.dsply();
    cout << endl;

    cout << y.getNm()<<"'s Money: $"<<y.getMny()<<endl;
    cout << "How much would you like to bet?(min $10 or enter 0 to end): ";
    cin >> bet;
    
    
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
        else if(d.getHA()&&y.getMny()>=bet+bet/2)
        {
            cout << "Would you like to take insurance for half your bet?"
                    <<"(1 for yes 0 for no):";
            cin >> ins;
            if(ins)
            {
                insb+=bet/2;
                L=HorP(dec, y, d);
            }
        }
        else
            L=HorP(dec, y, d);
        if(L)
        {
            d.dsply();
            y.dsply();
            while(d.getVal()<17)
            {
                d.setHand(dec.deal());
                d.dsply();
                y.dsply();
            }
            if(d.getVal()>21)
                cout << "Dealer busted :D\n";
            else if(d.getVal()<y.getVal())
                cout << "You were closer to 21!";
            else if(d.getVal()>y.getVal()&&d.getVal()<22)
            {
                cout << "The dealer was closer to 21 :(";
                L=0;
            }
        }
                
    }
    
    if(L)
    {
        cout << " You won: $";
        y.LoGMny(bet);
    }
    else
    {
        cout << " You lost: $";
        y.LoGMny(-bet);
    }
    
    my=y.getMny();
    cout << my;
    return bet;
}


bool HorP(Deck<Card> &dec, Player &y, Player &d)
{
    char HoP;
    bool L=1;
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
    return L;
}

