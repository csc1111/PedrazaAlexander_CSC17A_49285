/* 
 * File: Structures Movie Data
 * Author: Alexander Pedraza
 * Created on 10/11/2020
 * Purpose: finds movie data
 */

#include <iostream>
#include <iomanip>

using namespace std;

struct mdata                    //Movie data
{
    string ttl;         //Movie Title
    string drctr;       //Directors Name
    int yr;             //Year released
    int rt;             //Movie Runtime
};


mdata *fill(int);               //User fills in array
void prnt(const mdata *, int);  //prints elements of mdata array

int main()
{
    int nmv;            //number of movies
    
    cin >> nmv;         
    cin.ignore();
    
    mdata *mv=fill(nmv);
    prnt(mv, nmv);
    
    delete []mv;        //deletes dynamically allocated array
    return 0;
}

mdata *fill(int nm)
{
    mdata *mv = new mdata[nm];  //dynamically allocates array for movie data
                                //depending on user input
    
    for(int x=0; x<nm; ++x)
    {
        getline(cin, mv[x].ttl);        //Movie title
        getline(cin,mv[x].drctr);       //Director
        cin >> mv[x].yr;                //Release Year
        cin >> mv[x].rt;                //Runtime
        cin.ignore();
    }

    return mv;
}

void prnt(const mdata *m, int nm)
{
    cout << "This program reviews structures\n";
    cout << "Input how many movies, the Title of the Movie, Director, Year "
            "Released, and the Running Time in (minutes).\n";
    for(int x=0; x<nm; ++x)
    {
        cout << endl;
        cout << left << setw(11) << "Title:";
        cout << m[x].ttl << endl;
        
        cout << left << setw(11) << "Director:";
        cout << m[x].drctr << endl;
        
        cout << left << setw(11) << "Year:";
        cout << m[x].yr << endl;
        
        cout << left << setw(11) << "Length:";
        cout << m[x].rt << endl;
    }
}