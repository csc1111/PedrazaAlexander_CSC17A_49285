/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Purpose: Saves a user and his friend and family members info
 *       
 */

#include <iostream>

using namespace std;


class pInfo
{
    private:
        string name;    //name
        string adrs;   //address
        int age;        //age
        int phnN;      //phone number
    
    public:
        void setNam(string);    //sets name
        void setAdrs(string);   //sets address
        void setAge(int);       //sets age
        void setPhnN(int);      //sets phone number
        
        string prntNam();       //returns name
        string prntAdrs();      //returns address
        int prntAge();          //returns age
        int prntPhn();          //returns phone number
};
void info(string &, string &, int &, int &);

int main(int argc, char** argv) 
{
    pInfo you, frnd, fam;       //user's info, friends info, family members info
    string n, ad;               //string holding name and address
    int ag, phn;                //integer holding age and phone number
    
    //gets users info
    cout << "Enter your ";
    info(n, ad, ag, phn);
    you.setNam(n);
    you.setAdrs(ad);
    you.setAge(ag);
    you.setPhnN(phn);
        cin.ignore();
        
    //gets friend's info
    cout << "Enter your friend's ";
    info(n, ad, ag, phn); 
    frnd.setNam(n);
    frnd.setAdrs(ad);
    frnd.setAge(ag);
    frnd.setPhnN(phn);
        cin.ignore();
        
    //gets family member's info
    cout << "Enter your family  member's ";
    info(n, ad, ag, phn); 
    fam.setNam(n);
    fam.setAdrs(ad);
    fam.setAge(ag);
    fam.setPhnN(phn);
    
    //outputs user info
    cout << endl;
    cout << "Name: " << you.prntNam() << endl;
    cout << "Address: " << you.prntAdrs() << endl;
    cout << "Age: " << you.prntAge() << endl;
    cout << "Phone Number: " << you.prntPhn()<< endl; 
    cout << endl;
    //outputs friend's info
    cout << "Name: " << frnd.prntNam() << endl;
    cout << "Address: " << frnd.prntAdrs() << endl;
    cout << "Age: " << frnd.prntAge() << endl;
    cout << "Phone Number: " << frnd.prntPhn() <<endl; 
    cout << endl;
    //outputs family member's info
    cout << "Name: " << fam.prntNam() << endl;
    cout << "Address: " << fam.prntAdrs() << endl;
    cout << "Age: " << fam.prntAge() << endl;
    cout << "Phone Number: " << fam.prntPhn()<<endl; 

    return 0;
}

void info(string &nm, string &ad, int &ag, int &phn)
{
    cout << "name: ";
    getline(cin, nm);           //gets name
    cout << "Enter address: ";
    getline(cin, ad);           //gets address
    cout << "Enter age: ";
    cin >> ag;                  //gets age
    cout << "Enter phone number: ";
    cin >> phn;                 //gets phone number

}


/****************************************************************************
 *  setNam                                                                  *
 *      assigns value to name                                               *
 ***************************************************************************/
void pInfo::setNam(string n)
{
    name = n;
}
/****************************************************************************
 *  setAdrs                                                                 *
 *      assigns value to adrs                                               *
 ***************************************************************************/
void pInfo::setAdrs(string ad)
{
    adrs = ad;
}
/****************************************************************************
 *  setAge                                                                  *
 *      assigns value to age                                                *
 ***************************************************************************/
void pInfo::setAge(int ag)
{
    age = ag;
}
/****************************************************************************
 *  setPhnN                                                                 *
 *      assigns value to phnN                                               *
 ***************************************************************************/
void pInfo::setPhnN(int phn)
{
    phnN = phn;
}

/****************************************************************************
 *  prntNam                                                                 *
 *      returns value of name                                               *
 ***************************************************************************/
string pInfo::prntNam()
{
    return name;
}
/****************************************************************************
 *  prntAdrs                                                                *
 *      returns value of adrs                                               *
 ***************************************************************************/
string pInfo::prntAdrs()
{
    return adrs;
}
/****************************************************************************
 *  prntAge                                                                 *
 *      returns value of age                                                *
 ***************************************************************************/
int pInfo::prntAge()
{
    return age;
}
/****************************************************************************
 *  prntPhn                                                                 *
 *      returns value of phone number                                       *
 ***************************************************************************/
int pInfo::prntPhn()
{
    return phnN;
}
