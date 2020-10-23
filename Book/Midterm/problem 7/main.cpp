/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Purpose:  Find all prime factors
 *           
 */

#include <iostream>


using namespace std;
struct Prime{
	unsigned short prime;
	unsigned char power;
};
struct Primes{
	unsigned char nPrimes;
	Prime *prime;
};

Primes *factor(int);
void prntPrm(Primes *);

int main(int argc, char** argv) 
{
    Primes *prime;      //pointer to struct 
    int n;              //number
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
