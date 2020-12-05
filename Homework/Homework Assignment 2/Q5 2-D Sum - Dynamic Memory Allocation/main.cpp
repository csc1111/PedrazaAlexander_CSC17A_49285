/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Created on September 30th, 2020, 7:58 PM
 */

#include <iostream>

using namespace std;

int **getData(int &,int &);        //Return the 2-D array and its size.

void prntDat(const int* const *, int, int);//Print the 2-D Array

void destroy(int **,int,int);       //Deallocate memory

int sum(const int * const *, int, int);    //Return the Sum

int main()
{
    int rw, //rows of the 2D array
        cl; //columns of the 2D array
    
    int **tar = getData(rw, cl);
    prntDat(tar, rw, cl);
    int sm = sum(tar, rw, cl);
    cout << sm;
    
    destroy(tar, rw, cl);
    
    return 0;
}


int **getData(int &rw, int &cl)
{
    cin >> rw >> cl;
    int **ta = new int *[rw]; //array created
    for(int x=0; x<rw; ++x)
        ta[x] = new int [cl];   //2d array
                
    for(int x=0; x<rw; ++x)
        for(int y=0; y<cl; ++y)
            cin >> ta[x][y];    //input into array

    return ta;
}

void prntDat(const int* const *tar, int rw, int cl)
{
    //outputs the 2D array
    for(int x=0; x<rw; ++x)
    {
        for(int y=0; y<cl; ++y)
        {
            cout << tar[x][y];
            if(y!=cl-1)
                cout << " ";
        }
        cout << endl;
    }
}

void destroy(int **tar, int rw, int cl)
{
    //Destroys the array
    for(int x=0; x < rw; ++x)
        delete[] tar[x];
    delete[] tar;
}

int sum(const int * const *tar, int rw, int cl)
{
    int sm;
    for(int x=0; x<rw; ++x)
        for(int y=0; y<cl; ++y)
            sm += tar[x][y];    //sums up the elements in the array
    return sm;         
}