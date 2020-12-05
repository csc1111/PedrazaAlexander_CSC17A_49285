/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Created on September 7th, 2020, 7:10 PM
 * Purpose: Search using binary string
 *     
 */

//System Libraries
#include <iostream>  //I/O Library
#include <string>
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
void sort(string[], int);               //sorts the string array with bubble sort
int search(string[], string, int);      //searches for name
//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    
    //Declare all variables for this function
    string usn;                 //users name
    int fnd;                    //found
    //Initialize all known variables
    const int NUM_NAMES = 20;   //number of names
    string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                               "Griffin, Jim", "Stamey, Marty", "Rose, Geri", 
                               "Taylor, Terri", "Johnson, Jill", 
                               "Allison, Jeff", "Looney, Joe", "Wolfe, Bill", 
                               "James, Jean", "Weaver, Jim", "Pore, Bob", 
                               "Rutherford, Greg", "Javens, Renee", 
                               "Harrison, Rose", "Setzer, Cathy",
                               "Pike, Gordon", "Holland, Beth" };


    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives

    sort(names, NUM_NAMES);                 // sort function
    cout << "Enter a Name to search:";
    getline(cin, usn);
    
    fnd = search(names, usn, NUM_NAMES);    //Binary search
    
    //Display the Inputs/Outputs
    if (fnd=1)
        cout << "name found!";
    else
        cout << "name not found :(";
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations


void sort(string names[], int NUM_NAMES)
{                    
    string temp;
    for(int i=1; i<NUM_NAMES ;i++ )
        {
            for( int j=0; j<(NUM_NAMES-1) ; j++)
            {
                if(names[j] > names[j+1])
                {

                    temp = names[j];
                    names[j] = names[j+1];
                    names[j+1] = temp;
                }
            }
        }
    }

int search(string names[], string usn, int NUM_NAMES)
{
    int f = 0,                 // First name in array
        l = NUM_NAMES-1,       // Last name in array
        mid;                   // Middle name in array
    bool found = false;        // Flag

    while (!found && f <= l)
    {
        mid = (f + l) / 2;     // Calculate mid point
        if (names[mid] == usn)      // If value is found at mid
        {
            found = true;
        }
        else if (names[mid] > usn)  // If value is in lower half
            l = mid - 1;
        else
            f = mid + 1;           // If value is in upper half
    }
    return found;
}


