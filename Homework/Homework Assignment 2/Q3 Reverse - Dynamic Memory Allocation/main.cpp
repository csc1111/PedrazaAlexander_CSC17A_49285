/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Created on September 30th, 2020, 6:58 PM
 */

#include <iostream>

using namespace std;

int *getData(int &);               //Fill the array

int *sort(const int *,int);         //Sort smallest to largest

int *reverse(const int *,int);      //Sort in reverse order

void prntDat(const int *,int);  //Print the array


int main()
{
    int aSz;    //array size
    
    int *ary = getData(aSz);        //array
    int *sary= sort(ary, aSz);      //sorted array
    int *rary= reverse(sary, aSz);  //reversed sorted array
    prntDat(rary, aSz);
    
    delete[] ary;
    delete[] sary;
    delete[] rary;
    
    return 0;
}

int *getData(int &aSz)
{
    //array size input
    cin >> aSz;     
    int *arr = new int[aSz];
    
    //array input
    for(int x=0; x<aSz; ++x)
        cin >> arr[x];    

    return arr;

}

int *sort(const int *ary, int aSz)
{
    bool swp;       //swap bool for bubble sort
    int temp;       //temp for bubble sort
    int *sar = new int[aSz];    //sorted array
    
    for(int x=0; x<aSz; ++x)    //sar filled by array ary
        sar[x]=ary[x];
    
    //bubble sort for the new array
    do
    {
        swp = false;
        for(int x=0; x<(aSz-1); ++x)
        {
            if(sar[x]>sar[x+1])
            {
                temp=sar[x];
                sar[x] = sar[x+1];
                sar[x+1] = temp;
                swp = true;
            }
        }
    }while(swp);

    return sar;
}

int *reverse(const int *sary, int aSz)
{
    int *rarr = new int[aSz];       //reverse array
    
    for(int x=0; x<aSz; ++x)        //reverse array is filled with sary starting
        rarr[x]=sary[aSz-x-1];      //with the largest value moving to the lowest
        
    return rarr;
}

void prntDat(const int *rary, int aSz)
{
    for(int x=0; x<aSz; ++x)
    {
        cout << rary[aSz-x-1];      //outputs the reverse array backwards
        if(x!=aSz-1)
            cout << " ";
    }
    cout << endl;

    for(int x=0; x<aSz; ++x)
    {
        cout << rary[x];            //outputs the array
        if(x!=aSz-1)
            cout << " ";            
    }
}