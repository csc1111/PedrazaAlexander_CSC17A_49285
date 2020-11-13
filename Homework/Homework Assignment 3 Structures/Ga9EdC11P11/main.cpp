/* 
 * File: Ga9EdC11P11
 * Author: Alexander Pedraza
 * Created on 10/11/2020
 * Purpose:  Monthly budget goal met
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
struct bdgt
{
    float hs;       //Housing
    float ut;       //Utilities                       
    float hhe;      //Household Expenses
    float trn;      //Transportation
    float fd;       //Food
    float med;      //Medical
    float ins;      //Insurance
    float ent;      //Entertainment
    float clt;      //Clothing
    float misc;     //Misc
};

void budget(bdgt&);         //set budget goal
void budgetExp(bdgt&);      //actual money spent
void prntNcmp(bdgt, bdgt);  //output results

//Execution Begins Here
int main(int argc, char** argv) {

    bdgt bs;                //base budget
    bdgt exp;               //expenses
    
    
    budget(bs);
    budgetExp(exp);
    prntNcmp(bs,exp);

    return 0;
}

void budget(bdgt &b)
{
    b.hs = 500;
    b.ut = 150;
    b.hhe = 65;
    b.trn = 50;
    b.fd = 250;
    b.med = 30;
    b.ins = 100;
    b.ent = 150;
    b.clt = 75;
    b.misc = 50;
}

void budgetExp(bdgt &b)
{
    cout << "Enter housing cost for the month:$" << endl;
    cin >> b.hs;
    cout << "Enter utilities cost for the month:$" << endl;
    cin >> b.ut;
    cout << "Enter household expenses cost for the month:$" << endl;
    cin >> b.hhe;
    cout << "Enter transportation cost for the month:$" << endl;
    cin >> b.trn;
    cout << "Enter food cost for the month:$" << endl;
    cin >> b.fd;
    cout << "Enter medical cost for the month:$" << endl;
    cin >> b.med;
    cout << "Enter insurance cost for the month:$" << endl;
    cin >> b.ins;
    cout << "Enter entertainment cost for the month:$" << endl;
    cin >> b.ent;
    cout << "Enter clothing cost for the month:$" << endl;
    cin >> b.clt;
    cout << "Enter miscellaneous cost for the month:$" << endl;
    cin >> b.misc;
    
}

void prntNcmp(bdgt b, bdgt c)
{
    float tot=0;          //total spent
    float btot=0;         //base budget total
    
    /*if the amount spent is greater than the budget, its over, if lesser then 
     *its under, if equal then its even. Totals are added and base totals are 
     *added 
    */
    cout << "Housing ";
    if(b.hs > c.hs)
        cout << "Under\n";
    else if(b.hs == c.hs)
        cout << "Even\n";
    else if (b.hs < c.hs)
        cout << "Over\n";
    tot += c.hs;
    btot+=b.hs;
    
    cout << "Utilities ";
    if(b.ut > c.ut)
        cout << "Under\n";
    else if(b.ut == c.ut)
        cout << "Even\n";
    else if (b.ut < c.ut)
        cout << "Over\n";
    tot += c.ut;
    btot+=b.ut;
    
    cout << "Household Expenses ";
    if(b.hhe > c.hhe)
        cout << "Under\n";
    else if(b.hhe == c.hhe)
        cout << "Even\n";
    else if (b.hhe < c.hhe)
        cout << "Over\n";
    tot += c.hhe;
    btot+= b.hhe;
    
    cout << "Transportation ";
    if(b.trn > c.trn)
        cout << "Under\n";
    else if(b.trn == c.trn)
        cout << "Even\n";
    else if (b.trn < c.trn)
        cout << "Over\n";
    tot += c.trn;
    btot+= b.trn;
    
    cout << "Food ";
    if(b.fd > c.fd)
        cout << "Under\n";
    else if(b.fd == c.fd)
        cout << "Even\n";
    else if (b.fd < c.fd)
        cout << "Over\n";
    tot += c.fd;
    btot+= b.fd;
    
    cout << "Medical ";
    if(b.med > c.med)
        cout << "Under\n";
    else if(b.med == c.med)
        cout << "Even\n";
    else if (b.med < c.med)
        cout << "Over\n";
    tot += c.med;
    btot+= b.med;
    
    cout << "Insurance ";
    if(b.ins > c.ins)
        cout << "Under\n";
    else if(b.ins == c.ins)
        cout << "Even\n";
    else if (b.ins < c.ins)
        cout << "Over\n";
    tot += c.ins;
    btot+= b.ins;
    
    cout << "Entertainment ";
    if(b.ent > c.ent)
        cout << "Under\n";
    else if(b.ent == c.ent)
        cout << "Even\n";
    else if (b.ent < c.ent)
        cout << "Over\n";
    tot += c.ent;
    btot+= b.ent;
    
    cout << "Clothing ";
    if(b.clt > c.clt)
        cout << "Under\n";
    else if(b.clt == c.clt)
        cout << "Even\n";
    else if (b.clt < c.clt)
        cout << "Over\n";
    tot += c.clt;
    btot+= b.clt;
    
    cout << "Miscellaneous ";
    if(b.misc > c.misc)
        cout << "Under\n";
    else if(b.misc == c.misc)
        cout << "Even\n";
    else if (b.misc < c.misc)
        cout << "Over\n";
    tot += c.misc;
    btot+= b.misc;
    
    if(tot<btot)
        cout << "You were $" << fixed << setprecision(2) << btot-tot << " under budget";
    else if(tot>btot)
    {
        cout << "You were $" << fixed << setprecision(2) << tot-btot << " over budget";
    }
    else if (tot==btot)
        cout << "You were even on budget";
        
}