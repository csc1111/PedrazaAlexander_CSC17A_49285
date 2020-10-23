/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Purpose:  Decrypts a 4 digit number between 0-7 by adding 3 and finding the  
 *           number modulus 8. Then it swaps 1and3, and 2and4.
 */
#include <iostream>
#include <iomanip>

using namespace std;

void decrypt();

int main(int argc, char** argv) 
{
    decrypt();
    
    return 0;
}


void decrypt()
{
    int num;                  //users encrypted number
    int on, tw, th, fr;       //numbers one through four
    int tmp;                  //temporary number placeholder
    int dec;                  //decrypted number
    bool x;                   //bool for while loop 
    
    do
    {
        x=0;
        cout << "Enter encrypted 4 digit code"
                <<"(must be less than 8 and can't be a negative): ";
        cin >> num;
        cout << endl;
        
        if(num<0)       //can't be a negative number
        {
            cout << "No negative numbers. Try again:";
            cin >> num;
            cout << endl;
        }

        //isolates the numbers
        on = num / 1000;
        tw = num %1000 / 100;
        th = num %1000 %100 / 10;
        fr = num %1000 %1000 %10;
        
        if(on>7|| tw>7 || th>7 || fr>7)   //number can't be more than 7
        {
            cout << "Numbers can't be greater than 7. Try again:";
            x=1;                //do while loops again
        }
    }while(x);
    
    
    //decrypts number 
    tmp = (on + 3) %8;      //3 = 8-5
    on = (th + 3) %8;
    th = tmp;
    tmp = (tw + 3) %8;
    tw = (fr + 3) %8;
    fr = tmp;
    //brings numbers back together 
    dec = on * 1000 + tw * 100 + th * 10 + fr;
    
    cout << "Decrypted number: ";
    cout << setfill('0') << setw(4) << dec;     //setfill makes first 0 visible
}
