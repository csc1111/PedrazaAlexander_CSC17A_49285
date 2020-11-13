/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Purpose: Outputs day of the year in the format, January 25.
 *   
 */

#include <iostream>

using namespace std;

class dOy
{
    private: 
        static string mnth[12]; //month in english
        int day;                //day chosen by user

    public:
        dOy(int);               //constructor excepts day
        void setDay(int);       //sets day
        void print();           //prints the month and date
    
};

string dOy::mnth[12] = {"January ", "February ", "March ", "April ", "May ",    //defines and fills mnth array.
                        "June ", "July ", "August ", "September ", "October ",
                        "November ", "December "};

int main(int argc, char** argv) 
{
    int n;      //holds day
    cout << "Enter a day of the year: ";
    cin >> n;
    
    dOy d(n);
    
    d.print();

    return 0;
}

/*****************************************************************************
 *  constructor dOy
 *      when a dOy variable is created this runs. It calls the function setDay
 *  as well.
 *****************************************************************************/
dOy::dOy(int n)
{
    setDay(n);
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
 *  print
 *      Prints the day in the form month day.
 *****************************************************************************/
void dOy::print()
{    
    //if splits it in half so that it won't take so long for larger numbers
    if(day<=181)
    {
        //if its less than 31(days in jan) it will output the mnth[] and day
        if(day<=31)                 //Jan
            cout << mnth[0] << day;
        else if(day<=59)            //Feb   //for bigger numbers it tests that 
            cout << mnth[1] << day-31;      //day is equal to or less than the 
        else if(day<=90)            //mar   //number of days in a month as well
            cout << mnth[2] << day-59;      //as the previous month
        else if(day<=120)           //April //Also the previous months must be
            cout << mnth[3] << day-90;      //removed from day to get the 
        else if(day<=151)           //may   //correct number
            cout << mnth[4] << day-120;
        else if(day<=181)           //June
            cout << mnth[5] << day-151;
    }
    else
    {
        if(day<=212)                //July
            cout << mnth[6] << day-181;
        else if(day<=243)           //August
            cout << mnth[7] << day-212;
        else if(day<=273)           //September
            cout << mnth[8] << day-243;
        else if(day<=304)           //October
            cout << mnth[9] << day-273;
        else if(day<=334)           //November
            cout << mnth[10] << day-304;
        else                        //December
            cout << mnth[11] << day-334;
    }
}