/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alexf
 *
 * Created on December 4, 2020, 3:03 PM
 * Purpose: Make a derived class from class Time(provided by book). Change 
 * military time to normal.
 */
#include <iomanip>
#include <iostream>

using namespace std;

#include "Time.h"
/*
 * 
 */
int main(int argc, char** argv) 
{
    int hr;         //Military hour and minute
    int sec;        //second
    cout << "Enter the hour and minute in military time(0000-2359): ";
    cin >> hr;
    while(hr<0||hr>2359)
    {
        cout << "Error time must be less than 2359 and more than 0 try again: ";
        cin >> hr;
    }
    cout << "Enter the seconds: ";
    cin >> sec;
    while(sec<0||sec>59)
    {
        cout << "ERROR. Seconds can't be more than 59 or less than 0 try again: ";
        cin >> sec;
    }
    MilTime tim(hr, sec);
    
    cout << tim.getHour() << ":" << tim.getMin() << endl;
    cout << tim.getMH();
    
    return 0;
}

