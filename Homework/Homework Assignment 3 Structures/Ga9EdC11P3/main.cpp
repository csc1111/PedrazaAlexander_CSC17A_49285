/* 
 * File: Ga9EdC11P3
 * Author: Alexander Pedraza
 * Created on 10/11/2020
 * Purpose:  Quarterly sales and average sales of 4 company divisions
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Function Prototypes
struct cds
{
    string dvNm;            //division name
    float qSl[4];           //Quarterly sales
    float anS;              //Annual sales
    float avqs;             //Average quarterly sales
};

//FUNCTIONS
void info(cds &);           //writes info into the struct variables
void prnt(const cds);       //outputs

//Execution Begins Here
int main(int argc, char** argv) 
{
    //divisions
    cds n = {"North"};
    cds w = {"West"};
    cds e = {"East"};
    cds s = {"South"};


    info(n);            //north
    cout << endl;
    info(w);            //west
    cout << endl;
    info(e);            //east
    cout << endl;
    info(s);            //south



    return 0;
}


void info(cds &d)
{
    d.anS = 0;
    d.avqs = 0;
    cout << d.dvNm << endl;
    string qrtOrder[4] = {"first", "second", "third", "fourth"};


    for(int x=0; x < 4; ++x)
    {
        cout << "Enter " << qrtOrder[x] << "-quarter sales:" << endl;
        cin >> d.qSl[x];
        d.anS += d.qSl[x];
    }

    d.avqs = d.anS/4;     //calculate average
    prnt(d);              //prints total annual sales and average quarterly
                          //sales
}

void prnt(const cds s)
{
    cout << "Total Annual sales:$" << fixed << setprecision(2) << s.anS << endl;
    cout << "Average Quarterly Sales:$" << fixed << setprecision(2) << s.avqs;
}