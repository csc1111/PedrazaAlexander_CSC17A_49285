/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Created on 17 September 2020
 * Purpose:  Even, Odd Vectors and Array Columns Even, Odd
 * Note:  Check out content of Sample conditions in Hacker Rank
 * Input size of integer array, then array, output columns of Even, Odd
 * Vectors then Even, Odd 2-D Array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <vector>  //vectors<>
#include <iomanip> //Format setw(),right
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=2;//Only 2 columns needed, even and odd

//Function Prototypes Here
void read(vector<int> &, vector<int> &);
void copy(vector<int>, vector<int>,int [][COLMAX]);
void prntVec(vector<int>, vector<int>,int);//int n is the format setw(n)
void prntAry(const int [][COLMAX],int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //No more than 80 rows
    int array[ROW][COLMAX];     //Really, just an 80x2 array, even vs. odd
    vector<int> even(0),odd(0); //Declare even,odd vectors
    
    //Input data and place even in one vector odd in the other
    read(even,odd);
    
    //Now output the content of the vectors
    //          setw(10)
    prntVec(even,odd,10);//Input even, odd vectors with setw(10);
    
    //Copy the vectors into the 2 dimensional array
    copy(even,odd,array);
    
    //Now output the content of the array
    //                              setw(10)
    prntAry(array,even.size(),odd.size(),10);//Same format as even/odd vectors
    
    //Exit
    return 0;
}

/****************************************************************************
 *read
 * Reads numbers into the odd or even vector dependent on the number
 ****************************************************************************/
void read(vector<int> &even, vector<int> &odd)
{
    int arSz;       //User input for array size
    int num;        //User input for numbers in array
    
    cout << "Input the number of integers to input.\n";
    cout << "Input each number.\n";
    cin >> arSz;                    //user inputted array size             
   
    for(int x = 0; x < arSz; ++x)
    {    
        cin >> num;                 //user inputted number
   
        if(num % 2 == 0)            //if the number can be divided by 2 then            
            even.push_back(num);    //place in even
        else                        //if number is not divisible by 2 its odd
            odd.push_back(num);
    }

}

/****************************************************************************
 *prntVec
 * outputs the numbers in the vector.
 ****************************************************************************/
void prntVec(vector<int> even, vector<int> odd, int n)
{
   cout << "    Vector      Even       Odd" << endl;
   
   if(even.size() > odd.size())             //If even is greater use its size
    {                                       //for the for loop
        for(int x = 0; x < even.size(); ++x)
        {
            cout << setw(20) << even.at(x) << setw(n);
            if(x < odd.size())
                cout << odd.at(x) << endl;
            else                                //when x is greater than odd
                cout << " " << endl;            //leave an empty space
        }
    }
   
   else                                     //if odd is greater use its size
   {                                        //for the for loop
       for(int x = 0; x < odd.size(); ++x)
        {
            if(x < even.size())
                cout << setw(20) << even.at(x) << setw(n);
            else                                   //when x is greater than the
                cout << setw(20) << " " << setw(n);//size of even leave empty 
            cout << odd.at(x) << endl;             //space
                   
        }
   }
   
}
   
/****************************************************************************
 *copy
 * copies vector even into arr[][COLMAX-1] and vector odd into arr[][COLMAX]
 ****************************************************************************/
void copy(vector<int> even, vector<int> odd,int arr[][COLMAX])
{
    for(int x = 0; x < even.size(); ++x)    //fills in arr[][COLMAX-1] using
        arr[x][COLMAX-1] = even.at(x);      //vector even
    for(int x = 0; x < odd.size() ; ++x)    //fills in arr[][COLMAX] using
        arr[x][COLMAX] = odd.at(x);         //vector odd
}

/****************************************************************************
 *prntAry
 * outputs the numbers in arr[][COLMAX-1] and arr[][COLMAX]
 ****************************************************************************/
void prntAry(const int arr[][COLMAX],int eSz,int oSz, int n)
{
    cout << "     Array      Even       Odd\n";
    
    if(eSz > oSz)                       //if even size is greater than odd size
    {
        for(int x = 0; x < eSz; ++x)
        {
            cout << setw(20) << arr[x][COLMAX-1] << setw(n);
            if(x < oSz)
                cout << arr[x][COLMAX] << endl;
            else                        //if x is greater or equal to odd size
                cout << " " << endl;    //output a blank space
        }
    }
    
    else
    {
       for(int x = 0; x < oSz; ++x)
        {
                      
            if(x < eSz)
                cout << setw(20) << arr[x][COLMAX-1] << setw(n);
            else                                    //if x is greater than or 
                cout << setw(20) << " " << setw(n); //equal to even size then
                                                    //output a blank space
            cout << arr[x][COLMAX] << endl; 
        }
    }
}