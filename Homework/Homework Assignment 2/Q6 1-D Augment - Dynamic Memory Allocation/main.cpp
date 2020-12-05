/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Created on September 30th, 2020, 8:48 PM
 */

#include <iostream>

using namespace std;

//Functions
int *getData(int &);//Read the array

int *augment(const int *,int);//Augment and copy the original array

void prntAry(const int *,int);//Print the array

int main()
{
    //Variables
    int aSz;        //array size

    int *ary = getData(aSz);        //input array
    prntAry(ary, aSz);          //outputs array
    cout << endl;

    ++aSz;                      //array incremented for augmented array
    int *aug = augment(ary,aSz);    //augment array
    prntAry(aug, aSz);          //outputs augmented array
    
    delete[] ary;               //deallocates memory
    delete[] aug;
    return 0;
}


int *getData(int &aSz)
{
    cin >> aSz;         //array size

    int *arr = new int[aSz];
    
    for(int x=0; x<aSz; ++x)
        cin >> arr[x];

    return arr;

}

int *augment(const int *ary,int aSz)
{

    int *aug = new int[aSz];
    
    aug[0]=0;                   //first element becomes 0
    for(int x=1; x<aSz; ++x)
        aug[x]=ary[x-1];        //aug[x] is equal to ary[x-1], shifting the array

    return aug;
}


void prntAry(const int *ar,int aSz)
{    
    //outputs the array
    for(int x=0; x < aSz; ++x)
    {
        cout << ar[x];
        if (x < aSz-1)
            cout << " ";
    }
}