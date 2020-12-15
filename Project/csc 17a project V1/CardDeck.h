/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CardDeck.h
 * Author: alexf
 *
 * Created on December 10, 2020, 11:38 PM
 */

#ifndef CARDDECK_H
#define CARDDECK_H


using namespace std; 

class Card
{
private:
    unsigned char cNum;
public:
    Card(unsigned char n);
    unsigned char Face();
    unsigned char Suit();
    unsigned char Val();
};


#endif /* CARDDECK_H */

