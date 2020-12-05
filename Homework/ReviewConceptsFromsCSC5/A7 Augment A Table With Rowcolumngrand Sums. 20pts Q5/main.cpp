/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Created on 9/17/2020
 * Purpose:  Sum Rows, Sum Columns, Grand Sum of an integer array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <iomanip> //setw(10)
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;  //Max Columns much larger than needed.

//Function Prototypes Here
void read(int [][COLMAX],int &,int &);//Prompt for size then table
void sum(const int [][COLMAX],int,int,int[][COLMAX]);//Sum rows,col,grand total
void print(const int [][COLMAX],int,int,int);//Either table can be printed

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //Max Rows much larger than needed
    int array[ROW][COLMAX]={};  //Declare original array
    int augAry[ROW][COLMAX]={}; //Actual augmented table row+1, col+1
    int row,col;                
    
    //Input the original table
    read(array,row,col);
    
    //Augment the original table by the sums
    sum(array,row,col,augAry);
    
    //Output the original array
    cout<<endl<<"The Original Array"<<endl;
    print(array,row,col,10);//setw(10)
    
    //Output the augmented array
    cout<<endl<<"The Augmented Array"<<endl;
    print(augAry,row+1,col+1,10);//setw(10)
    
    //Exit
    return 0;
}

/****************************************************************************
 *read 
 * Reads the size of the column and rows provided by the user then takes user
 * input for the numbers in the array.
 ****************************************************************************/
void read(int array[][COLMAX], int& row, int& col)
{
    cout << "Input a table and output the Augment row,col and total sums.\n";
    cout << "First input the number of rows and cols. <20 for each\n";
    cin >> row;                         //user input row
    cin >> col;                         //user input column
    cout << "Now input the table.\n";

    for (int i = 0; i < row; ++i)       //for loop for rows
    {
        for (int j = 0; j < col; ++j)   //for loop for columns
            cin >> array[i][j];
    }
}

/****************************************************************************
 *sum 
 * Finds the sum of the numbers in a row and the sum of the columns. After it
 * finds the total sum of the array
 ****************************************************************************/
void sum(const int array[][COLMAX], int row, int col, int augAry[][COLMAX])
{
    int rowSum;                     //sum of a row
    int colSum;                     //sum of a column
    int total = 0;                  //sum of all the columns and rows

    for (int i = 0; i < row; i++)
    {
        rowSum = 0;

        for (int j = 0; j < col; j++)
        {

            augAry[i][j] = array[i][j]; //puts numbers into aug array
            total += array[i][j];       //finds total of the array
            rowSum += array[i][j];      //finds the sum of a row
        }

        augAry[i][col] = rowSum;        //Makes the last rows equal to rowSum
    }

    for (int j = 0; j < col; ++j)       
    {
        colSum = 0;

        for (int i = 0; i < row; ++i)
        {
            colSum += array[i][j];      //finds the sum of a column
        }

        augAry[row][j] = colSum;        //makes the last column equal to colSum
    }

    augAry[row][col] = total;       //makes the last column and row of the array
                                    //equal to the total 
}

/****************************************************************************
 *print 
 * Prints the original array and the augmented array.
 ****************************************************************************/
void print(const int array[][COLMAX], int row, int col, int width)
{
    for (int i = 0; i < row; ++i)               //for loop for the rows
    {
        for (int j = 0; j < col; ++j)           //for loop for the columns
            cout << setw(width) << array[i][j]; //outputs array in row i column
        cout << endl;                           //j
    }
}

