/* 
 * File: Corporate Sales Data Output
 * Author: Alexander Pedraza
 * Created on 10/15/2020
 * Purpose:  Quarterly sales of 4 company divisions
 */


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//Function Prototypes
struct cds                  //corprate division sales
{
    string dvNm;            //division name
    float qSl[4];           //Quarterly sales
};

//FUNCTIONS
void info(cds &);           //writes info into the struct variables
void prnt(const cds);       //prints to file

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
    cout << d.dvNm << endl;
    string qrtOrder[4] = {"first", "second", "third", "fourth"};

    for(int x=0; x < 4; ++x)
    {
        cout << "Enter " << qrtOrder[x] << "-quarter sales:" << endl;
        cin >> d.qSl[x];
        if(d.qSl[x]<0)
        {
            cout << "Sales must be a positive number. Try again: ";
            cin >> d.qSl[x];        //quarterly sales
        }
    }
    prnt(d);              //prints quarterly sales to file

}

void prnt(const cds s)
{
    fstream of;
    of.open("quarterly sales.txt", ios::app);   //opens file. app allows you to 
                                                //write without overwriting 
                                                //the file
    
    of << "Data for " << s.dvNm << endl;        //division name
    for(int x=1; x < 5; ++x)
    {
        of << "Quarter " << x << " sales: ";
        of << s.qSl[x-1] << endl;                 //prints quarterly sales
    }
    of << endl;
    of.close();
}