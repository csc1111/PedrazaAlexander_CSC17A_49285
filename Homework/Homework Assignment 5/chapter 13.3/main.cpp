/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Purpose: Gets a cars year model and make then calculates the speed after it
 *          accelerates. It then gets the speed as it brakes.
 */

#include <iostream>

using namespace std;

class car
{
private:
    int yModl;              //year model
    string mk;              //make
    int spd;                //speed
public:
    car(int, string, int);
    void setYModl(int);
    void setMk(string);
    void acc(int);
    void brk(int);
    void setSpd(int);
    
    int getYModl();
    string getMk();
    int getSpd();
};


int main(int argc, char** argv) 
{
    int a=5;     //accelerate
    int b=-5;    //brake
    int y;       //year model
    string m;    //make
    
    cout << "What is the cars year model?: ";
    cin >> y;
    cout << "What is the make?: ";
    cin.ignore();
    getline(cin, m);
    
    car vroom(y, m, 0);
    cout << vroom.getYModl() << endl;
    cout << vroom.getMk() << endl;
    
    cout << "Accelerate.\n";
    for(int x=0; x<5; ++x)
    {
        vroom.acc(a);
        cout << vroom.getSpd() << endl;
    }
    cout << "Brake.\n";
    for(int x=0; x<5; ++x)
    {
        vroom.brk(b);
        cout << vroom.getSpd() << endl;
    }   
    return 0;
}


car::car(int y, string m, int s)
{
    setYModl(y);
    setMk(m);
    setSpd(s);
}

void car::setYModl(int y)
{
    yModl=y;
}
void car::setMk(string m)
{
    mk=m;
}
void car::acc(int a)
{
    setSpd(a);
}
void car::brk(int b)
{
    setSpd(b);
}
void car::setSpd(int s)
{
    spd+=s;
}

int car::getYModl()
{
    return yModl;
}
string car::getMk()
{
    return mk;
}
int car::getSpd()
{
    return spd;
}

