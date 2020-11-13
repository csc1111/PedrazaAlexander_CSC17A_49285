/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Purpose: Saves three items description, amount, and value.
 *       
 */

#include <iostream>
#include <iomanip>

using namespace std;


class RetailItem
{
private:
    string dsc;         //description
    int unt;            //units
    double prc;         //price of item (book said to use double)
    
public:
    RetailItem(string, int, double);    //constructor
    void setDsc(string);                //sets description
    void setUnt(int);                   //sets units
    void setPrc(double);                //sets price
    
    string getDsc() const;              //returns desc
    int getUnt() const;                 //returns units
    double getPrc() const;              //returns price
};

void input(string &, int &, double &, int &);   //input into class
void prnt(RetailItem, int &);                   //prints class

int main(int argc, char** argv) 
{
    string dsc;          //description
    int unt;             //unit
    double prc;          //price
    int itm=1;           //item count
 
    input(dsc, unt, prc, itm);
    RetailItem one(dsc, unt, prc);
    input(dsc, unt, prc, itm);
    RetailItem two(dsc, unt, prc);
    input(dsc, unt, prc, itm);
    RetailItem thre(dsc, unt, prc);
    itm=1;                          //resets the item count
    prnt(one, itm);
    prnt(two, itm);
    prnt(thre, itm);

    return 0;
}

/****************************************************************************
 *  input                                                                   *
 *      lets you input into a class                                         *
 ***************************************************************************/
void input(string &d, int &u, double &p, int &i)
{
    cout << "Enter description of item " << i << ": ";
    getline(cin, d);
    cout << "Enter number of units: ";
    cin >> u;
    cout << "Enter the price: ";
    cin >> p;
    cin.ignore();

    ++i;
}
/****************************************************************************
 *  prnt                                                                    *
 *      Prints the variables in the class                                   *
 ***************************************************************************/
void prnt(RetailItem x, int &i)
{
    cout << "Item " << i <<endl;
    cout << "_____________________________";
    cout << "Description: " << x.getDsc() << endl;
    cout << "Units on hand: " << x.getUnt() << endl;
    cout << "Price: $" << fixed << setprecision(2) << x.getPrc() << endl;
    cout << endl;
    ++i;
}

/****************************************************************************
 *  RetailItem constructor                                                  *
 *      calls set functions to fill class                                   *
 ***************************************************************************/
RetailItem::RetailItem(string d, int u, double p)
{
    setDsc(d);
    setUnt(u);
    setPrc(p);
}

/****************************************************************************
 *  setDsc                                                                  *
 *      Sets the description                                                *
 ***************************************************************************/
void RetailItem::setDsc(string d)
{
    dsc=d;
}
/****************************************************************************
 *  setUnt                                                                  *
 *      Sets the units                                                      *
 ***************************************************************************/
void RetailItem::setUnt(int u)
{
    unt=u;
}
/****************************************************************************
 *  setPrc                                                                  *
 *      Sets the price                                                      *
 ***************************************************************************/
void RetailItem::setPrc(double p)
{
    prc=p;
}

/****************************************************************************
 *  getDsc                                                                  *
 *      returns the description                                             *
 ***************************************************************************/
string RetailItem::getDsc() const
{
    return dsc;
}
/****************************************************************************
 *  getUnt                                                                  *
 *      returns the unit                                                    *
 ***************************************************************************/
int RetailItem::getUnt() const
{
    return unt;
}
/****************************************************************************
 *  getPrc                                                                  *
 *      returns the price                                                   *
 ***************************************************************************/
double RetailItem::getPrc() const
{
    return prc;
}