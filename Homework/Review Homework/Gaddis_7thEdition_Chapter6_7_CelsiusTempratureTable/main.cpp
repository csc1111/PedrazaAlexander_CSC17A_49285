/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Created on September 5th, 2020, 5:04 PM
 * Purpose: Create a table from 0 to 20 degrees Fahrenheit with Celsius 
 * conversion
 *          
 */

//System Libraries
#include <iostream>  //I/O Library
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
float celsius(float F);
//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    
    //Declare all variables for this function
    float C;  //Celsius
    float F;  //Fahrenheit
    
    //Initialize all known variables
    int min = 0;    //Lowest temperature
    int max = 20;   //Highest temperature
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    
    //Display the Inputs/Outputs
    cout << "___________________________________" << endl;
    cout << "Fahrenheit     | Celsius           " << endl;
    cout << "___________________________________" << endl;
    
    for (F = min; F <= max; ++F){
        C = celsius(F);
        cout << F << "\t\t";
        cout << C << endl;
    }
    
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

/******************************************************************************
 * Celsius 
 *  This function converts Fahrenheit to Celsius.
 ******************************************************************************/

float celsius(float F){
    float C;
    C = 5.0/9 * (F-32);
    return C;
}