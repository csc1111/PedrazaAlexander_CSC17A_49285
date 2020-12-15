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
void game(float, string);

int main(int argc, char** argv) 
{
    
    float my;               //money
    string nm;              //name


    
    cout << "Welcome to my black jack only casino!\n";
    cout << "The game has the same rules as normal black jack with one deck of"
            << " cards.\n";
    cout << "What is your name: ";
    getline(cin, nm);
    cout << "How much money do you have to gamble?($10 minimum bet): $";
    cin >> my;
    
    for(int x=0;x<3;++x)
    {
        game(my, nm);
        game(my, nm);
        cout << "j";
    }
    
    cout << "shdoashduhsaohdoiuhaso";
    return 0;
}

void game(float my, string nm)
{    
    Deck<Card> dec;
    char ch;

    
    dec.dsply();
    
    dec.shfl();
    cout << "Would you like to be a dirty cheater and see the shuffled deck?"
            << "(enter y for yes or enter anything else for no): ";
    cin >> ch;
    if(ch=='y')
        dec.dsply();

    
    //cout << endl;
    

    //you.Deal(dec.deal());
    //you.dsply();
    //you.Deal(dec.deal());
    //you.dsply();

}


