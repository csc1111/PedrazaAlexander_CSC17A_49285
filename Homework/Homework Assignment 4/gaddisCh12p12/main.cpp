/* 
 * File: Corporate Sales Data Output modified
 * Author: Alexander Pedraza
 * Created on 10/15/2020
 * Purpose:  Quarterly sales of 4 company divisions
 */


#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//Function Prototypes
struct cds                  //corporate division sales
{
    string dvNm;            //division name
    float qSl[4];           //Quarterly sales
    float anS;              //Annual sales divisions
    float avqs;             //Average quarterly sales

};

//FUNCTIONS
void info(cds &);           //writes info into the struct variables
void prnt(const cds);       //prints to file
void prntCorp(const cds, const cds, const cds, const cds);   //corporate info
                                                             //found and printed

//Execution Begins Here
int main(int argc, char** argv) 
{
    //divisions
    fstream of;    
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
    cout << endl;
    
    prntCorp(n, w, e, s);          

    return 0;
}


void info(cds &d)
{
    d.avqs=0;
    d.anS=0;
    cout << d.dvNm << endl;
    string qrtOrder[4] = {"first", "second", "third", "fourth"};

    for(int x=0; x < 4; ++x)
    {
        cout << "Enter " << qrtOrder[x] << "-quarter sales:" << endl;
        cin >> d.qSl[x]; 
        d.anS += d.qSl[x];      //divisions annual sales found
        
        if(d.qSl[x]<0)
        {
            cout << "Sales must be a positive number. Try again: ";
            cin >> d.qSl[x];        //quarterly sales
        }
    }

    d.avqs = d.anS/4;     //calculate average
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
        of << "Quarter " << x << " sales: $";
        of << s.qSl[x-1] << endl;                 //prints quarterly sales
    }
    of << "Total annual sales: $"; 
    of << s.anS << endl;
    of << "Average quarterly sales : $";
    of << s.avqs << endl;
    
    of << endl;
    of.close();
}

void prntCorp(const cds n, const cds w, const cds e, const cds s)
{
    fstream of;
    float tyc;      //total yearly corporate sales
    float hgh;      //highest corporate quarter earnings
    int hq;        //highest corporate quarter
    float low;      //lowest corporate quarter earnings
    int lq;        //lowest corporate quarter 
    
    float qrt[4];   //total corporate sales per quarter

    for(int x=0; x<4; ++x)
        qrt[x] = n.qSl[x] + w.qSl[x] + e.qSl[x] + s.qSl[x]; //corporate quarter
                                                            //sales found
    hgh = qrt[0];
    low = qrt[0];
    
    for(int x=1; x<4; ++x)      //highest quarter found
    {
        if(hgh < qrt[x])
        {
            hgh=qrt[x];
            hq=x;
        }
    }
    for(int x=1; x<4; ++x)      //lowest quarter found
    {
        if(low > qrt[x])
        {
            low=qrt[x];
            lq=x;
        }
    }
    tyc = n.anS + w.anS + e.anS + s.anS;
    
    
    of.open("quarterly sales.txt", ios::app);   //opens file. app allows you to 
                                                //write without overwriting 
                                                //the file
    for(int x=1; x<5; ++x)
    {
        of << "Quarterly corporate sales for quarter " << x << " is: $";
        of << qrt[x-1] << endl;
    }
    of << "Total yearly corporate sales is: $" << tyc << endl;
    of << "The highest corporate quarter is quarter " << ++hq << endl;
    of << "The highest corporate quarter earned: $" << hgh << endl;
    of << "The lowest corporate quarter is quarter " << ++lq << endl;
    of << "The lowest corporate quarter earned: $" << low << endl;
    

    of.close();
}