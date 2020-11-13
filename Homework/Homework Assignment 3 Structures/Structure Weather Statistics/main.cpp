/* 
 * File: Structure Weather Statistics
 * Author: Alexander Pedraza
 * Created on 10/11/2020
 * Purpose:  stores weather data
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;



struct rainFall
{
    //
    string mnth;    //month
    float trf;      //total rainfall
    float htmp;     //highest temperature
    float ltmp;     //lowest temperature
    float atmp;     //average temperature
};

void write(rainFall *, int);    //writes into array
void print(rainFall *, float, float, float, float, int, int); //outputs

//Execution Begins Here
int main(int argc, char** argv) 
{

    
    int m = 12;         //months
    float amrf;         //average monthly rainfall
    float hTemp;        //highest temperature
    int hmth = 0;       //highest temperature position in array
    float lTemp;        //lowest temperature
    int lmth = 0;       //lowest temperature position in array
    float aTemp;        //average temperature
    rainFall rd[m];     //rainfall array

    
    for(int x=0; x<m; ++x)
        write(rd, x);
    
    for(int x=0; x<m; ++x)
        amrf += rd[x].trf;  //average monthly rainfall added up
    amrf /= m;              //average monthly rainfall divided and found
   
    
        
    hTemp = rd[0].htmp;
    lTemp = rd[0].ltmp;
    

    
    for(int x=1; x<m; ++x)
    {
        if(rd[x].htmp > hTemp)
        {
            hTemp = rd[x].htmp; //highest temperature found
            hmth = x;           //its positions saved
        }
    }
        
    for(int x=1; x<m; ++x)
    {
        if(rd[x].ltmp < lTemp)
        {
            lTemp = rd[x].ltmp; //lowest temperature found
            lmth = x;           //its position saved
        }
    }
    
    for(int x=0; x<m; ++x)
        aTemp += rd[x].atmp;    //average temperature added up
    aTemp /= m;                 //average temperature divided
    
    print(rd, amrf, hTemp, lTemp, aTemp, hmth, lmth);
    return 0;
}

void write(rainFall *r, int x)
{
    r[x].atmp = 0;
    
    cin >> r[x].mnth;

    cin >> r[x].trf;
    
    cin >> r[x].ltmp;
    
    cin >> r[x].htmp;
    r[x].atmp = (r[x].ltmp + r[x].htmp)/2;  //calculates average temp
    
}



void print(rainFall *r, float ar, float h, float l, float at, int hm, int lm)
{
    //rounds to nearest decimal
    cout << "Average Rainfall " << round(ar*10)/10 << " inches/month" << endl;
    cout << "Lowest  Temperature " << r[lm].mnth << "  " << l << " Degrees Fahrenheit" << endl;
    cout << "Highest Temperature " << r[hm].mnth << "  " << h << " Degrees Fahrenheit" << endl;
    cout << "Average Temperature for the year " << round(at) << " Degrees Fahrenheit\n";
}