/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Created on September 7th, 2020, 7:04 PM
 * Purpose: number analysis program
 *          
 */


//System Libraries
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//FUNCTION PROTOTYPES
int getLow(vector<int>, int);   //function for lowest 
int getHigh(vector<int>, int);  //function for highest
int getSum(vector<int>, int);   //function for sum
float getAve(vector<int>, int); //function for average

//Execution of Code Begins Here
int main(int argc, char** argv) 
{
    //Declare all variables for this function
    vector<int> numbers;    //vector for numbers
    string fl;              //file name
    int fnum;               //numbers from file
    int low;                //lowest number in file
    int hgh;                //highest number in file
    int tot;                //sum of all numbers
    float ave;              //average of all numbers

    //Initialize all known variables
    int count = 0;    
    
    cout << "Please Enter File Name ('numbers.txt'): ";
    getline(cin,fl);
    
    ifstream inputFile(fl);
    
    if (!inputFile)
    {
        cout << "ERROR: File Not Found" << endl;
        return 0;
    }
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives    
    while (inputFile >> fnum){
        numbers.push_back(fnum);
        ++count;
    }
    
   //Display the Inputs/Outputs    
    cout << "Smallest number in file is: ";
    low = getLow(numbers, count);
    cout << low << endl;
    
    cout << "largest number in file is: ";
    hgh = getHigh(numbers, count);
    cout << hgh << endl;
    
    cout << "Sum of all numbers in file is: ";
    tot = getSum(numbers, count);
    cout << tot << endl;
    
    cout << "The average of all numbers is: ";
    ave = getAve(numbers, count);
    cout << ave << endl;
    
    
    //Clean up the code, close files, deallocate memory, etc....
    //Exit stage right    
    return 0;
}

int getLow(vector<int> numbers, int count){
    int low = numbers[0];
    for (int i=1; i < count; ++i)
    {
        if(low>numbers[i])
        {
            low=numbers[i];
        }
    }
    return low;
}

int getHigh(vector<int> numbers, int count){
    int hgh = numbers[0];
    for (int i=1; i < count; ++i)
    {
        if(hgh<numbers[i])
        {
            hgh=numbers[i];
        }
    }
    return hgh;
}

int getSum(vector<int> numbers, int count){
    int tot;
    for(int i=0; i < count; ++i)
        tot += numbers[i];          //adds the sum of all numbers
    return tot;
}

float getAve(vector<int> numbers, int count){
    float ave;
    ave = getSum(numbers, count);   //finds sum 
    ave/=count;                     //finds average of all numbers
    return ave;
}

