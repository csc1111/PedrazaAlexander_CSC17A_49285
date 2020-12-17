/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "EmployeeClass.h"
#include <iostream>
#include <string.h>

using namespace std;

Employee::Employee(char n[], char t[], float h)  //Constructor
{
    for(int x=0; x<strlen(n); ++x)
        MyName[x]=n[x];
    for(int x=0; x<strlen(n); ++x)
        JobTitle[x]=t[x];
    HourlyRate=h;
    HoursWorked=0; 
    GrossPay=0;
    NetPay=0;
}

float Employee::CalculatePay(float x, int y) //Procedure
{
    NetPay=getNetPay(getGrossPay(setHourlyRate(x), setHoursWorked(y)));
    return getNetPay(getGrossPay(setHourlyRate(x), setHoursWorked(y)));
}

float Employee::getGrossPay(float p, int h)  //Procedure
{
    if(h<40)
        GrossPay=p*h;
    else if(h>40&&h<50)
    {
        GrossPay=p*h;
        GrossPay+=(p+p/2)*(h-40);
    }
    else if(h>=50)
    {
        GrossPay=p*h;
        GrossPay+=(p+p/2)*(h-40);
        GrossPay+=(p*2)*(h-49);
    }
    return GrossPay;
}

float Employee::getNetPay(float)        //Procedure
{
    return GrossPay-(GrossPay*Tax(GrossPay));
}

void Employee::toString()              //Procedure
{
    bool f=1;
    if(HoursWorked<0||HoursWorked>84)
    {
        cout << "Unacceptable Hours Worked";
        f=0;
    }
    if(HourlyRate<0||HourlyRate>200)
    {
        cout << "Unacceptable Hourly Rate";
        f=0;
    }
    if(f=0)
    {
        HourlyRate=0;
        HoursWorked=0; 
        GrossPay=0;
        NetPay=0;
    }
    cout << endl;
    cout << "Name = ";
    for(int x=0; x<strlen(MyName); ++x)
        cout << MyName[x];
    cout << " Job Title = ";
    for(int x=0; x<strlen(JobTitle); ++x)
        cout << JobTitle[x];
    cout << endl;
    cout << "Hourly Rate = " << HourlyRate;
    cout << " Hours Worked = " << HoursWorked; 
    cout << " Gross Pay = " << GrossPay;
    cout << " Net Pay = " << NetPay;
    cout << endl;
}

int Employee::setHoursWorked(int h)     //Procedure
{
    HoursWorked=h;
    return HoursWorked;
}
float Employee::setHourlyRate(float hr)    //Procedure
{
    HourlyRate=hr;
    return HourlyRate;
}

double Employee::Tax(float)
{
    double tx;
    if(GrossPay<500)
        tx=.1;
    else if(GrossPay<1000)
        tx=.2;
    else if(GrossPay>=1000)
        tx=.3;
    return tx;
}