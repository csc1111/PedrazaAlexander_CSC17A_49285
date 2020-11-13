/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Purpose: Saves three items number, quantity, cost, total cost.
 *       
 */

#include <iostream>
#include <iomanip>

using namespace std;

class Inventory
{
private:
    int itNm;                           //item number
    int qnt;                            //quantity number
    double cst;                         //cost
    double tcst;                        //total cost
    
public:
    Inventory();
    Inventory(int, int, double);
    
    void setItNm(int);                  //sets item number
    void setQnt(int);                   //sets quantity
    void setCst(double);                //sets cost
    void setTcst(double, int);          //sets total cost

    int getItNm() const;                //returns item number
    int getQnt() const;                 //gets quantity
    double getCst() const;              //gets cost
    double getTcst() const;             //gets total cost
    
};
        
void Input(int &, int &, double &);     //Input into class
void prnt(Inventory);                   //Prints from class
        
int main(int argc, char** argv) 
{
    int itNm, qnt;                  //item number and quantity
    double cst, tcst;               //cost and total cost
    Input(itNm, qnt, cst);
    Inventory item(itNm, qnt, cst);
    prnt(item);

    return 0;
}

/****************************************************************************
 *  Input                                                                   *
 *      Inputs into class                                                   *
 ***************************************************************************/
void Input(int &i, int &q, double &c)
{
    cout << "Enter Item number: ";
    cin >> i;
    while(i<0)
    {
        cout << "Item number cannot be a negative. Try again: ";
        cin >> i;
    }
    cout << "Enter quantity of item: ";
    cin >> q;
    while(q<0)
    {
        cout << "Quantity cannot be a negative. Try again: ";
        cin >> q;
    }
    cout << "Enter the cost: $";
    cin >> c;
    while(c<0)
    {
        cout << "Cost cannot be a negative. Try again: ";
        cin >> c;
    }
    cout << endl;
}
/****************************************************************************
 *  prnt                                                                    *
 *      Outputs the class                                                   *
 ***************************************************************************/
void prnt(Inventory i)
{
    cout << "Item #" << i.getItNm() << endl;
    cout << "________________\n";
    cout << "Quantity: " << i.getQnt() << endl;
    cout << "Cost: $" << fixed << setprecision(2) << i.getCst() << endl;
    cout << "Total cost: $" << fixed << setprecision(2) << i.getTcst() << endl;    
}

/****************************************************************************
 *  Inventory constructor                                                   *
 *      If no variables all are 0                                           *
 ***************************************************************************/
Inventory::Inventory()
{
    setItNm(0);
    setQnt(0);
    setCst(0);
    setTcst(0,0);
}

/****************************************************************************
 *  Inventory constructor                                                   *
 *      fills class                                                         *
 ***************************************************************************/
Inventory::Inventory(int i, int q, double c)
{
    setItNm(i);
    setQnt(q);
    setCst(c);
    setTcst(c,q);
}

void Inventory::setItNm(int i)
{
    itNm = i;
}
void Inventory::setQnt(int q)
{
    qnt = q;
}
void Inventory::setCst(double c)
{
    cst = c;
}
void Inventory::setTcst(double c, int q)
{
    tcst = c*q;
}

int Inventory::getItNm() const  
{
    return itNm;
}
int Inventory::getQnt() const
{
    return qnt;
}
double Inventory::getCst() const
{
    return cst;
}
double Inventory::getTcst() const
{
    return tcst;
}