
/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Created on December 3, 2020, 3:46 PM
 * Purpose: get an employees name, number and hire date in a class then their 
 * shift and hourly pay in a derived class
 */

#include <iostream>

using namespace std;

#include "empProdWrk.h"

void output(prodWrk);

int main(int argc, char** argv) 
{
    string nam;     //Name
    int num;        //Number
    string hdat;    //Hire date
    int shft;       //Shift
    double hpr;     //Hourly pay
    
    cout << "Enter Employee name: ";
    getline(cin, nam);
    cout << "Enter Employee number: ";
    cin >> num;
    cin.ignore();
    cout << "Enter hire date: ";
    getline(cin, hdat);
    cout << "Enter shift number: ";
    cin >> shft;
    cout << "Enter hourly pay: ";
    cin >> hpr;
    
    prodWrk emp (nam, num, hdat, shft, hpr);
    output(emp);
    
    return 0;
}

void output(prodWrk emp)
{
    cout << "\nName: " << emp.rtrnNam() << endl;
    cout << "Employee Number: " << emp.rtrnNum() << endl;
    cout << "Hire date: " << emp.rtrnDat() << endl;
    cout << "Shift Number: " << emp.rtrnShft() << endl;
    cout << "Hourly Pay: $" << emp.rtrnHPR() << endl;
}