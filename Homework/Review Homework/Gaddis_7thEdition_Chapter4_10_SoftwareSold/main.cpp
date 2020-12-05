/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Created on September 5th, 2020, 4:51 PM
 * Purpose:  Calculate 
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
    int ssld;       //Software sold
    int cst;        //Cost before discount($99 per package)
    float tcst;     //Total cost
    
    //Initialize all known variables
    int sprc = 99;  //Price for software package without discount
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    cout << "Enter quantity of software packages sold: ";
    cin >> ssld;
    
    while(ssld <= 0){
        cout << "Quantity must be greater than 0. Try again: ";
        cin >> ssld;
    }
    
    cst = ssld *99;     
    
    if (ssld > 9 && ssld < 20)
        tcst = cst-(cst*0.2);
    else if (ssld > 19 && ssld < 50)
        tcst = cst-(cst*0.3);
    else if (ssld > 49 && ssld < 100)
        tcst = cst-(cst*0.4);
    else if (ssld > 99)
        tcst = cst-(cst*0.5);
    else
        tcst = cst;
    
    //Display the Inputs/Outputs
    cout << "Total cost after discount: $";
    cout << setprecision(2) << fixed <<  tcst;
    
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right
    return 0;
}

//Function Implementations