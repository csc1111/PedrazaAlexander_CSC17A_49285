/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alexf
 *
 * Created on December 10, 2020, 6:52 PM
 */

#include <iostream>

using namespace std;

#include "Deck.h"
/*
 * 
 */
int main(int argc, char** argv) 
{
    Deck dec;
    dec.dsply();
    cout << "\n shuffle \n";
    dec.shfl();
    dec.dsply();
    

    

    return 0;
}

