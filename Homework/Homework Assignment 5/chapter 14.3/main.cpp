/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Purpose: Outputs day of the year in the format, January 25. Also increments 
 *  and decrements day post and prefix
 */

#include <iostream>

using namespace std;

class dOy
{
    private: 
        static string mnth[12];      //month in english
        static int md[12];           //month days        
        int day;                     //day chosen by user
        int mo;                      //month number


    public:
        dOy(int, string);       //constructor excepts day
        void setDay(int);       //sets day
        void setMnth(string);   //sets month
        void print();           //prints the month and date
        void inc();             //increments month if needed
        void dec();             //decrements month if needed
        dOy operator++();       //postfix increment
        dOy operator++(int);    //prefix increment
        dOy operator--();       //postfix decrement
        dOy operator--(int);    //prefix decrement

        
    
};


string dOy::mnth[12] = {"January", "February", "March", "April", "May",    //defines and fills mnth array.
                        "June", "July", "August", "September", "October",
                        "November", "December"};
int dOy::md[12] = {31,28,31,30,31,30,31,31,30,31,30,31};        //sets days in a month

int main(int argc, char** argv) 
{
    int n;      //holds day
    string mnth;    //holds month
    cout << "Enter a day of the year: ";
    cin >> n;
    cout << "Enter a month: ";
    cin >> mnth;
    
    dOy d(n, mnth);
    d.print();
    
    cout << "postfix increment: ";
    d++; 
    d.print();
    cout << "prefix increment: ";
    ++d;
    d.print();
    cout << "postfix decrement: ";
    d--;
    d.print();
    cout << "prefix increment: ";
    --d;
    d.print();

    return 0;
}

/*****************************************************************************
 *  constructor dOy
 *      when a dOy variable is created this runs. It calls the function setDay
 *  as well.
 *****************************************************************************/
dOy::dOy(int n, string m)
{
    setMnth(m);
    setDay(n);
    if(n<1||n>md[mo])
        cout << "ERROR. Number not within the months range\n";
}

/*****************************************************************************
 *  setDay
 *      Sets the day to the number given by user.
 *****************************************************************************/
void dOy::setDay(int n)
{
    day=n;
}
/*****************************************************************************
 *  setMnth
 *      Sets the month by comparing it to an array with months in it
 *****************************************************************************/
void dOy::setMnth(string m)
{
    for(int x=0; x<12; ++x)
    {
        if(m==mnth[x])
        {
            mo=x;
            x+=12;
        }
    }
}
/*****************************************************************************
 *  inc
 *      Increments the month and sets day to 0 if day can't be incremented 
 * further. If its the last day of the year it makes month 0. 
 *****************************************************************************/
void dOy::inc()
{
    if(mo==11 && day==31)
    {
        mo=0;
        day=0;
    }
    else if(day==md[mo])
    {
        ++mo;
        day=0;
    }
}
/*****************************************************************************
 *  dec
 *      decrements the month and sets day to 31 if day can't be decremented 
 * further. If its the first day of the year it makes month 11. 
 *****************************************************************************/
void dOy::dec()
{
    if(mo==0 && day==0)
    {
        mo=11;
        day=31;
    }
    else if(day==0)
    {
        --mo;
        day=0;
    }
}

dOy dOy::operator++()       //prefix increment
{
    inc();
    ++day;
    return *this;
}
dOy dOy::operator++(int)    //postfix increment
{
    dOy temp = *this;
    inc();
    day++;
    return temp;
}
dOy dOy::operator--()       //prefix decrement
{
    dec();
    --day;
    return *this;
}
dOy dOy::operator--(int)    //postfix decrement
{
    dOy temp = *this;
    dec();
    day--;
    return temp;
}

/*****************************************************************************
 *  print
 *      Prints the day in the form month day.
 *****************************************************************************/
void dOy::print()
{    
    cout << mnth[mo] << " " << day;
    cout << endl;
}