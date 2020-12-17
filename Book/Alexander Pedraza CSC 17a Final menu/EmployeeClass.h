/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EmployeeClass.h
 * Author: Alexander Pedraza
 *
 * Created on December 16, 2020, 8:35 PM
 */

#ifndef EMPLOYEECLASS_H
#define EMPLOYEECLASS_H

#include <iostream>
using namespace std;


class Employee
{
    public:
        Employee(char[],char[],float);  //Constructor
        float  CalculatePay(float,int); //Procedure
        float  getGrossPay(float,int);  //Procedure
        float  getNetPay(float);        //Procedure
        void   toString();              //Procedure
        int    setHoursWorked(int);     //Procedure
        float  setHourlyRate(float);    //Procedure
    private:
        double Tax(float);      //Utility Procedure
        char   MyName[20];      //Property
        char   JobTitle[20];    //Property
        float  HourlyRate;      //Property
        int    HoursWorked;     //Property
        float  GrossPay;        //Property
        float  NetPay;          //Property
};
#endif /* EMPLOYEECLASS_H */

