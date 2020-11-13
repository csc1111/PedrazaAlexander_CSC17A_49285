/* 
 * File: Ga9EdC11P3
 * Author: Alexander Pedraza
 * Created on 10/11/2020
 * Purpose:  rainfall
 */
//System Libraries
#include <iostream>
using namespace std;


struct rainFall
{

    float trf;          //total rainfall
    float htmp;         //highest temperature
    float ltmp;         //lowest temperature
    float atmp;         //average temperature
};

void write(rainFall *, int);
void print(float, float, float, float);

//Execution Begins Here
int main(int argc, char** argv) 
{
    //Set Random Number seed

    //Declare Variable Data Types and Constants
    int m = 6;
    float amrf;     //average rainfall
    float hTemp;    //highest temperature
    float lTemp;    //lowest temperature
    float aTemp;    //average temperature
    rainFall rd[m];   
    //Initialize Variables
    
    //Process or map Inputs to Outputs
    for(int x=0; x<m; ++x)
        write(rd, x);
    
    for(int x=0; x<m; ++x)
        amrf += rd[x].trf;
    amrf /= m;
   
    
        
    hTemp = rd[0].htmp;
    lTemp = rd[0].ltmp;
    

    
    for(int x=1; x<m; ++x)
    {
        if(rd[x].htmp > hTemp)
        {
            hTemp = rd[x].htmp;
        }
    }
        
    for(int x=1; x<m; ++x)
    {
        if(rd[x].ltmp < lTemp)
        {
            lTemp = rd[x].ltmp;
        }
    }
    
    for(int x=0; x<m; ++x)
        aTemp += rd[x].atmp;
    aTemp /= m;
    
    print(amrf, hTemp, lTemp, aTemp);
    //Display Outputs

    //Exit stage right!
    return 0;
}

void write(rainFall *r, int x)
{
    r[x].atmp = 0;
    
    cout << "Enter the total rainfall for the month:" << endl;
    cin >> r[x].trf;
    cout << "Enter the high temp:" << endl;
    cin >> r[x].htmp;
    cout << "Enter the low temp:" << endl;
    cin >> r[x].ltmp;
    r[x].atmp = (r[x].ltmp + r[x].htmp)/2;
    
}



void print(float ar, float h, float l, float at)
{
    cout << "Average monthly rainfall:" << ar << endl;
    cout << "High Temp:" << h << endl;
    cout << "Low Temp:" << l << endl;
    cout << "Average Temp:" << at;
}