/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Created on September 5th, 2020, 3:51 PM
 * Purpose:  Calculate monthly sales tax
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
    string mnth;    //The month
    int yr;         //The year
    double cash;     //Total amount of money in register
    float ctax;     //County tax
    float stax;     //State tax
    float psal;     //Product sales (before tax total)
    float ttax;     //Total sales tax
    //Initialize all known variables
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    cout << "Please enter the month: ";
    cin >> mnth;
    cout << "Please enter the year: ";
    cin >> yr;
    cout << "Enter total amount of money found in the register: $";
    cin >> cash;
    
    psal = cash/1.06;    //formula to find product sales
    stax = psal * 0.04;  //formula to find sales tax
    ctax = psal * 0.02;  //formula to find county tax
    ttax = cash - psal;  //formula to find total sales tax
    
    //Display the Inputs/Outputs    
    cout << "Month: " << mnth << endl;
    cout << "-------------------"<< endl;
    cout << "Total Collected:\t$" << setw(9) << setprecision(2) << fixed << cash << endl;
    cout << "Sales:\t\t\t$" << setw(9) << setprecision(2) << fixed << psal << endl;
    cout << "County Sales Tax:\t$" << setw(9) << setprecision(2) << fixed << ctax << endl;
    cout << "State Sales Tax:\t$" << setw(9) << setprecision(2) << fixed << stax << endl;
    cout << "Total Sales Tax:\t$" << setw(9) << setprecision(2) << fixed << ttax <<endl;
    


    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations