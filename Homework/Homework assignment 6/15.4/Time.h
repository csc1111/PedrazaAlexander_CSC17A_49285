
/* 
 * File:   Time.h
 * Author: alexf
 *
 * Created on December 4, 2020, 8:46 PM
 */

#ifndef TIME_H
#define TIME_H

class Time
{
protected:
    int hour;
    int min;
    int sec;
public:
    //Default constructor
    Time()
    { hour = 0; min = 0; sec = 0;}
    
    //constructor
    Time(int h, int m, int s)
    { hour = h; min = m; sec = s;}
    
    //accessor functions
    int getHour() const
        {return hour;}
    int getMin() const
        {return min;}
    int getSec() const
        {return sec;}
};

class MilTime : public Time
{
private:
    int milHours;       //military hours
    int milSec;         //seconds
public:
    MilTime()
        {milHours = 0; milSec = 0;}
    MilTime(int, int);
    
    void setTime(int, int);
    int getMH();                //return military hour
};

MilTime::MilTime(int h, int s) : Time()
{
    setTime(h, s);
}

void MilTime::setTime(int h, int s)
{
    int t;      //temporarily holds 
    milHours=h;
    milSec=s;
    
    t=h/100;
    if(t>12)
        hour=t-12;
    else
        hour=t;
    
    min=h-t*100;
    sec=s;
}

int MilTime::getMH()
{
    return milHours;
}

#endif /* TIME_H */

