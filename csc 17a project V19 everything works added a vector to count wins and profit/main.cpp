/* 
 * File:   main.cpp
 * Author: Alexander PEdraza
 * Created on November 5th, 2019, 12:36 PM
 * Purpose:  Game of black jack.
 *           
 */

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

#include "Deck.h"
#include "Hands.h"
#include "Player.h"

/*
 * 
 */
bool game(Deck<Card> &, int&, string, string);
bool HorP(Deck<Card> &, Player &, Player &, int &bet);
inline bool del(Deck<Card> &, Player &, Player &, int &bet);
void LoGMny(Player &, int);



int main(int argc, char** argv) 
{
    Deck<Card> dec;
    int my;               //money
    string nm;              //name
    string dn;              //dealers name
    bool b=0;
    int GP=0;             //games played
    vector<int> M;        //money after game

    
    cout << "\n//*//Welcome to my black jack only casino!//*//\n";
    cout << "_________________________________________________________________\n";
    cout << "The game has the same rules as normal black jack with one deck of"
            << " cards.\n";
    cout << "What is your name: ";
    getline(cin, nm);
    cout << "How much money do you have to gamble?($10 minimum bet): $";
    cin >> my;
    while(my<10)
    {
        cout << "You can't even play one game with that bring more: ";
        cin >> my;
    }
    cin.ignore();
    cout << "Enter dealers name: ";
    getline(cin, dn);

    dec.shfl();
    do
    {
        int sm=my;
        b=game(dec, my, nm, dn);
        M.push_back(my-sm);
        GP++;
    }
    while(b);
    
    cout << GP << " Games played\n";
    for(int x=1; x<GP; ++x)
    {
        
        cout << "Game " << x << ": $" << M[x-1] << endl;
    }
    cout << "\nI hope you enjoyed my casino:).";
    
    

    return 0;
}

bool game(Deck<Card> &dec, int &my, string nm, string dn)
{    
    
    //dec.dsply();

    bool ch;

    bool BJ=0;            //black jack
    bool L=1;
    char HoP;
    Player y(nm, my);    
    Player d(dn);
    int bet=0;    

    
    cout << "\nWould you like to be a cheater and see the shuffled deck?"
            << "(enter 1 for yes or 0 for no): ";
    cin >> ch;
    if(ch)
        dec.dsply();
    cout << endl;

    cout << y.getNm()<<"'s Money: $"<<y.getMny()<<endl;
    cout << "How much would you like to bet?(Must be a multiple of 10"
            <<" or enter 0 to end): ";
    try
    {
        cin >> bet;
        if(bet>y.getMny())
            throw 0;
        
        
    }catch(int x)
    {
        cout << "error " << x << " You can't afford that bet.\n";
    }
    
            
    while(bet!=0&&bet%10!=0)
    {
        cout << "must be $10 or more and a multitude of 10: ";
        cin >> bet;
    }
    LoGMny(d, -bet);


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
            cout << "BLACKJACK WOOOOOOOOO\n";
            bet+=bet/2;
            LoGMny(y, bet);
            LoGMny(d, bet);
            BJ=1;
        }
        else
        {
            char chc;
            if(y.splt()&&y.getMny()>=bet*2)
            {
                cout << "Would you like to split?(y or n)?: ";
                cin >> chc;
                if(chc=='y')
                {
                    Player s;
                    s.setHand(y.spltC());
                    s.setHand(dec.deal());
                    d.dsply(1);
                    s.dsply();
                    cout << "Do you want to double down(d) or surrender(s)(n for no)?";
                    cin >> chc;
                    if(chc=='d')
                    {
                        if(s.getMny()>=bet*2)
                        { 
                            bet*=2;
                            s.setHand(dec.deal());
                            d.dsply(1);
                            s.dsply();
                            if(s.getVal()>21)
                            {
                                cout << "YOU BUSTED";
                                L=0;
                                LoGMny(y, -bet);
                            }
                            L=1;
                        }
                        else
                        {
                            cout<< "You can't afford to double down.";
                            L=HorP(dec, s, d, bet);
                        }
                    }
                    else if(chc=='s')
                    {
                        cout << "Chicken ";
                        L=0;
                        bet/=2;
                        LoGMny(y, -bet);
                    }
                    else
                    {
                        L=HorP(dec, s, d, bet);
                        LoGMny(y, s.getVal());
                    }
                    y.setHand(dec.deal());
                }

            }
            
            if(chc)
            {
                d.dsply(1);
                y.dsply();
            }
            cout << "Do you want to double down(d) or surrender(s)(n for no)?";
            cin >> chc;
            if(chc=='d')
            {
                if(y.getMny()>=bet*2)
                { 
                    bet*=2;
                    y.setHand(dec.deal());
                    d.dsply(1);
                    y.dsply();
                    if(y.getVal()>21)
                    {
                        cout << "YOU BUSTED";
                        L=0;
                        LoGMny(y, -bet);
                    }
                }
                else
                {
                    cout<< "You can't afford to double down.";
                    L=HorP(dec, y, d, bet);
                }
            }
            else if(chc=='s')
            {
                cout << "Chicken ";
                L=0;
                bet/=2;
                LoGMny(y, -bet);
            }
            else
                L=HorP(dec, y, d, bet);
            if(L)
                L=del(dec, y, d, bet);
        }
                
    }
    
    if(L&&y.getVal()==d.getVal()&&BJ!=1)
        cout << "You tied";
    else if(L)
        cout << "You won: $"<<bet;
    else
        cout << "You lost: $"<<bet;
            
    
    if(y.getMny()<10)
    {
        bool yon;
        int amnt;
        cout << "\nYou can't afford min bet. Do you want to borrow $ or leave?"
                <<"(enter 1 for yes or 0 for no): ";
        cin >>yon;
        if(yon)
        {
            cout << "How much do you want?: $";
            cin >> amnt;
            while(amnt+y.getMny()<10)
            {
                cout << "You need more for the minimum bet. Try again:";
                cin >> amnt;
            }
            LoGMny(y, amnt);
        }
        else
        {
            cout << "BYE\n";
            bet=0;
        }
    }
    my=y.getMny();
    return bet;
}


bool HorP(Deck<Card> &dec, Player &y, Player &d, int &bet)
{
    char HoP;
    bool L=1;
    do
    {
        cout << " Would you like to hit(h) or pass(p)?: ";
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
                LoGMny(y, -bet);
            }
        }
    }while(HoP=='h'&&L);
    return L;
}

inline bool del(Deck<Card> &dec, Player &y, Player &d, int &bet)
{
    bool L;
    bool ins;
    int insb;
    if(d.getHA()&&y.getMny()>=bet+bet/2)
    {
        cout << "Would you like to take insurance for half your bet?"
                <<"(1 for yes 0 for no):";
        cin >> ins;
        if(ins)
        {
            insb=bet/2;
            LoGMny(y, -insb);
        }
    }
    d.dsply();
    y.dsply();

    if(d.getVal()==21)
    {
        cout << "Dealer has a blackjack.\n";
        if(ins)
            LoGMny(y, bet);
        LoGMny(y, -bet);
        L=0;
    }
    else
    {
        while(d.getVal()<17)
        {
            d.setHand(dec.deal());
            d.dsply();
            y.dsply();
        }
        if(d.getVal()>21)
        {
            cout << "Dealer busted :D\n";
            LoGMny(y, bet);
        }
        else if(d.getVal()<y.getVal())
        {
            cout << "You were closer to 21!";
            LoGMny(y, bet);
        }
        else if(d.getVal()>y.getVal()&&d.getVal()<22)
        {
            cout << "The dealer was closer to 21 :(";
            LoGMny(y, -bet);
            L=0;
        }
        else if(d.getVal()==y.getVal())
            cout << "You and the dealer are even";

    }
    return L;
}


void LoGMny(Player &p, int x)
{
    p.mny+=x;
}