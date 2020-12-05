/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Created on 9/17/2020
 * Purpose:  Sorting an array of characters if specified correctly
 */

//System Libraries Here
#include <iostream>//cout,cin
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int  read(char []);
void sort(char [],int);
void print(const char [],int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;//Larger than needed
    char array[SIZE]; //Character array larger than needed
    int sizeIn,sizeDet;//Number of characters to be read, check against length
    
    //Input the size of the array you are sorting
    cout << "Read in a 1 dimensional array of characters and sort" << endl;
    cout << "Input the array size where size <= 20" << endl;
    cin >> sizeIn;
    
    //Now read in the array of characters and determine it's size
    cout<<"Now read the Array"<<endl;
    sizeDet=read(array);//Determine it's size
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size to sort
    if(sizeDet==sizeIn)
    {
        sort(array,sizeIn); //Sort the array
        print(array,sizeIn);//Print the array
    }
    else
    {
        cout<<(sizeDet<sizeIn?"Input size less than specified.":
            "Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}

/*****************************************************************************
 *read
 * reads user input into array and finds the length of the array.
 ****************************************************************************/
int read(char array[])
{
    cin.clear();
    cin.ignore();           //ignores last cin
    
    int len;                //length of array
    cin >> array;           //input array elements into array
    len = strlen(array);    //len equals the length of the array
    return len;             //returns length
}

/*****************************************************************************
 *sort
 * sorts array from greatest to least using a selection sort.
 ****************************************************************************/
void sort(char array[], int sizeIn)
{
    char start,         //start of search 
         minInd,        //minimum index
         minVal;        //minimum value
    
    for(start = 0; start < (sizeIn - 1); start++)
    {
        minInd = start;
        minVal = array[start];
        for(char index = start+1; index < sizeIn; index++)
                {
            if (array[index] < minVal)
                    {
                   minVal = array[index];
                   minInd = index;
                    }
                }
        array[minInd] = array[start];
        array[start] = minVal;
    }
}


/*****************************************************************************
 *print
 * outputs the array
 ****************************************************************************/
void print(const char array[],int sizeIn)
{
    for(int i=0; i < sizeIn; i++)
        cout << array[i];           //outputs array[i]
    cout << endl;
    
}