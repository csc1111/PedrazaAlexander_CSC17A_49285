/* 
 * File: array/file function
 * Author: Alexander Pedraza
 * Created on 10/15/2020
 * Purpose: write array into binary file and return to new array
 */

#include <iostream>
#include <fstream>


using namespace std;

/*
 * 
 */
void atf(string, char *, int ars);   //array to file
void fta(string, char *, int ars);   //file to array

int main(int argc, char** argv) 
{

    const int SIZE = 4;                         //array size
    char data[SIZE]= {'A', 'B', 'C', 'D'};      //first array
    char dat[SIZE];                             //second array written into
    string of;                                  //file name
    
    cout << "Enter output file name: ";
    cin >> of;
    
    atf(of, data, SIZE);
    fta(of, dat, SIZE);

    for(int x=0; x<SIZE; ++x)
        cout << dat[x];         //outputs second array
    
    return 0;
}

void atf(string o, char *data, int ars)
{
    fstream file;
    //open file for output in binary mode.
    file.open(o, ios::out | ios::binary);
    
    //write contents of array into file.
    cout << "Writing the char's to the file.\n";
    file.write(data, ars);                      //writes array into file
    
    //close file
    file.close();
}

void fta(string o, char *data, int ars)
{
    fstream file;
    //Open file for input in binary mode.
    cout << "now reading the data back into memory\n";
    file.open(o, ios::in | ios::binary);
    file.read(data, ars);                       //writes file into array
    
    file.close();
}