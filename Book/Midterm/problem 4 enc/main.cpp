/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Purpose:  Encrypts a 4 digit number between 0-7 by adding 5 and finding the  
 *           number modulus 8. Then it swaps 1and3, and 2and4.
 */

#include <iostream>
#include <iomanip>

using namespace std;

void encrypt();

int main(int argc, char** argv) 
{    
    encrypt();
    
    return 0;
}

void encrypt()
{
    int num;                    //users number
    int on, tw, th, fr;         //numbers one-four
    int tmp;                    //temporary place holder
    int enc;                    //encrypted number
    bool x;
    
    do
    {
        x=0;
        cout << "Enter a four digit number: ";
        cin >> num;
        if(num<0)
        {
            cout << "Can't be a negative number. Try again.";
            cin >> num;
            cout << endl;
        }
        
        //isolates numbers
        on = (num / 1000);
        tw = (num % 1000 / 100);
        th = (num % 1000 % 100 / 10);
        fr = (num % 1000 % 1000 % 10);
        if(on>7|| tw>7 || th>7 || fr>7)   //number can't be more than 7
        {
            cout << "Numbers can't be greater than 7. Try again:";
            x=1;                //do while loops again
        }
    }while(x);
    
    //encrypts
    //adds 5 then modulus of 8
    on = (on+5)%8;
    tw = (tw+5)%8;
    th = (th+5)%8;
    fr = (fr+5)%8;
    
    //switches one and three, then two and four
    tmp = on;
    on = th * 1000;
    th = tmp * 10;
    tmp = tw;
    tw = fr * 100;
    fr = tmp * 1;
    //encrypted number
    enc = on + tw + th + fr;

    cout << "Encrypted number: ";
    cout << setfill('0') << setw(4) << enc;
}
