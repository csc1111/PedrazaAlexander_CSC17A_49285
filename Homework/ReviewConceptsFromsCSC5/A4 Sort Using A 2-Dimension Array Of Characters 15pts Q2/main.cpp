/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Created on 9/17/2020
 * Purpose:  Sorting a 2-D array of characters if row and columns match
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int);//Sort by row
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    
    //Input the size of the array you are sorting
    cout << "Read in a 2 dimensional array of characters and sort by Row" << endl;
    cout << "Input the number of rows <= 20" << endl;
    cin >> rowIn;
    cout << "Input the maximum number of columns <=20" << endl;
    cin >> colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet = rowIn;
    cout << "Now input the array." << endl;
    colDet = read(array,rowDet);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    }else{             
        if(rowDet!=rowIn)
        cout<<(rowDet<rowIn?"Row Input size less than specified.":
            "Row Input size greater than specified.")<<endl;
        if(colDet!=colIn)
        cout<<(colDet<colIn?"Column Input size less than specified.":
            "Column Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}

/*****************************************************************************
 *read
 * reads user input into 2 dimensional char array and determines if user
 * exceeded row limit. It returns the length of the array in order to compare
 * its columns to the user inputted number of columns for input validation in 
 * main.
 *****************************************************************************/
int read(char array[][COLMAX], int& rowDet)
{
    cin.clear();        
    cin.ignore();       //ignores last input
    
    int len;            //length of the array
    int rowC=0;         //count of rows used
    char arr[COLMAX];   //holds any user input that exceeds specified row limit
    
    for(int i = 0; i < rowDet; ++i)
    {
        cin.getline (array[i], COLMAX);     //writes user input into array
        cin.clear();
        ++rowC;                             //increments row count
    }

    cin.getline (arr,COLMAX);           //accepts numbers exceeding row limit
    
    if (strlen(arr)!=0)                 //if row limit is exceeded row count
        ++rowC;                         //is incremented 
    
    len = strlen(array[0]);             //len is equal to length of array[0]
    
    for(int i=0; i < rowDet; ++i)       //loops through all rows in array
    {
        if (len < strlen(array[i]))     //if len is smaller than the strlen of
            len = strlen(array[i]);     //array[i] then len becomes it
    }
    rowDet=rowC;                        //rowDet becomes rowC
      
    return len;                         //returns the length of the biggest array
}

/*****************************************************************************
 *sort
 * sorts the array from greatest to least by row. It uses nested for loop and
 * strcmp to compare the array rows to the others.
 *****************************************************************************/
void sort(char array[][COLMAX], int rowIn, int colIn)
{
    char *temp[COLMAX];                        //temporarily holds row for array
    for(int i = 0; i < rowIn; ++i)
    {
        for(int j = i + 1; j < rowIn; ++j)
        {
            if(strcmp(array[i],array[j]) > 0)
            {
                strcpy(temp[COLMAX], array[i]);
                strcpy(array[i], array[j]);
                strcpy(array[j], temp[COLMAX]);
            }
        }
    }
}

/*****************************************************************************
 *print
 * outputs array using a for loop.
 *****************************************************************************/
void print(const char array[][COLMAX], int rowIn, int colIn)
{
    for (int i = 0; i < rowIn; ++i)     //outputs array in order
    {
        cout << array[i];               //outputs array[i]
        cout << endl;
    }
}