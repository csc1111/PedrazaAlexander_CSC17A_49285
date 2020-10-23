/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Purpose:  Problem 5 finds biggest factorial number possible for a data type
 *           
 */

#include <iostream>
#include <cmath>
using namespace std;


int main(int argc, char** argv) 
{

    cout << " bool           n=1      1 != 1\n";
    cout << " unsigned char  n=5      5 != 120\n";
    cout << " signed char    n=5      5 != 120\n";
    cout << " signed int     n=12    12 != 479,001,600\n";
    cout << " unsigned int   n=12    12 != 479,001,600\n";
    cout << " signed short   n=7      7 != 5,040\n";
    cout << " unsigned short n=8      8 != 40,320\n";
    cout << " signed long    n=20    20 != 2,432,902,008,176,640,000\n";
    cout << " unsigned long  n=20    20 != 2,432,902,008,176,640,000\n";
    cout << " float          n=34    34 != 295,232,799,039,600,000,000,000,000,000"
            <<",000,000,000\n";
    cout << " double         n=303  303 != 1.7888*10^308";

    return 0;
}

