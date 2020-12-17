/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <math.h>
#include "SavingsAccount.h"
using namespace std;

SavingsAccount::SavingsAccount(float m)
{
    Balance=0;                       //Property
    FreqWithDraw=0;                  //Property
    FreqDeposit=0;                   //Property
    
}

void SavingsAccount::Transaction(float m)
{

    if(m>0)
        Balance+=Deposit(m);
    else
        Balance-=Withdraw(m);
    
}

float SavingsAccount::Total(float savint, int time)
{
    return Balance*pow((1+savint), time);
}

float SavingsAccount::TotalRecursive(float savint, int time)
{
    return Balance*pow((1+savint),time);
}

void SavingsAccount::toString()
{
    cout << "Balance="<<Balance<<endl;
    cout << "WithDraws="<<FreqWithDraw<<endl;
    cout << "Deposit="<<FreqDeposit<<endl;
}
float SavingsAccount::Withdraw(float x)               //Utility Procedure
{
    x*=-1;
    bool wd=1;
    
    try     
    {
        if(Balance<x)
            throw 99;
    }catch(int i)
    {
        cout<<"\nError "<<i<<": WithDraw not Allowed\n";
        wd=0;
    }
    if(wd)
        ++FreqWithDraw;
    else
        x=0;
    
    return x;
}
float SavingsAccount::Deposit(float x)                //Utility Procedure
{
    ++FreqDeposit;
    return x;
}