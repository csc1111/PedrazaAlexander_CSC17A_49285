/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Purpose:  Prints out a check for workers depending on their hours worked,
 *           their pay rate.
 */
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cmath>

using namespace std;

struct emp
{
    string nam;     //Employee Name
    int hrs;        //Hours worked
    float rop;      //Rate of pay
    float pay;      //total pay
};

emp *info(int);
void print(emp *, int);
void eng(emp *, int);
int reverse(int, int);
void out(int ,int ,int);

int main(int argc, char** argv) 
{
    emp *emps;      //employee array
    int empn;       //employee numbers
    cout << "Enter the number of employees: ";
    cin >> empn;
    
    emps = info(empn);
    print(emps, empn);
    
    delete[] emps;  //frees memory
    return 0;
}

emp *info(int empn)
{
    emp  *e=new emp[empn];
    
    for(int x=0; x<empn; ++x)
    {
        cin.ignore();
        cout << "Enter employee name: ";
        getline(cin, e[x].nam);

        cout << "Enter  hours worked: ";
        cin >> e[x].hrs;
        while(e[x].hrs<0)
        {
            cout << "Must be a positive number. Try again:";
            cin >> e[x].hrs;
        }
        
        cout << "Enter pay rate: ";
        cin >> e[x].rop;
        while(e[x].rop<0)
        {
            cout << "Must be a positive number. Try again:";
            cin >> e[x].rop;
        }
        
        e[x].pay=0;
        if(e[x].hrs>50)
        {
            e[x].pay+=(e[x].hrs-50)*(e[x].rop*3);
            e[x].pay+=(10)*(e[x].rop*2);
            e[x].pay+=(40)*e[x].rop;
        }
        else if(e[x].hrs>40)
        {
            e[x].pay+=(e[x].hrs-40)*(e[x].rop*2);
            e[x].pay+=(40)*e[x].rop;
        }
        else
            e[x].pay += e[x].hrs*e[x].rop;

    }    
    return e;
}

void print(emp *e, int empn)
{
    //loops to print all employees info
    for(int x=0; x<empn; ++x)
    {
        cout << "Company"<<endl;
        cout << "Address"<<endl;
        cout << "Name: " << setw(20) << e[x].nam << " Amount: " 
                << fixed << setprecision(2) << e[x].pay << endl;
        cout << "Amount: ";
        eng(e,x);               //english output
        cout << "Signature Line:________________________________________ \n";
    }
}

void eng(emp *e, int x)
{
    int l;                    //numbers length
    int rev;                  //Reversed number
    int mod;                  //reversed number modulized by 10
    float chg;                //change
    float temp = e[x].pay;    //holds the value of e[x].pay

    
    chg = floor(e[x].pay);          //rounds e[x].pay down 
    chg = (e[x].pay-chg)*100;       //subtracts e[x].pay by chg then * by 10
                                    //get the change
    
    for(;temp>=1;temp/=10)
        ++l;                //finds length

    temp=e[x].pay;
    rev=reverse(temp, l);
    
    while(rev)                  //goes till rev is 0
    {
        mod=rev%10;             //modulus of rev modulus 10. Gets last nuber of
                                //rev but first number of needed check
        rev/=10;                //reverse is divided by 10 in preperation for 
                                //next number
        if(l==1)        
            out(mod,l,rev);
        else if(l==2)
        {
            if(mod==1)
            {
                out(mod,l,rev); //tens place
                l-=2;           //loop ends
            }
            else
            {
                out(mod,l,rev);    //tens place
                --l;
            }
        }
        else if(l==3)       //hundreds
        {
            out(mod,l,rev);
            --l;
            if(mod!=0)
                cout<<"hundred ";
        }
        else if(l>=4)             //if l is > 4 
        {
            out(mod,l,rev);
            --l;        
            if(mod==1&&l==4)        //when a number 10-19 is outputted l is 
                --l;                //decremented to skip over next number
            
            if(l==3)                //thousand is not said till all thousands
                cout<<"thousand ";  //are said
        }
    }
    cout << "dollars " <<fixed <<setprecision(0) << chg << " /100\n";
}

int reverse(int v,int lim)
{
	if(lim==1)  //if there is only one number no need to reverse
		return v;
	else        //reverses numbers
		return (((v%10)*pow(10,lim-1))+reverse(v/10,lim-1)); 
}

void out(int digit,int l,int r) 
{
    if(l==5&&digit==1)                  //if the length is 5 and the digit is 1
    {                                   //r needs to be changed in order for a
        r=r%10;                         //number from 10-19 to be displayed 
    }                                   //properly
    
    if(l==1||l==3||l==4)                //when number is any of these lengths     
    {                                  //ex 1, 100, 1000
        switch(digit)                           //singles
        {                                   
            case 1: cout<<"one ";
            break;
            case 2: cout<<"two ";
            break;
            case 3: cout<<"three ";
            break;
            case 4: cout<<"four ";
            break;
            case 5: cout<<"five ";
            break;
            case 6: cout<<"six ";
            break;
            case 7: cout<<"seven ";
            break;
            case 8: cout<<"eight ";
            break;
            case 9: cout<<"nine ";
            break;
        }
    }
    else if(l==2 || l==5 )                       //tens place and ten thousands     
    {
        switch(digit)                      
        {
            case 1: switch(r)               //values 10-19 determined by r or r%10
            {                               //if l=5
                case 0: cout<<"ten ";
                break;
                case 1: cout<<"eleven ";
                break;
                case 2: cout<<"twelve ";
                break;
                case 3: cout<<"thirteen ";
                break;
                case 4: cout<<"fourteen ";
                break;
                case 5: cout<<"fifteen ";
                break;
                case 6: cout<<"sixteen ";
                break;
                case 7: cout<<"seventeen ";
                break;
                case 8: cout<<"eighteen ";
                break;
                case 9: cout<<"nineteen ";
                break;
            }
            break;
            case 2: cout<<"twenty ";
            break;
            case 3: cout<<"thirty ";
            break;
            case 4: cout<<"forty ";
            break;
            case 5: cout<<"fifty ";
            break;
            case 6: cout<<"sixty ";
            break;
            case 7: cout<<"seventy ";
            break;
            case 8: cout<<"eighty ";
            break;
            case 9: cout<<"ninety ";
            break;
            case 0: cout<<"";
            break;

        }
    }
    else if(l==6)               //for hundred thousands
    {
        switch(digit)  
        {                                   
            case 1: cout<<"one hundred ";
            break;
            case 2: cout<<"two hundred ";
            break;
            case 3: cout<<"three hundred ";
            break;
            case 4: cout<<"four hundred ";
            break;
            case 5: cout<<"five hundred ";
            break;
            case 6: cout<<"six hundred ";
            break;
            case 7: cout<<"seven hundred ";
            break;
            case 8: cout<<"eight hundred ";
            break;
            case 9: cout<<"nine hundred ";
            break;
        }
    }
}