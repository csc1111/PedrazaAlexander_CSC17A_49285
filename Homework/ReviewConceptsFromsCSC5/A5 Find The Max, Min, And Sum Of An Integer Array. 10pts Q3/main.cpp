/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Created on 9/17/2020
 * Purpose:  Summing, Finding the Max and Min of an integer array
 * Note:  Look at the output for the format for print
 */

//System Libraries Here
#include <iostream>//cin,cout
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables

//Function Prototypes Here
void read(int [],int);
int  stat(const int [],int,int &,int &);
void print(const int [],int,int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;
    int array[SIZE];
    int sizeIn,sum,min,max;
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of integers find sum/min/max"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of integers
    cout<<"Now read the Array"<<endl;
    read(array,sizeIn);//Read in the array of integers
    
    //Find the sum, max, and min
    sum=stat(array,sizeIn,max,min);//Output the sum, max and min
    
    //Print the results
    print(array,sizeIn,sum,max,min);//print the array, sum, max and min

    //Exit
    return 0;
}

/*****************************************************************************
 *read
 * Reads user input into array.
 ****************************************************************************/
void read(int array[], int sizeIn)
{
    for(int i=0; i < sizeIn; ++i)   //loops till array is filled
        cin >> array[i];            //user inputs number into array
}

/*****************************************************************************
 *stat
 * Finds the largest and the smallest value in an array. Also finds sum of all
 * numbers in the array.
 ****************************************************************************/
int stat(const int array[], int sizeIn, int& max, int& min)
{
    int sum=0;          //Sum of all numbers in array
    max = array[0];     //Greatest number in array
    min = array[0];     //Smallest number in array
    
    for(int i=0; i < sizeIn; ++i)   //loops till end of array
    {
        if (array[i]>max)           //if the number in array[i] is greater than        
            max = array[i];         //variable max then max becomes array[i]
    }
    
    for(int i=0; i < sizeIn; ++i)   //loops till end of array
    {
        if (array[i]<min)           //if array[i] is less than variable min,
            min = array[i];         //min becomes array[i]
    }
    
    for(int i=0; i < sizeIn; ++i)   //loops till end of array
        sum += array[i];            //adds up the sum and array
    return sum;
}

/*****************************************************************************
 *print
 * Outputs the max. min and sum of the array.
 ****************************************************************************/
void print(const int array[], int sizeIn, int sum, int max, int min)
{
    for(int i=0; i < sizeIn; ++i)
    {
        cout << "a[" << i << "] = ";
        cout << array[i] << endl;           //outputs array in the order it was
    }                                       //placed
    
    cout << "Min  = " << min << endl;       //outputs min
    cout << "Max  = " << max << endl;       //outputs max
    cout << "Sum  = " << sum << endl;       //outputs sum
}