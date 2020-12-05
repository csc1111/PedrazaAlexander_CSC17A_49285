/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Created on September 30th, 2020, 7:35 PM
 */
#include <iostream>

using namespace std;

//Functions
int *getData(int &);            //Return the array size and the array from the inputs
int *sumAry(const int *,int);   //Return the array with successive sums
void prntAry(const int *,int);  //Print the array

int main()
{
    int aSz;    //array size

    int* ary=getData(aSz);      //array
    int* ssA=sumAry(ary,aSz);  //array with successive sum
    
    prntAry(ary, aSz);          //outputs array
    cout << endl;
    prntAry(ssA, aSz);         //outputs successive sum array
    
    delete[] ary;
    delete[] ssA;
    return 0;
}


int *getData(int &aSz)
{
    cin >> aSz;                 
    int *arr = new int[aSz];    //new array created

    for(int x=0; x<aSz; ++x)
        cin >> arr[x];          //input to fill array
    
    return arr;
}


int *sumAry(const int *ary,int aSz)
{
    int *sum = new int[aSz];    //successive sum array created
   
    sum[0]=ary[0];              //first element is the same on both
    
    for(int x=1; x<aSz; ++x)        //sum[x] is equal to the sum before it 
        sum[x] = sum[x-1] + ary[x]; //plus the array element ary[x]
    
    return sum;
}


void prntAry(const int *arr, int aSz)
{
    for(int x=0; x<aSz; ++x)    //outputs the array and ss array
    {
        cout << arr[x];
        if (x < aSz-1)
            cout << " ";
    }
}