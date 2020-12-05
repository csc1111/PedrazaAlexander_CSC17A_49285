/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Created on September 30th, 2020, 6:00 PM
 */

int *getData(int &);         //Return the array size and the array

void prntDat(int *,int);    //Print the integer array

float *median(int *,int);  //Fill the median Array with the Float array size, the median, and the integer array data

void prntMed(float *);     //Print the median Array

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int aSz;            //size of the array
  
    int *ary = getData(aSz);
    prntDat(ary, aSz);
    float *far = median(ary, aSz);
    prntMed(far);
    
    delete[]far;
    delete[]ary;
    return 0;
}

int *getData(int &aSz)
{
    cin >> aSz;
    int *array = new int [aSz]; //creates new array
    for(int x=0; x<aSz; ++x)
        cin >> array[x];
    return array;
}

void prntDat(int *ary, int aSz)
{
    //outputs the unsorted array
    cout << ary[0];
    for(int x=1; x < aSz; ++x)
        cout << " " << ary[x];
    cout << endl;
}

float *median(int *ary, int aSz)
{
    float *fary = new float [aSz+2];    //new float array 
    int med1,   //first medium number position
        med2;   //second medium number position
    float med3; //median number
    bool swp;   //bool for bubble sort
    int temp;   //temporary int for bubble sort
    
    
    fary[0] = aSz+2;    //first element of array is array size
    
    for(int x=0; x < aSz; ++x)  //float array is filled with unsorted array ary
        fary[x+2] = ary[x];     //starting at element 2
    
    //Bubble sort
    //In order to find median the array must be sorted in order
    do
    {
        swp = false;
        for(int x=0; x<(aSz-1); ++x)
        {
            if(ary[x]>ary[x+1])
            {
                temp=ary[x];
                ary[x] = ary[x+1];
                ary[x+1] = temp;
                swp = true;
            }
        }
    } while(swp);
    
    
    if(aSz%2 == 0)              //if the median two number
    {
        med1 = aSz/2 - .5;      //first median position found by subtracting .5
        med2 = aSz/2 + .5;      //from size divided by two and median 2 is found 
                                //by adding
        med3 = (ary[med1] + ary[med2]); //med3 equals the two middle numbers added
        med3 = med3 / 2;        //average is found by dividing by 2
        fary[1] = med3;
    }
    else                        //if median is one number
    {
        fary[1] = ary[aSz/2];   //the middle number is the median
    }
    
    return fary;
}

void prntMed(float *far)
{
    //outputs array size, median number and the float array
    cout << far[0];
    for(int x=1; x<far[0]; ++x)
        cout << " " << setprecision(2) << fixed << far[x];
}