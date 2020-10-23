/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Purpose: determines the balance of a persons bank account after checks are 
 *         written and deposits are made. If they spent too much they get charged
 */

#include <iostream>


using namespace std;

struct cstmr         //Customer info
{
    string nam;      //Customer name
    string adrs;     //Address
    int actn;        //Account number
    float bbeg;      //Balance at the beginning of the month
    float blnc;      //Balance at the beginning of month
    float chk;       //Checks written
    float deps;      //Deposits made by customer
};

void fillArr(cstmr &);
void output(cstmr );

int main(int argc, char** argv) 
{
    cstmr usr;          //user's struct
    
    fillArr(usr);
    
    return 0;
}

void fillArr(cstmr &u)
{
    int x=1;                //used to determine check values, deposits made and
                            //when to exit a while loop.
    cout << "Please enter your name: ";
    getline(cin, u.nam);
    cout << "Please enter your address: ";
    getline(cin, u.adrs);
    cout << "Enter account number: ";
    cin >> u.actn;
    cout << "Enter your balance at the beginning of the month: $";
    cin >> u.bbeg;
    u.blnc = u.bbeg;        //balance at beginning of month remains the same
    u.deps=0;               //balance changes 
    u.chk=0;
    
    cout << "Enter checks written this month (input 0 if done): $";
    while(x!=0)
    {
        cin >> x;
        u.chk+=x;           //every check amount is counted up
        u.blnc-=x;          //balance is dropped by check amount
    }
    
    x=1;
    cout << "Enter deposits made this month (input 0 if done): $";
    while(x!=0)
    {
        cin >> x;
        u.deps+=x;          //deposits made added up
        u.blnc+=x;          //balance is increased by deposits
    }
    
    if (u.blnc<0)           //if user went under balance they are charged $20
        u.blnc-=20;
    output(u);
}

void output(cstmr u)
{
    cout << "Name: "<< u.nam << endl;
    cout << "Address: " << u.adrs << endl;
    cout << "Account Number: " << u.actn << endl;
    cout << "Balance at the beginning of the month: $" << u.bbeg << endl;
    cout << "Total checks written: $" << u.chk << endl;
    cout << "Total deposits made: $" << u.deps << endl;
    if(u.blnc<0)    //when user is charged extra for going under they are told
        cout << "Your account was overdrawn. Extra $20 charge."<<endl;
    cout << "Total balance: $" << u.blnc;
}
