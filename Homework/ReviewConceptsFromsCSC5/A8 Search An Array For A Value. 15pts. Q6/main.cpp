/* 
 * File:   main.cpp
 * Author: Alexander Pedraza
 * Created on 9/17/2020
 * Purpose:  Searching for multiple occurrence of patterns
 * Note:  cout proceeds to null terminator, cin reads to end of line
 *        for character arrays
 * 
 */

//System Libraries Here
#include <iostream>//cin,cout,getline()
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//PI, e, Gravity, or conversions

//Function Prototypes Begins Here
//srch1 utility function Input->start position, Output->position found or not
//srch1 is a simple linear search function, repeat in srchAll till all found
//srch1 Input->sentence, pattern, start position Output-> position found
//Remember arrays start at index/position 0
//srchAll Input->sentence, pattern Output->position array
int  srch1(const char [],const char [],int);//Search for 1 occurrence
void srchAll(const char [],const char [],int []);//Search for all occurrences
void print(const char []);//Print the character arrays
void print(const int []); //Print the array of indexes where the pattern found

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int LINE=81;               //Size of sentence or pattern to find
    char sntnce[LINE],pattern[LINE]; //80 + null terminator
    int match[LINE];                 //Index array where pattern was found
    
    //Input a sentence and a pattern to match
    cout<<"Match a pattern in a sentence."<<endl;
    cout<<"Input a sentence"<<endl;
    cin.getline(sntnce,LINE);
    cout<<"Input a pattern."<<endl;
    cin.getline(pattern,LINE);
    
    //Search for the pattern
    //Input the sentence and pattern, Output the matching positions
    //Remember, indexing starts at 0 for arrays.
    srchAll(sntnce,pattern,match);
    
    //Display the inputs and the Outputs
    cout<<endl<<"The sentence and the pattern"<<endl;
    print(sntnce);
    print(pattern);
    cout<<"The positions where the pattern matched"<<endl;
    print(match);
    
    //Exit
    return 0;
}


/*****************************************************************************
 *srchAll
 * Searches array sntnce for the first letter in array pattern. If it finds none
 * the function will end with -1 in all of matches elements. If one is found 
 * it's position will be sent to function srch1 and it's next chars will be 
 * tested against the next part of sntnce. If it returns 0 then the index is not
 * saved and pattern[0] will be tested with the next index. If it returns 1 it 
 * will be saved into match[pos]. After all of sntnce has been tested with 
 * pattern[0], every element in match that was not filled will become -1.
 *****************************************************************************/
void srchAll(const char sntnce[], const char pattern[], int match[])
{
    int index = 0;              //Position where 
    int pos = 0;                //Element of match
    int len = strlen(sntnce);   //Length of sntnce 
    bool chk;                   //If found yes or no
    int tmp;                    //temporarily holds index
    
    do
    {
        chk=0;
        for(int x=index; x<len; ++x)    //loops till it reaches sntnce length
        {
            if(pattern[0]==sntnce[x])   //compares the first element of pattern
            {                           //with sntnce[x]
                index=x;                //if a match is found index will be x
                x=len;                  //if a match is found x will become len
            }                           //and the for loop will end
            else
                index=len;              //if nothing was found index will equal
        }                               //len
        
        if(index<len)                           //runs if index was found
            chk = srch1(sntnce, pattern, index);
        
        if(chk)                         //if the pattern tested matched
        {
            match[pos]=index;           //match[pos] becomes index
            ++pos;                      //pos is ready for next index
        }

        index++;            //index will move up one to skip last index checked
        
    }while(index<len);      //once every element of sntnce has been compared to 
                            //the first element of pattern the loop ends
    
    for(int x=pos; x<81; ++x)   //elements that don't have inputted numbers 
        match[x] = -1;          //become -1.

}

/*****************************************************************************
 *srch1
 * If the first letter of pattern was found in sentence it will test to see
 * if the next letters in pattern match the next letters in sentence. If it 
 * does it will return a bool 1. if it does not it will return a 0.
 *****************************************************************************/
int srch1(const char sntnce[], const char pattern[], int index)
{
    int lens = strlen(pattern);     //length of array pattern
    int x=index;                    //holds number for index
    bool y=1;                       //decides if pattern matches 
        for(int y=1; y<lens; ++y)   //loops to the size of pattern
        {       
            ++x;                        //adds 1 to x to test number after index
            if(pattern[y]!= sntnce[x])  //if pattern[y] and sntnce[x] don't 
                y=0;                    //match, y becomes 0 indicating it did 
        }                               //not match
    
    return y;
}

/*****************************************************************************
 *print
 * outputs char array entered into the function.  
 *****************************************************************************/
void print(const char sntnce[])
{
    int len = strlen(sntnce);   //length of array sntnce
    
    for(int x=0;x<len;++x)      //loops till x reaches len
        cout << sntnce[x];      //outputs sntnce[x]
    
    cout << endl;
}

/*****************************************************************************
 *print
 * outputs the int array match[]. If match[0] is -1 "None" is outputted. It is 
 * impossible for there to naturally be a negative 1 in the function therefore
 * no other unused elements in array match will be shown.
 *****************************************************************************/
void print(const int match[])
{
    if(match[0]!=-1)            //if the first match has a number thats not -1
    {
        for(int x=0;x<81;++x)
        {
            if(match[x]>-1)
                cout << match[x] << endl;  //outputs position of the matches      
            else
                x+=81;                 //when end last number is found loop ends
        }
    }
    else
        cout << "None" <<endl;  //outputs none if nothing was found

}