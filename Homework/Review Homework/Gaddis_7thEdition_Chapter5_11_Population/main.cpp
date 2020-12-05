/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Created on September 5th, 2020, 6:20 PM
 * Purpose:  Calculate population increase
 *
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    
    //Declare all variables for this function
    int org;    //Starting organisms
    float inc;  //Daily population increase
    int days;   //Days organisms will multiply
    //Initialize all known variables
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    cout << "How many organisms are there?:";
    cin >> org;
    while (org<2){
        cout << "Must be more than 1 organism. Try again";
        cin >> org;
    }
    
    cout << "What is the daily population increase by percent: %";
    cin >> inc;
    while (inc < 0){
        cout << "Daily population increase must be a positive number. Try again";
        cin >> inc;
    }
    
    cout << "How many days will the organisms multiply?";
    cin >> days;
    while(days < 1){
        cout << "Number of days must be greater than 1. Try again";
        cin >> days;
    }
    
    inc *=0.01;
    for(int x=0; x<days+1; ++x){
        cout << "day " << x << "\t"  << org << endl;
        org += (org*inc); 
    }
    //Display the Inputs/Outputs

    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations