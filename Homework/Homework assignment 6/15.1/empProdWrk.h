/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   empProdWrk.h
 * Author: Alexander Pedraza
 *
 * Created on December 3, 2020, 3:53 PM
 */

#ifndef EMPPRODWRK_H
#define EMPPRODWRK_H

class Employee
{
private:
    string eNam;    //name
    int eNum;       //employee number
    string hDat;    //Hire date
    
public:
    //Default constructor
    Employee()
    {
        eNam="0";
        eNum=0;
        hDat="0";
    };
    //constructor
    Employee(string, int, string);
    
    //set functions
    void getENam(string);
    void getENum(int);
    void getHDat(string);
    
    //accessor functions   
    string rtrnNam();
    int rtrnNum();
    string rtrnDat();
    
    
};
class prodWrk : public Employee
{
private:
    int shft;       //shift(1 or 2)
    double hpr;     //hourly pay rate
    
public:
    //Default constructor
    prodWrk()
    {
        shft=0; 
        hpr=0;  
    };
    //constructor
    prodWrk(string, int, string, int, double);
    //set functions
    void getPShft(int );
    void getHPR(double );
    
    //accessor functions    
    int rtrnShft();
    double rtrnHPR();
    
};

//***********************************************************
// Constructor for Employee.                                *
//                                                          *
//***********************************************************
Employee::Employee(string nam, int num, string dat)
{
    getENam(nam);
    getENum(num);
    getHDat(dat);
}
void Employee::getENam(string nam)
{
    eNam = nam;
}
void Employee::getENum(int num)
{
    eNum = num;
}
void Employee::getHDat(string dat)
{
    hDat = dat;
}
string Employee::rtrnNam()
{
    return eNam;
}
int Employee::rtrnNum()
{
    return eNum;
}
string Employee::rtrnDat()
{
    return hDat;
}

prodWrk::prodWrk(string nam, int num, string dat, int st, double HR) : Employee(nam, num, dat)
{
    getPShft(st);
    getHPR(HR);
}

void prodWrk::getPShft(int st)
{
    shft = st;
}
void prodWrk::getHPR(double HR)
{
    hpr = HR;
}
int prodWrk::rtrnShft()
{
    return shft;
}
double prodWrk::rtrnHPR()
{
    return hpr;
}



#endif /* EMPPRODWRK_H */

