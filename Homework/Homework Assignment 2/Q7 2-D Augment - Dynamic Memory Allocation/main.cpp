/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Created on September 30th, 2020, 11:20 PM
 */

#include <iostream>

using namespace std;

//Functions
int **getData(int &,int &);//Get the Matrix Data

void printDat(const int * const *,int,int);//Print the Matrix

int **augment(const int * const *,int,int);//Augment the original array

void destroy(int **,int);//Destroy the Matrix, i.e., reallocate memory

int main()
{
    //Variables
    int rw,                             //row size
        cl;                             //column size
    int **ary = getData(rw, cl);          //input array    
  
    ary = augment(ary, rw,cl);          //augment array
    printDat(ary, rw, cl);               //outputs augmented array
    
    destroy(ary, rw);
    
    return 0;
}


int **getData(int &rw, int &cl)
{
    cin >> rw >> cl;
    ++rw;
    ++cl;
    int **ta = new int *[rw]; //array created
    for(int x=0; x<rw; ++x)
        ta[x] = new int [cl];   //2d array
                
    for(int x=0; x<rw-1; ++x)
        for(int y=0; y<cl-1; ++y)
            cin >> ta[x][y];    //input into array

    return ta;
}

void printDat(const int* const *ar, int rw, int cl)
{
    //outputs the 2D array
    for(int x=1; x<rw; ++x)
    {
        for(int y=1; y<cl; ++y)
        {
            cout << ar[x][y];
            if(y!=cl-1)
                cout << " ";
        }
        cout << endl;
    }
    for(int x=0; x<rw; ++x)         //outputs augmented array
    {
        for(int y=0; y<cl; ++y)
        {
            cout << ar[x][y];
            if(y!=cl-1)
                cout << " ";
        }
        if(x!=rw-1)
            cout << endl;
    }    
}

int **augment(const int * const *ar, int rw, int cl)
{

    int **ag = new int *[rw]; //array created
    for(int x=0; x<rw; ++x)
        ag[x] = new int [cl];   //2d array
    
    for(int x=0; x<rw;++x)
        ag[x][0]=0;                   //makes first row all 0
    for(int x=0; x<cl;++x)
        ag[0][x]=0;                   //makes first column all 0
    
    for(int x=1; x<rw; ++x)
        for(int y=1; y<cl; ++y)
            ag[x][y]=ar[x-1][y-1];      //shifts array right and down one

    return ag;
}


void destroy(int **ar, int rw)
{
       //Destroys the array
    for(int x=0; x < rw; ++x)
        delete[] ar[x];
    delete[] ar;
}