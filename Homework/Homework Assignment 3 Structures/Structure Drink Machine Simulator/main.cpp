/* 
 * File: Structure Drink Machine Simulator
 * Author: Alexander Pedraza
 * Created on 10/11/2020
 * Purpose:  order drink from vending machine
 */

#include <iostream>
#include <iomanip> 

using namespace std;

struct drnk
{
    string sda;     //soda name
    int cst;        //cost of soda
    int qnt;        //quantity of sodas in machine
    
};

void fill(drnk *);                              //fills vnd array
void output(drnk *, const int);                 //outputs the menu
void choice(drnk *, int &, const int ,bool &);  //user choice


int main()
{
    const int el = 5;     //array elements
    drnk vnd[el];         //vending machine
    int me=0;             //money earned
    bool qt=1;            //bool quit do while
    
    fill(vnd);
    
    do
    {
    output(vnd, el);        
    choice(vnd, me, el, qt);
    }while(qt);     //runs loop till qt is 0
    
    cout << me << endl;
    
    return 0;
}

void fill(drnk *v)
{
    v[0].sda = "Cola";
    v[0].cst= 75;
    v[0].qnt = 20;
    
    v[1].sda = "Root Beer";
    v[1].cst= 75;
    v[1].qnt = 20;    
    
    v[2].sda = "Lemon-Lime";
    v[2].cst= 75;
    v[2].qnt = 20;   
    
    v[3].sda = "Grape Soda";
    v[3].cst= 80;
    v[3].qnt = 20;
    
    v[4].sda = "Cream Soda";
    v[4].cst= 80;
    v[4].qnt = 20;
}

void output(drnk *v, const int e)
{
    for(int x=0; x<e; ++x)
    {
        cout << left << setw(11) << v[x].sda;
        cout << left << setw(4) << v[x].cst;
        cout << v[x].qnt;
        cout << endl;
    }
    cout << "Quit\n";
}

void choice(drnk* v, int &m, const int e, bool &q)
{
    string chc;         //user choice
    int mny;            //users cash

    getline(cin,chc);
    for(int x=0; x<e; ++x)  //runs through menu
    {
        if(chc == v[x].sda) //if users choice equals an option 
        {
            if(v[x].qnt==0)         //if no more sodas are left
                cout<<"Sold Out\n";
            else
            {
                cin >> mny;             
                while(mny<0||mny>100)   //validation for money
                {
                    cout << "Must be more than 0 and greater than 100";
                    cin >> mny;
                }
                mny -= v[x].cst;    //calculates change
                cout << mny << endl;
                m+=v[x].cst;        //money made
                --v[x].qnt;         //quantity lowered
            }
        }    
        else if(chc == "Quit")  //if quit then for loop ends and q=0
        {
            x+=e;
            q=0;
        }
    }
    cin.ignore();

}