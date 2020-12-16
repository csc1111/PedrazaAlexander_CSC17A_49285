/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Class: CSC 17A 49285
 * Professor: Mark Lehr
 * Created on November 5th, 2019, 12:36 PM
 * Purpose:  Game of black jack. 
 * files included: CardDeck.h
 *                  CardDeckF.cpp
 *                  deck.h
 *                  hands.h
 *                  hands.cpp
 *                  AbstractC.h
 *                  Player.h
 *                  Player.cpp
 *           
 */

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

#include "Deck.h"
#include "Hands.h"
#include "Player.h"


bool game(Deck<Card> &, int&, string, string);
bool HorP(Deck<Card> &, Player &, Player &, int &bet);
inline bool del(Deck<Card> &, Player &, Player &, int &bet);
void LoGMny(Player &, int);


int main(int argc, char** argv) 
{
    Deck<Card> dec;         //deck of cards
    int my;                 //money
    string nm;              //name
    string dn;              //dealers name
    bool b=0;               //decides if to keep playing
    int GP=0;               //games played
    vector<int> M;          //money after game
    bool chc;               //choice to see deck          

    
    cout << "\n//*//Welcome to my black jack only casino!//*//\n";
    cout << "_________________________________________________________________\n";
    cout << "The game has the same rules as normal black jack with one deck of"
            <<" cards.\nYou can double down, you can surrender and get half of"
            <<" your bet back, you can get insurance if the dealers open card is"
            <<" an ace (half you bet),\nand you can split cards with the same"
            <<" face if you can afford it(up to 2 times). Your bet must be"
            <<" divisible by 10. If you get a Blackjack \nyou automatically get"
            <<" your bet and %50. If the dealer gets a black jack, even if you"
            <<" have 21 as well the dealer wins. If you had bought insurance you"
            <<" break even. \n \tHave fun!\n";
    cout << "What is your name: ";
    getline(cin, nm);
    cout << "How much money do you have to gamble?($10 minimum bet): $";
    cin >> my;
    
    //Validation. Tests if player has enough money
    while(my<10)
    {
        cout << "You can't even play one game with that bring more: ";
        cin >> my;
    }
    
    cin.ignore();
    cout << "Enter dealers name: ";
    getline(cin, dn);
    cout << "Would you like to see the deck before it is shuffled?:"
            <<"(1 for yes and 0 for no)";
    cin >>chc;
    if(chc)
    {
        dec.dsply();
    }
    dec.shfl();
    //runs the Game
    do
    {
        int sm=my;  //sm is money before any profits or losses
        b=game(dec, my, nm, dn);    //game returns b
        M.push_back(my-sm);         //keeps track of wins and losses
        GP++;                       //games played
    }
    while(b);                       //if b then game runs again
    
    cout << GP << " Games played\n";//games played
    for(int x=1; x<GP; ++x)
    {
        //outputs the profits or losses per game played
        cout << "Game " << x << ": $" << M[x-1] << endl;
    }
    cout << "\nI hope you enjoyed my casino:).";
    
    

    return 0;
}

bool game(Deck<Card> &dec, int &my, string nm, string dn)
{    

    bool ch;            //choice to cheat

    bool BJ=0;          //if player has black jack
    bool L=1;           //if 1 player is winning if 0 losing
    Player y(nm, my);   //Player you
    Player d(dn);       //Player dealer
    int bet=0;          //bet

    
    cout << "\nWould you like to be a cheater and see the shuffled deck?"
            << "(enter 1 for yes or 0 for no): ";
    cin >> ch;
    if(ch)
    {
        dec.dsply();
    }
    cout << endl;

    cout << y.getNm()<<"'s Money: $"<<y.getMny()<<endl;
    cout << "How much would you like to bet?(Must be a multiple of 10"
            <<" or enter 0 to end): ";
    try     
    {
        cin >> bet;
        if(bet>y.getMny()) //if user places bet he can't afford
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
   


    if(bet!=0)  //if the bet is 0 the game doesn't move on
    {
        y.setHand(dec.deal());
        d.setHand(dec.deal());
        y.setHand(dec.deal());
        d.setHand(dec.deal());
        d.dsply(1);
        y.dsply();
        if(y.getVal()==21)  //if player has a 21 in the first 2 cards
        {                   //he automatically wins
            cout << "BLACKJACK WOOOOOOOOO\n";
            bet+=bet/2;
            LoGMny(y, bet);
            LoGMny(d, bet);
            BJ=1;
        }
        else
        {
            char chc;   //chc to split or not
            if(y.splt()&&y.getMny()>=bet*2)     //if the player has two cards 
            {                                   //with matching faces they may 
                                                //split
                cout << "Would you like to split?(y or n)?: ";
                cin >> chc;
                if(chc=='y')
                {
                    Player s;               //new player is created 
                    s.setHand(y.spltC());   //new player now has player y's
                    s.setHand(dec.deal());  //first card
                    d.dsply(1);
                    s.dsply();
                    if(d.splt()&&y.getMny()>=bet*2)
                    {
                        cout << "Would you like to split?(y or n)?: ";
                        cin >> chc;
                        if(chc=='y')
                        {
                            Player ss;
                            ss.setHand(s.spltC());
                            ss.setHand(dec.deal());
                            d.dsply(1);
                            ss.dsply();
                            cout << "Do you want to double down(d) or "
                                    <<"surrender(s)(n for no)?";
                            cin >> chc;
                            if(chc=='d')
                            {
                                if(ss.getMny()>=bet*2)
                                { 
                                    bet*=2;
                                    ss.setHand(dec.deal());
                                    d.dsply(1);
                                    ss.dsply();
                                    if(ss.getVal()>21)
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
                                    L=HorP(dec, ss, d, bet);
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
                                L=HorP(dec, ss, d, bet);
                                LoGMny(y, ss.getVal());
                            }
                            d.setHand(dec.deal());
                        }
                    }
                    cout << "Do you want to double down(d) or surrender(s)"
                            <<"(n for no)?";
                    cin >> chc;
                    if(chc=='d')
                    {
                        //if 'd' players bet is doubled and a card is added
                        //to their deck
                        if(s.getMny()>=bet*2)
                        { 
                            bet*=2;
                            s.setHand(dec.deal());
                            d.dsply(1);
                            s.dsply();
                            if(s.getVal()>21)
                            {
                                cout << "YOU BUSTED";
                                L=0;            //lost
                                LoGMny(y, -bet);
                            }
                            L=1;    //winning
                        }
                        else
                        {
                            cout<< "You can't afford to double down.";
                            L=HorP(dec, s, d, bet);
                        }
                    }
                    else if(chc=='s')   //if player surrenders they are returned
                    {                   //half their bet and lose
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
                    L=HorP(dec, y, d, bet); //if they can't afford it play as 
                }                           //normal
            }
            else if(chc=='s')
            {
                cout << "Chicken ";
                L=0;
                bet/=2;
                LoGMny(y, -bet);
            }
            else
                L=HorP(dec, y, d, bet);//player  hits or passes till they 
            if(L)                       //pass or lose
                L=del(dec, y, d, bet);  //if the player hasn't lost yet
        }                               //dealer will play his hand
                
    }
    
    if(L&&y.getVal()==d.getVal()&&BJ!=1)
        cout << "You tied";                     //if you tie
    else if(L)
        cout << "You won: $"<<bet;              //if you win
    else
        cout << "You lost: $"<<bet;             //if you lost
            
    
    if(y.getMny()<10)       //get more money
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

/***********************************************************************
 *  bool HorP
 *
 *      This function allows you to hit or pass on your hand. if you go
 *  over 21 it lowers the players money and returns a 0;
 *************************************************************************/
bool HorP(Deck<Card> &dec, Player &y, Player &d, int &bet)
{
    char HoP;           //hit or pass
    bool L=1;           //loss
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

/*****************************************************************************
 *inline bool del
 *      
 *      This function allows the dealer to play his hand and allows player to
 *  take insurance if the open dealer card has an ace. If the Player takes 
 *  insurance he puts up half his bet saying that the dealer has a black jack
 *  if he is right he breaks even. Dealer must hit if the value of his cards 
 *  are 16 or less. Also gives or takes bet depending on if the dealer wins.
 *  returns 0 if loss or 1 if win.
 *****************************************************************************/
inline bool del(Deck<Card> &dec, Player &y, Player &d, int &bet)
{
    bool L;         //loss
    bool ins;       //if player took insurance
    int insb;       //insurance value
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

/****************************************************************************
 *  void LoGMny
 *      function that adds or subtracts bet from users total
 ****************************************************************************/
void LoGMny(Player &p, int x)
{
    p.mny+=x;//x is bet
}