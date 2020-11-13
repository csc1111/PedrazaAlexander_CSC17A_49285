/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Purpose: Asks user for month day and year then outputs it in different forms 
 *       
 */

#include <iostream>


using namespace std;


class Date
{
    private:
        int month;      //month
        int day;        //day
        int year;       //year
    
    public:
        void setM(int); //sets month
        void setD(int); //sets day
        void setY(int); //sets year
        int prntM();    //returns month
        int prntD();    //returns day
        int prntY();    //returns year
};


int main(int argc, char** argv) {

    Date d;             //class variable
    int D, M, Y;        //integers for day, month, year
    //array string mnth used for the months in english
    string mnth[] = {"January", "February", "March", "April", "May", "June", 
                        "July", "August", "September", "October", "November", 
                        "December"};
    
    cout << "What is the day?: ";
    cin >> D;
    while(D<1 || D>31)      //day can't be less than 1 or more than 31 
    {
        cout << "Day can't be less than 1 or greater than 31. Try again: ";
        cin >> D;
    }
    
    cout << "What is the month?: ";
    cin >> M;
    while(M<1 || M>12)      //month can't be less than 1 or more than 12
    {
        cout << "Month can't be less than 1 or greater than 12. Try again: ";
        cin >> M;
    }
    
    cout << "What is the year?: ";
    cin >> Y;
    
    d.setM(M);              //assigns M to member function setM
    d.setD(D);              //assigns D to member function setD
    d.setY(Y);              //assigns Y to member function setY
    
    cout << d.prntM() << "/" << d.prntD() << "/" << d.prntY() << endl;
    cout << mnth[d.prntM()-1] << " " << d.prntD() << ", " << d.prntY() << endl;
    cout << d.prntD() << " " << mnth[d.prntM()-1] << " " << d.prntY() << endl;
    
    
    
    return 0;
}


/****************************************************************************
 *  setM                                                                    *
 *      assigns value to month                                              *
 ***************************************************************************/
void Date::setM(int m)
{
    month = m;          
}
/****************************************************************************
 *  setD                                                                    *
 *      assigns value to day                                                *
 ***************************************************************************/
void Date::setD(int d)
{
    day = d;
}
/****************************************************************************
 *  setY                                                                    *
 *      assigns value to year                                               *
 ***************************************************************************/
void Date::setY(int y)
{
    year = y;
}

/****************************************************************************
 *  prntM                                                                   *
 *      returns month                                                       *
 ***************************************************************************/
int Date::prntM()
{
    return month;
}
/****************************************************************************
 *  prntD                                                                   *
 *      returns day                                                         *
 ***************************************************************************/
int Date::prntD()
{
    return day;
}
/****************************************************************************
 *  prntY                                                                   *
 *      returns year                                                        *
 ***************************************************************************/
int Date::prntY()
{
    return year;
}
