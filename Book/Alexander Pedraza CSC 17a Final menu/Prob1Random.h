/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Prob1Random.h
 * Author: Alexander Pedraza
 *
 * Created on December 16, 2020, 8:37 AM
 */

#ifndef PROB1RANDOM_H
#define PROB1RANDOM_H

using namespace std;

template <class T>
class Prob1Random
{
    private:
            T *set;      //The set of numbers to draw random numbers from
            char  nset;     //The number of variables in the sequence
            int  *freq;     //Frequency of all the random numbers returned
            int   numRand;  //The total number of times the random number function is called
    public:
            Prob1Random(const char,const char *);     //Constructor
            ~Prob1Random(void);                       //Destructor
            char randFromSet(void);                   //Returns a random number from the set
            int *getFreq(void) const;                 //Returns the frequency histogram
            char *getSet(void) const;                 //Returns the set used
            int getNumRand(void) const;               //Gets the number of times randFromSet has
                                                      //been called
};

template <class T>
Prob1Random<T>::Prob1Random(const char n,const char *r)     //Constructor
{
    srand(time(0));
    nset=n;
    numRand=0;
    set = new char [n];
    for(char x=0; x<n; ++x)
        set[x] = r[x];
    freq = new int [n];
    for(int x=0;x<n;++x)
        freq[x]=0;
}
template <class T>
Prob1Random<T>::~Prob1Random(void)                       //Destructor
{
    delete set;
    delete freq;
}
template <class T>
char Prob1Random<T>::randFromSet(void)                   //Returns a random number from the set
{
    int x;
    ++numRand;
    x=rand()%nset;
    ++freq[x];
    return set[x];
}
template <class T>
int *Prob1Random<T>::getFreq(void) const                 //Returns the frequency histogram
{
    return freq;
}
template <class T>
char *Prob1Random<T>::getSet(void) const                 //Returns the set used
{
    return set;
}
template <class T>
int Prob1Random<T>::getNumRand(void) const                //Gets the number of times randFromSet has
{                                                         //been called
    return numRand;
}

#endif /* PROB1RANDOM_H */

