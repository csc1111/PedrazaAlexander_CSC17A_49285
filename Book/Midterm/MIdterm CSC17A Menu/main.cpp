/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Purpose:  Menu for mid term
 *           
 */
//Libraries 
#include <iostream>
#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <cmath>



//User Libraries(used for problem 3)
#include "Array.h"
#include "Stats.h"

using namespace std;

struct cstmr         //Customer info (Problem 1)
{
    string nam;      //Customer name
    string adrs;     //Address
    int actn;        //Account number
    float bbeg;      //Balance at the beginning of the month
    float blnc;      //Balance at the beginning of month
    float chk;       //Checks written
    float deps;      //Deposits made by customer
};

struct emp          //Employee info(problem 2)
{
    string nam;     //Employee Name
    int hrs;        //Hours worked
    float rop;      //Rate of pay
    float pay;      //total pay
};


//problem 7
struct Prime{       
	unsigned short prime;
	unsigned char power;
};
struct Primes{
	unsigned char nPrimes;
	Prime *prime;
};


void menu();
int getN();
void problem1();
//problem 1 functions
void fillArr(cstmr &);
void output(cstmr );


void problem2();
//problem 2 functions
emp *info(int);
void print(emp *, int);
void eng(emp *, int);
int reverse(int, int);
void out(int ,int ,int);


void problem3();
//problem 3 functions
Array *fillAry(int,int);        //Fill an array and put into a structure
void prntAry(const Array *,int);//Print the array 
int *copy(const int *,int);     //Copy the array
void mrkSort(int *,int);        //Sort an array
void prtStat(const Stats *);    //Print the structure
void rcvrMem(Array *);          //Recover memory from the Array Structure
void rcvrMem(Stats *);          //Recover memory from Statistics Structure
Stats *stat(const Array *);     //Find & store mean, median, & modes in structure


void problem4();
//problem 4
void encrypt();
void decrypt();


void problem5();


void problem6();


void problem7();
//problem 7
Primes *factor(int);
void prntPrm(Primes *);


int main(int argc, char** argv) 
{
    int inN;

    menu();
    inN=getN();

    switch(inN)
    {
       case 1:    problem1();break;
       case 2:    problem2();break;
       case 3:    problem3();break;
       case 4:    problem4();break;
       case 5:    problem5();break;
       case 6:    problem6();break;
       case 7:    problem7();break;
       default:   "end"; break;
    }

        
    return 0;
}

void menu()
{
    
    cout<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Problem 1"<<endl;
    cout<<"Type 2 for Problem 2"<<endl;
    cout<<"Type 3 for Problem 3"<<endl;   
    cout<<"Type 4 for Problem 4"<<endl;
    cout<<"Type 5 for Problem 2"<<endl;
    cout<<"Type 6 for Problem 3"<<endl;   
    cout<<"Type 7 for Problem 4"<<endl;
    cout<<"Type a number not listed above to end"<< endl <<endl;
}
int getN()
{
    int n;
    cin >> n;
    
    return n;
}

/*****************************************************************************
 *
 *                              Problem 1
 * Determines the balance of a persons bank account after checks are written and
 * deposits are made. If they spent too much they get charged.
 * ***************************************************************************/
void problem1()
{
    cin.ignore();
    cstmr usr;          //user's struct
    
    fillArr(usr);
}

void fillArr(cstmr &u)
{
    int x=1;                //used to determine check values, deposits made and
                            //when to exit a while loop.
    cout << "Please enter your name: ";
    getline(cin, u.nam);
    cout << "Please enter your address: ";
    getline(cin, u.adrs);
    cout << "Enter account number: ";
    cin >> u.actn;
    cout << "Enter your balance at the beginning of the month: $";
    cin >> u.bbeg;
    u.blnc = u.bbeg;        //balance at beginning of month remains the same
    u.deps=0;               //balance changes 
    u.chk=0;
    
    cout << "Enter checks written this month (input 0 if done): $";
    while(x!=0)
    {
        cin >> x;
        u.chk+=x;           //every check amount is counted up
        u.blnc-=x;          //balance is dropped by check amount
    }
    
    x=1;
    cout << "Enter deposits made this month (input 0 if done): $";
    while(x!=0)
    {
        cin >> x;
        u.deps+=x;          //deposits made added up
        u.blnc+=x;          //balance is increased by deposits
    }
    
    if (u.blnc<0)           //if user went under balance they are charged $20
        u.blnc-=20;
    output(u);
}

void output(cstmr u)
{
    cout << "Name: "<< u.nam << endl;
    cout << "Address: " << u.adrs << endl;
    cout << "Account Number: " << u.actn << endl;
    cout << "Balance at the beginning of the month: $" << u.bbeg << endl;
    cout << "Total checks written: $" << u.chk << endl;
    cout << "Total deposits made: $" << u.deps << endl;
    if(u.blnc<0)    //when user is charged extra for going under they are told
        cout << "Your account was overdrawn. Extra $20 charge."<<endl;
    cout << "Total balance: $" << u.blnc;
}


/*****************************************************************************
 *
 *                              Problem 2
 * Prints out a check for workers depending on their hours worked,
 * their pay rate.
 * ***************************************************************************/
void problem2()
{
    emp *emps;      //employee array
    int empn;       //employee numbers
    cout << "Enter the number of employees: ";
    cin >> empn;
    
    emps = info(empn);
    print(emps, empn);
    
    delete[] emps;  //frees memory
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

/*****************************************************************************
 *
 *                              Problem 3
 * Driver program to test out the statistics problem.
 * ***************************************************************************/
void problem3()
{
    //Declare variables
    int arySize;//Array Size
    int modNum; //Number to control the modes (digits 0 to 9 allowed)
    Array *array;
    
    //Input the size and mod number
    cout<<"This program develops an array to be analyzed"<<endl;
    cout<<"Array size from mod number to 100"<<endl;
    cout<<"Mod number from 2 to 10"<<endl;
    cout<<"Input the Array Size and the mod number to be used."<<endl;
    cin>>arySize>>modNum;
    cout<<endl<<endl;
    
    //Fill the array
    array=fillAry(arySize,modNum);
    
    //Print the initial array
    cout<<"Original Array before sorting"<<endl;
    prntAry(array,10);
    
    //Sort the array
    mrkSort(array->data,array->size);
    cout<<"Sorted Array to be utilize for the stat function"<<endl;
    prntAry(array,10);
    
    //Calculate some of the statistics
    Stats *stats=stat(array);
    
    //Print the statistics
    prtStat(stats);
    
    //Recover allocated memory
    rcvrMem(array);
    rcvrMem(stats);
    
    //Exit stage right        
}

int *copy(const int *a,int n){
    //Declare and allocate an array
    //that is a c
    int *b=new int[n];
    //Fill
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Return the copy
    return b;
}

void prtStat(const Stats *ary){
    cout<<endl;
    cout<<"The average of the array = "<<ary->avg<<endl;
    cout<<"The median of the array  = "<<ary->median<<endl;
    cout<<"The number of modes      = "<<
            ary->mode->size<<endl;
    cout<<"The max Frequency        = "<<
            ary->modFreq<<endl;
    if(ary->mode->size==0){
        cout<<"The mode set             = {null}"<<endl;
        return;
    }
    cout<<"The mode set             = {";
    for(int i=0;i<ary->mode->size-1;i++){
        cout<<ary->mode->data[i]<<",";
    }
    cout<<ary->mode->data[ary->mode->size-1]<<"}"<<endl;
}

void mrkSort(int *array,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(array[j]<array[i]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
}

void rcvrMem(Stats *stats){
    rcvrMem(stats->mode);
    delete stats;
}

void rcvrMem(Array *array){
    delete []array->data;
    delete array;
}

void prntAry(const Array *array,int perLine){
    //Output the array
    for(int i=0;i<array->size;i++){
        cout<<array->data[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Array *fillAry(int n, int modNum){
    //Allocate memory
    Array *array=new Array;
    array->size=n;
    array->data=new int[array->size];
    
    //Fill the array with mod numbers
    for(int i=0;i<n;i++){
        array->data[i]=i%modNum;
    }
    
    //Exit function
    return array;
}

Stats *stat(const Array *array){
    //Non-working stub to be completed by the student
    cout<<endl<<"stat function to be completed by the student"<<endl;
    Stats *stats=new Stats;
    stats->mode=new Array;
    stats->mode->size=0;
    stats->mode->data=new int[array->size];
    stats->modFreq=0;
    stats->median=0;
    
    for(int x=0; x<array->size; ++x)
        stats->avg+=array->data[x];     //finds average
    stats->avg/=array->size;
    
    int pos=0;        //position

    for(int x=0; x<array->size; ++x)
    {
        int count=0;    //freq count
        
        for(int y=x; y<array->size; ++y)
        {
            if(array->data[x] == array->data[y])
                ++count;                //counts frequency of tested number
            else
                y+=array->size+1;       //ends loop
        }

        if (stats->modFreq<count)       //if the count is larger than current
        {                               //greatest frequency
            
            stats->mode->size=1;        //only one mode if new mode is found
            
            stats->modFreq=count;       //New freq is count
            
            stats->mode->data[0]=array->data[x];//new mode is set in the first 
                                                //array space
            
            pos=0;                      //position in array set back to 0
        }
        else if(stats->modFreq == count)//if current greatest frequency is equal
        {                               //to count 
            pos+=1;                     //second mode is set to next position
            
            stats->mode->size+=1;       //amount of modes increased
            
            stats->mode->data[pos]=array->data[x];//new mode is added to next
                                                  //spot in array
        }
      
        x+=count-1;     //in order to skip over numbers tested x=count-1
    }
    
    //when nModes(is divisible by 2 its an even and mode is found differently
    //when its odd its the middle number since array->size is an int
    if(stats->mode->size%2==0){
        stats->median=(array->data[(array->size/2)-1]+array->data[(array->size/2)]);
        stats->median/=2;
    }
    else
        stats->median=array->data[array->size/2];
    
    return stats;
}

/*****************************************************************************
 *
 *                              Problem 4
 * Encrypts and decrypts a 4 digit number between 0-7 by adding 5 and finding the  
 * number modulus 8. Then it swaps 1and3, and 2and4.
 * ***************************************************************************/
void problem4()
{
    int x;
    do
    {
        cout << "Enter 1 for encrypt, 2 for decrypt, and 0 to exit.";
        cin >> x;
        if(x<0||x>2)
            cout << "x must be 0,1 or 2. Try again\n";
        else if(x==1)
            encrypt();
        else if(x==2)
            decrypt();
    }while(x!=0);
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
        cout << "\nEnter a four digit number: ";
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
    cout << setfill('0') << setw(4) << enc <<endl;
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
        cout << "\nEnter encrypted 4 digit code"
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
    cout << setfill('0') << setw(4) << dec<<endl;     //setfill makes first 0 visible
}

/*****************************************************************************
 *
 *                              Problem 5
 * Problem 5 finds biggest factorial number possible for a data type
 * ***************************************************************************/
void problem5()
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
}

/*****************************************************************************
 *
 *                              Problem 6
 * outputs 2 numbers in float form binary, hex, and octal.
 * ***************************************************************************/
void problem6()
{
    cout<<"2.875 decimal\n 10.111 binary\n 2.E hexadecimal\n 2.7 octal\n";
    cout<<"2.875 in binary float form is"
            "0101 1100 0000 0000 0000 0000 0000 0010\n";
    cout << "in hex its A3000007\n\n";
    
    cout << "0.1796875 decimal\n 0.00101111 binary\n 0.2E hexadecimal\n 0.134 octal"
    cout << "0.1796875 in binary float form is "
            "0101 1100 0000 0000 0000 0000 1111 1100\n";
    cout << "in hex it's A30000FC\n\n";
    
}

/*****************************************************************************
 *
 *                              Problem 7
 * Finds prime factors of a number
 * ***************************************************************************/
void problem7()
{
    Primes *prime;
    int n;
    cout << "Enter a number between 2 and 10,000 to get all prime factors: ";
    cin >> n;
    while(n<2 || n>10000)
    {
        cout <<"\nThat is NOT a number between 2 and 10,000 as the instructions "
               "above have specified.\nPLEASE enter a number between 2(TWO)"
               " and 10,000(TEN THOUSAND): ";
        cin >>n;
    }
    
    prime=factor(n);
    cout << n;
    prntPrm(prime);
    delete []prime->prime;
    delete prime;
    return 0;
}
Primes *factor(int n)
{

    Primes *p=new Primes;
    p->prime=new Prime[100];        //new array created
    p->nPrimes=0;                   //number of unique prime numbers
    int cnt=0;                      //the position of the number
    
    /*if a number is divisible by a prime number it is divided by it till it can
     * stops giving whole numbers. The same thing is done for prime numbers till
     * number 97 because that is the highest prime number that can multiply
     * itself and be under 10,000 */
    
    if(n%2==0)                      //if n is divisible by 2
    {
        do                          //because of the if it is guaranteed to be 
        {                           //divisible by 2 atleast once
            p->prime[cnt].prime=2;  //first prime number spot becomes 2
            ++p->prime[cnt].power;  //power is incremented;
            n=n/2;                  //n is divided by 2
        }while(n%2==0);             //n is tested
        ++p->nPrimes;               //one prime number is counted
        ++cnt;                      
    }

    if(n%3==0)
    {
        do
        {
            p->prime[cnt].prime=3;
            ++p->prime[cnt].power;
            n=n/3;
        }while(n%3==0);
        ++p->nPrimes;    
        ++cnt;
    }
    
    if(n%5==0)
    {
        do
        {
            p->prime[cnt].prime=5;
            ++p->prime[cnt].power;
            n=n/5;
        }while(n%5==0);
        ++p->nPrimes;    
        ++cnt;
    }
    
    if(n%7==0)
    {
        do
        {
            p->prime[cnt].prime=7;
            ++p->prime[cnt].power;
            n=n/7;
        }while(n%7==0);
        ++p->nPrimes;    
        ++cnt;
    }
    
    if(n%11==0)
    {
        do
        {
            p->prime[cnt].prime=11;
            ++p->prime[cnt].power;
            n=n/11;
        }while(n%11==0);
        ++p->nPrimes;    
        ++cnt;
    }

    if(n%13==0)
    {
        do
        {
            p->prime[cnt].prime=13;
            ++p->prime[cnt].power;
            n=n/13;
        }while(n%13==0);
        ++p->nPrimes;    
        ++cnt;
    }
    
    if(n%17==0)
    {
        do
        {
            p->prime[cnt].prime=17;
            ++p->prime[cnt].power;
            n=n/17;
        }while(n%17==0);
        ++p->nPrimes;    
        ++cnt;
    }
    
    if(n%19==0)
    {
        do
        {
            p->prime[cnt].prime=19;
            ++p->prime[cnt].power;
            n=n/19;
        }while(n%19==0);
        ++p->nPrimes;    
        ++cnt;
    }
    
    if(n%23==0)
    {
        do
        {
            p->prime[cnt].prime=23;
            ++p->prime[cnt].power;
            n=n/23;
        }while(n%23==0);
        ++p->nPrimes;    
        ++cnt;
    }
    
    if(n%29==0)
    {
        do
        {
            p->prime[cnt].prime=29;
            ++p->prime[cnt].power;
            n=n/29;
        }while(n%29==0);
        ++p->nPrimes;    
        ++cnt;
    }
    
    if(n%31==0)
    {
        do
        {
            p->prime[cnt].prime=31;
            ++p->prime[cnt].power;
            n=n/31;
        }while(n%31==0);
        ++p->nPrimes;    
        ++cnt;
    }
    
    if(n%37==0)
    {
        do
        {
            p->prime[cnt].prime=37;
            ++p->prime[cnt].power;
            n=n/37;
        }while(n%37==0);
        ++p->nPrimes;    
        ++cnt;
    }
    
    if(n%41==0)
    {
        do
        {
            p->prime[cnt].prime=41;
            ++p->prime[cnt].power;
            n=n/41;
        }while(n%41==0);
        ++p->nPrimes;    
        ++cnt;
    }
    
    if(n%43==0)
    {
        do
        {
            p->prime[cnt].prime=43;
            ++p->prime[cnt].power;
            n=n/43;
        }while(n%43==0);
        ++p->nPrimes;    
        ++cnt;
    }    
    
    if(n%47==0)
    {
        do
        {
            p->prime[cnt].prime=47;
            ++p->prime[cnt].power;
            n=n/47;
        }while(n%47==0);
        ++p->nPrimes;    
        ++cnt;
    }
      
    if(n%53==0)
    {
        do
        {
            p->prime[cnt].prime=53;
            ++p->prime[cnt].power;
            n=n/53;
        }while(n%53==0);
        ++p->nPrimes;    
        ++cnt;
    }
     
    if(n%59==0)
    {
        do
        {
            p->prime[cnt].prime=59;
            ++p->prime[cnt].power;
            n=n/59;
        }while(n%59==0);
        ++p->nPrimes;    
        ++cnt;
    }
       
    if(n%61==0)
    {
        do
        {
            p->prime[cnt].prime=61;
            ++p->prime[cnt].power;
            n=n/61;
        }while(n%61==0);
        ++p->nPrimes;    
        ++cnt;
    }
    
    if(n%67==0)
    {
        do
        {
            p->prime[cnt].prime=67;
            ++p->prime[cnt].power;
            n=n/67;
        }while(n%67==0);
        ++p->nPrimes;    
        ++cnt;
    }
    
    if(n%71==0)
    {
        do
        {
            p->prime[cnt].prime=71;
            ++p->prime[cnt].power;
            n=n/71;
        }while(n%71==0);
        ++p->nPrimes;    
        ++cnt;
    }
       
    if(n%73==0)
    {
        do
        {
            p->prime[cnt].prime=73;
            ++p->prime[cnt].power;
            n=n/73;
        }while(n%73==0);
        ++p->nPrimes;    
        ++cnt;
    }
       
    if(n%79==0)
    {
        do
        {
            p->prime[cnt].prime=79;
            ++p->prime[cnt].power;
            n=n/79;
        }while(n%79==0);
        ++p->nPrimes;    
        ++cnt;
    }
     
    if(n%83==0)
    {
        do
        {
            p->prime[cnt].prime=83;
            ++p->prime[cnt].power;
            n=n/83;
        }while(n%83==0);
        ++p->nPrimes;    
        ++cnt;
    }
    
    if(n%89==0)
    {
        do
        {
            p->prime[cnt].prime=89;
            ++p->prime[cnt].power;
            n=n/89;
        }while(n%89==0);
        ++p->nPrimes;    
        ++cnt;
    }
    
    if(n%97==0)
    {
        do
        {
            p->prime[cnt].prime=97;
            ++p->prime[cnt].power;
            n=n/97;
        }while(n%97==0);
        ++p->nPrimes;    
        ++cnt;
    }
    
    if(n!>1)              //if n is greater than 1 
    {
        p->prime[cnt].prime=n;  //
        p->prime[cnt].power=1;
        ++p->nPrimes;
    }

    return p;
}

void prntPrm(Primes *p)
{
    
    if(p->nPrimes>1|| p->prime[0].power>1)
    {
        cout<<" Can be factored by "<<(int)p->nPrimes<<" prime numbers."<<endl;
        for(int x=0; x<p->nPrimes; ++x)
        {
            cout <<" ";
            cout << p->prime[x].prime << "^";
            cout << (int)p->prime[x].power;
            if(x!=p->nPrimes-1)
                cout << " *";        
        }
    }
    else
        cout << " Is already a prime number silly :p!";
}