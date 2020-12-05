/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Created on September 5th, 2020, 4:48 PM
 * Purpose:  Calculate the property tax of a property
 *
 */

//System Libraries
#include <iostream>  //I/O Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    
    //Declare all variables for this function
    float pval;     //Property value
    float aval;     //Assessment value (60% of property value)
    float ptax;     //Property tax (64 cents per 100$ of assessment value)
    //Initialize all known variables
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    cout << "Enter property value: $";
    cin >> pval;
    
    aval = pval * 0.6;      //Formula for assessment value 
    ptax = aval * 0.0064;   //Formula for property tax 
    
    //Display the Inputs/Outputs
    cout << "Assessment value:\t$" << setprecision(2) << fixed << aval << endl;
    cout << "Property tax:\t\t$" << setprecision(2) << fixed << ptax << endl;
    
    
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations