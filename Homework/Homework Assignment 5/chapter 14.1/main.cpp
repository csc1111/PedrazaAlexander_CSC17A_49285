/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Purpose: Takes a user's number from 0-9999 and outputs it in english
 *   
 */

#include <iostream>

class Numbers
{
private:
    int num;            //users number
public:
    Numbers(int);       //constructor
    void setN(int);     //sets number
    void prnt();        //prints number in english
};

using namespace std;


int main(int argc, char** argv) 
{
    int num;        //users number
    
    cout << "Enter a number from 0-9999: ";
    cin >> num;
    while(num<0||num>9999)      //
    {
        cout << "Number must be positive and less than 10000. Try again: ";
        cin >> num;
    }
    Numbers n(num);
    n.prnt();
    
    return 0;
}

Numbers::Numbers(int n)
{
   setN(n);     //calls setN() function
}

void Numbers::setN(int n)
{
    num=n;
}

void Numbers::prnt()
{
    //english numbers less than 20
    string lesT[20] = {"zero ", "one ", "two ", "three ", "four ", "five ",
                        "six ", "seven ", "eight ", "nine ", "ten",
                        "eleven", "twelve", "thirteen", "fourteen",
                        "fifteen", "sixteen", "seventeen", "eighteen",
                        "nineteen "};
    //english numbers for double digits
    string tens[8] = {"twenty ", "thirty ", "forty ", "fifty ", "sixty ",
                        "seventy ", "eighty ", "ninety "};
    //english word hundred
    string hndrd = "hundred ";
    //english word for thousand
    string thsnd = "thousand ";
    
    int temp = num;             //keeps track of the number we are on.
    int temp1 = 0;              //temporarily holds number being outputted
    
    if(temp == 0)               //when temp is 0 output 0 without testing further
        cout << lesT[temp];
    else
    {
        if (temp>999)               //when num is greater than 999
        {
            temp1=temp/1000;        //finds number at 1000
            cout << lesT[temp1] << thsnd;   //outputs number in english and thousand
            temp-=temp1*1000;       //takes the thousand place from temp
        }
        if(temp>99)                 //when number is greater than 99
        {
            temp1=temp;             //temp1 becomes temp
            temp1/=100;             //finds the number at 100
            cout << lesT[temp1] << hndrd;   //outputs number in english and hundred
            temp-=temp1*100;        //takes hundreds place out of temp
        }
        if(temp<19&&temp!=0)        //when temp is less than 19 and not 0
            cout << lesT[temp];     //outputs number in english
        else if(temp>19)            //when temp is greater than 19
        {
            temp1=temp/10;          //gets tens place
            cout << tens[temp1-2];  //outputs tens place
            temp-=temp1*10;         //removes tens place
            if(temp>0)              //if temp is greater than 0
                cout << lesT[temp]; //outputs number in english
        }
    }
}