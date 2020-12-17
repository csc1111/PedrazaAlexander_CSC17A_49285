/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Final menu
 * Created on December 16, 2020, 8:26 PM
 */

#include <iostream>


using namespace std;

#include "Prob1Random.h"
#include "SavingsAccount.h"
#include "EmployeeClass.h"

/*
 * 
 */
void Prob1();
void Prob4();
void Prob5();
void Prob6();
int main(int argc, char** argv) 
{
    int chc;
    cout << "What problem would you like to view\n";
    cout << "1. Problem 1 Random sequence\n";
    cout << "4. Savings Account\n";
    cout << "5. Employee Class\n";
    cout << "6. Conversions\n";
    cin >>chc;
    
    if(chc==1)
        Prob1();
    else if(chc==4)
        Prob4();
    else if(chc==5)
        Prob5();
    else if(chc==6)
        Prob6();
    else
        "Error";

    return 0;
}

void Prob1()
{
    char n=5;
    char rndseq[]={19,34,57,79,126};
    int ntimes=100000;
    Prob1Random<char> a(n,rndseq);
    for(int i=1;i<=ntimes;i++)
    {                              
        a.randFromSet();             
    }                               
    int *x=a.getFreq();
    char *y=a.getSet();
    for(int i=0;i<n;i++)
    {
            cout<<int(y[i])<<" occured "<<x[i]<<" times"<<endl;
    }
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
}

void Prob4()
{

    SavingsAccount mine(-300);

    for(int i=1;i<=10;i++)
    {
            mine.Transaction((float)(rand()%500)*(rand()%3-1));
    }
    mine.toString();
    cout<<"Balance after 7 years given 10% interest = "
            <<mine.Total((float)(0.10),7)<<endl;
    cout<<"Balance after 7 years given 10% interest = "
            <<mine.TotalRecursive((float)(0.10),7)
            <<" Recursive Calculation "<<endl;

}

void Prob5()
{
    Employee Mark("Mark","Boss",215.50);
    Mark.setHoursWorked(-3);
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(20.0),
            Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(40.0),
            Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(60.0),
            Mark.setHoursWorked(25));
    Mark.toString();

    Employee Mary("Mary","VP",50.0);
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
            Mary.setHoursWorked(40));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
            Mary.setHoursWorked(50));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
            Mary.setHoursWorked(60));
    Mary.toString();
}

void Prob6()
{
    
}