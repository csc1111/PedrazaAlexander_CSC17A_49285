  
/* 
 * Author: Alexander Pedraza
 * Created on oct 25th, 2020, 10:48 pm
 * Purpose:  Project 1- game of bloack jack.
 *
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <stdio.h>
#include <iomanip>

using namespace std;

enum ops
{
    hit, stand, doubledown
};
struct card
{
    string num;         //card
    string sut;      //suits 1=spades 2=clubs 3=diamonds 4=hearts
    int val;            //Value of the card
};

card *cardSet(int );                //sets deck
void game(card *, int);             //plays game
void dc(card *d, int cards);        //shows deck
card *shuffle(card *,int );         //shuffles deck
int hands(card *, bool, int );      //shoes player and dealer hands
card *cut(card *, int );            //cuts cards
        
int main(int argc, char** argv) 
{
    int cards = 53;
    card *set;
    set = cardSet(cards);
    game(set, cards);
    
    delete[] set;
    return 0;
}

/*************************************************
 *  cardSet sets up the card deck by assigning face
 * suit and value
 *************************************************/
card *cardSet(int cards)
{

    int val = 1;
    int su = 1;
    card *set = new card[cards];

    for(int x=1; x<cards; ++x)
    {
        if(x==1||x==14||x==27||x==40)
            set[x].num="ACE";
        else if(x==2||x==15||x==28||x==41)
            set[x].num="Two ";
        else if(x==3||x==16||x==29||x==42)
            set[x].num="Three";
        else if(x==4||x==17||x==30||x==43)
            set[x].num="Four";
        else if(x==5||x==18||x==31||x==44)
            set[x].num="Five";
        else if(x==6||x==19||x==32||x==45)
            set[x].num="Six";
        else if(x==7||x==20||x==33||x==46)
            set[x].num="Seven";
        else if(x==8||x==21||x==34||x==47)
            set[x].num="Eight";
        else if(x==9||x==22||x==35||x==48)
            set[x].num="Nine";
        else if(x==10||x==23||x==36||x==49)
            set[x].num="Ten";
        else if(x==11||x==24||x==37||x==50)
            set[x].num="Jack";
        else if(x==12||x==25||x==38||x==51)
            set[x].num="Queen";
        else if(x==13||x==26||x==39||x==52)
            set[x].num="King";    
    }

    
    for(int x=1; x<cards; ++x)
    {
        set[x].val=val;    
        ++val;
        if(val==10)
        {
            for(int y=0; y<4; ++y)
            {
                ++x;
                set[x].val=val;
            }
            val=1;
        }   
    }
    
    for(int x=1; x<14; ++x)
        set[x].sut="Spades";
    for(int x=14; x<27; ++x)
        set[x].sut="Clubs";
    for(int x=27; x<40; ++x)
        set[x].sut="Diamonds";
    for(int x=40; x<53; ++x)
        set[x].sut="Hearts";    
    
    //cut card set
    set[0].num="cut card";
    set[0].sut="0";
    set[0].val=0;
    
   
    return set;
}

void game(card *d, int cards)
{

    int mn;                    //total player money
    int bet;                    //bet for game
    bool splt;                      //if player wnats to split
    bool ext=1;                   //leave game
    bool cht;                   //cheat
    bool sp=0;                    //if player split
    int crds=2;                   //cards the player has
    int dcrds=2;                  //cards the dealer has
    int ddcrd=6;                //cards dealt
    int dval;                   //dealer value
    int val[3];                 //value of cards
    int chce;                   //choice to hit stand or double down.
    int bett;                   //bet for second hand
    card* plyr = new card[9];   //players hand
    card* plyr2 = new card[9];  //players 2nd hand if split
    card* deal = new card[9];   //dealers hand
    
    do
    {
        cout << "How much money do you have in total(minimum bet $10): $";
        cin >> mn;
        if(mn <10&&mn!=0)
        {
            cout << "Minimum bet is 10$. Go to the Atm and come back.\n";
        }
        else if(mn==0)
            ext=0;
    }while(mn<10 && mn!=0);
    
    while(mn>10 || ext)
    {
        cout << "You have $"<<mn<<endl;
        cout << "Place your bet (must be a multiple of 10)(enter 0 to quit) :";
        cin >> bet;
        while(bet>mn&&bet!=0)
        {
            cout << "You can't afford that high of a bet. Try again(0 to quit):";
            cin >> bet;
        }
        while(bet<10&&bet!=0)
        {
            cout << "Minimum bet is 10. Place a higher bet(0 to quit):";
            cin >> bet;
        }
        while(bet%10!=0)
        {
            cout << "Bet must be a multiple of 10. Try again(0 to quit)";
            cin >> bet;
        }

        
        if(bet==0)      //game ends if player enters 0 as bet
            ext=0;
        else
        {
            d=shuffle(d, cards);
            cout<<"To cheat and view deck, press 1 else to not be a dirty cheat,"
                  " press '0': ";
            cin >> cht;
            if(cht)
                dc(d, cards);
            
            if(d[0].val==0)     //if the cut card is found the deck is cut and
            {                   //the cut card is skipped
                d=cut(d, ddcrd);
                ++ddcrd;
            }     
            plyr[0]=d[ddcrd];

            ++ddcrd;
            if(d[1].val==0)
            {
                d=cut(d, ddcrd);
                ++ddcrd;
            }
            deal[0]=d[ddcrd];
            
            ++ddcrd;
            if(d[2].val==0)
            {
                d=cut(d, ddcrd);
                ++ddcrd;
            }
            plyr[1]=d[ddcrd];
            
            ++ddcrd;
            if(d[3].val==0)
            {
                d=cut(d, ddcrd);
                ++ddcrd;
            }
            deal[1]=d[ddcrd];

            cout << " Dealers hand\n"<<"_________________________\n";
            hands(deal, 1, dcrds);
            cout << "\n Your cash\n"<<"_________________________\n";
            cout << "Current bet: $"<<bet<<endl;
            cout << "Your money: $"<<mn<<endl;
            cout << "Your Game\n" <<  "_________________________\n"; 
            hands(plyr ,0, crds);
            if (plyr[0].num=="ACE"&&plyr[1].val==10||plyr[1].num=="ACE"&&plyr[0].val==10)
            {
                cout << "!!!21!!!\n";
                mn += (bet/2)+bet;
                cout << "You made " << (bet/2)+bet<<endl;
            }
            else if(plyr[0].num==plyr[1].num&&mn>=bet*2)
            {
                cout<<"Would you like to split(1 for yes 0 for no)?: ";
                cin>>splt;
                if(splt)
                {
                    sp=1;
                    plyr2[0]=plyr[1];           //new hand. first card is one
                    ++ddcrd;                    //of the others
                    if(d[ddcrd].val==0)         
                    {
                        d=cut(d, ddcrd);
                        ++ddcrd;
                    }       
                    plyr2[crds]=d[ddcrd];       //second card dealt
                    bett=bet;                   //new bet added
                    cout << "Dealer\n___________\n";
                    hands(deal,1,dcrds);
                    cout << "Player hand 2\n____________\n";
                    hands(plyr2,0,crds);
                    do
                    {
                        cout << "Would you like to hit(1) stand(2) or double down(3): ";
                        cin >>chce;
                        if(chce==3)
                        {
                            bett*=2;                    //if they double down
                                                        //their bet is doubled
                            ++ddcrd;                    //and they can no longer
                            if(d[ddcrd].val==0)         //hit
                            {
                                d=cut(d, ddcrd);
                                ++ddcrd;
                            }                        
                            plyr2[crds]=d[ddcrd];
                            ++crds;
                            cout << "\nDealer\n___________\n";
                            dval=hands(deal,1,dcrds);
                            cout << "\nPlayer hand 2\n____________\n";
                            val[1]=hands(plyr2,0,crds);
                        }
                        else if(chce==1)
                        {
                            do
                            {
                                ++ddcrd;
                                if(d[ddcrd].val==0)
                                {                       //for cut card
                                    d=cut(d, ddcrd);
                                    ++ddcrd;
                                }  
                                plyr[crds]=d[ddcrd];        //card added
                                ++crds;

                                cout << "\nPlayer hand 1\n___________\n";
                                val[1]=hands(plyr,0,crds);
                                if(val[1]<21)
                                {
                                    cout <<"\nHit(1) or stand(2)?";
                                    cin >> chce;
                                    while(chce<1||chce>3)
                                    {
                                        cout <<"try again";     //validation
                                        cin >>chce;
                                    }
                                }
                                else if(val[1]==21)
                                    chce=2;         //if val is 12 no need to hit
                            }while(val[1]<22||chce!=2);
                        }
                        else if(chce==2)    //player stays
                        {
                            cout << "\nPlayer hand 2\n____________\n";
                            hands(plyr2,0,crds);                            
                            cout << "Final player card value is "<<val[1]<<endl;
                        }
                        else
                            cout <<"Wrong button try again.\n";
                    }while(chce<0&&chce>4);
                    if(val[1]>21)
                    {
                        cout << "You busted";
                        mn-=bett;
                    }
                    ++ddcrd;
                    if(d[ddcrd].val==0)
                    {                       //for cut card
                        d=cut(d, ddcrd);
                        ++ddcrd;
                    }  
                    plyr[1]=d[ddcrd];   //second card for next game dealt
                    crds=2;
                }   
            }
            else
            {
                cout << "Dealer\n___________\n";
                hands(deal,1,dcrds);
                cout << "Player hand 1\n____________\n";
                hands(plyr,0,crds);
                do
                {
                    cout << "Would you like to hit(1) stand(2) or double down(3): ";
                    cin >>chce;
                    if(chce==3)
                    {
                        bet*=2;     //bet doubles
                        
                        ++ddcrd;
                        if(d[ddcrd].val==0)
                        {
                            d=cut(d, ddcrd);
                            ++ddcrd;
                        }                        
                        plyr[crds]=d[ddcrd];
                        ++crds;
                        cout << "\nDealer\n___________\n";
                        dval=hands(deal,1,dcrds);
                        cout << "\nPlayer hand 1\n____________\n";
                        val[0]=hands(plyr,0,crds);
                    }
                    else if(chce==1)
                    {
                        do
                        {
                            ++ddcrd;
                            if(d[ddcrd].val==0)
                            {
                                d=cut(d, ddcrd);
                                ++ddcrd;
                            }
                            plyr[crds]=d[ddcrd];
                            
                            ++crds;

                            cout << "\nPlayer hand 1\n___________\n";
                            val[0]=hands(plyr,0,crds);
                            if(val[0]<21)
                            {
                                cout <<"\nHit(1) or stand(2)?";
                                cin >> chce;
                                while(chce<1||chce>3){
                                    cout <<"try again";
                                    cin >>chce;
                                }
                            }
                            else if(val[0]==21)
                                chce=2;
                        }while(val[0]<22||chce==1);
                    }
                    else if(chce==2)
                    {
                        cout << "\nPlayer hand 1\n____________\n";
                        val[0]=hands(plyr,0,crds);                            
                        cout << "Final player card value is "<<val[0]<<endl;
                    }
                    else
                        cout <<"Wrong button try again.\n";
                }while(chce<0&&chce>4);
                if(val[0]>21)           //if you go over 21
                {
                    cout << "You busted";
                    mn-=bet;
                }
                cout << "Dealer\n___________\n";
                dval=hands(deal,0,dcrds);
                cout << "Player hand 1\n____________\n";
                val[0]=hands(plyr,0,crds);
                if(sp)  //if there is a second game
                {
                    cout << "Player hand 2\n____________\n";
                    val[1]=hands(plyr2,0,crds);
                }

                if(val[0]<=21||val[1]<=21)      //when atleast one deck is under 21
                {
                    if(dval==21)                //if dval hit 21 before drawing
                    {                           //a card
                        if(val[0]<21)
                        {
                            mn-=bet;
                            cout <<"you lost"<<bet;
                        }
                        else if(dval==val[0])
                            cout <<"Draw";
                        if(sp)
                        {
                            if(val[1]<21)
                            {
                                mn-=bett;
                                cout << "you lost"<<bett;
                            }
                            else if(dval==val[1])
                               cout << "Draw" ;
                        }
                    }
                    while(dval<17)              //dealer has to draw under 17
                    {
                        if(d[ddcrd].val==0)
                        {
                            d=cut(d, ddcrd);
                            ++ddcrd;
                        }
                        ++ddcrd;
                        deal[dcrds]=d[ddcrd];
                        ++dcrds;

                        cout << "Dealer\n___________\n";
                        dval=hands(deal,0,dcrds);
                    }
                    if(dval>21)             //if the dealer busts
                    {                    
                        if(val[0]<=21)  //you still lose if you bust first
                        {
                            mn+=bet;
                            cout << "you won "<<bet;
                        }
                        if(sp)
                        {
                            if(val[1]<=21)
                            {
                                mn+=bett;
                                cout << "you won "<<bet;
                            }
                        }
                    }
                    else if(dval<=21)       //if the dealer doesnt bust
                    {
                        if(val[0]<dval)     //you have less
                        {
                            mn-=bet;
                            cout << "You lost "<<bet;
                        }
                        else if(val[0]==dval)       //you are equal
                        {
                            cout << "tie";
                        }
                        else if(val[0]>dval&&val[0]<22)
                        {
                            mn+=bet;
                            cout << "you won"<<bet;
                        }
                        if(sp)
                        {
                            if(val[1]<dval)
                            {
                                mn-=bett;
                                cout << "You lost"<<bett;
                            }
                            else if(val[1]==dval)
                            {
                                cout << "You tied";
                            }
                            else if(val[1]>dval&&val[1]<22)
                            {
                                mn+=bett;
                                cout << "You won"<<bett;
                            }
                        }

                    }
                }
            }
        }            
            
    }
    
    delete[]plyr2;
    delete[]plyr;
    delete[]deal;
}

/*********************************************************
 **outputs the card deck
 ****************************************************/
void dc(card *d, int cards)
{
    for(int x=0; x<cards; ++x)
    {
        cout << endl;
        cout << d[x].sut << " " << d[x].num << " " << d[x].val << endl;
    }
}

/********************************************************
 * shuffles deck randomly
 ****************************************/
card *shuffle(card *d, int cards)
{
    card temp;      //temporarily holds card
    int m;          //random number
    srand(time(0));
    for(int n=0; n<cards;++n)
    {
        m=rand()%53;    //takes random number between 0 and 53
        temp=d[n];
        d[n]=d[m];
        d[m]=temp;
    }

   return d;
}

//**************************************************************///////////
//cut allows user to cut the cards when the cut card appears in the deck///
/*************************************************************////////////

card *cut(card *d, int dcrd)
{
    int num;
    card *temp = new card[53];
    cout << "CUT CARDDDD\n";
    cout << "where should it go? pick number between: "<<dcrd <<" and 52:";
    cin >> num;                 //where to cut
    int y=dcrd+1;
    
    //swaps from user num to 53 and adds it on top of everything under num
    for(int x=num+dcrd; x<53; ++x)
    {
        temp[y]=d[x];              
        ++y;
    }
    for(int x=dcrd+num-1; x>dcrd; x--)
    {
        temp[y]=d[x];
        ++y;
    }
    return temp;   
    
}


/********************************************************************
 *  hands outputs the player and dealers hand while also calculating 
 *  value
 ********************************************************************/
int hands(card *p, bool y, int c)
{
    int val=0;
    int acnt; //count for aces
    for(int x=0; x<c;++x)
    {
        cout << "*==========*\n";

        cout<<"|"<<p[x].num<<endl;
        cout<<"|"<<p[x].sut<<endl;
        val+=p[x].val;                  //calculates value of cards added
        
        if(y)
        {
            cout << "*==========*\n\n";
            cout << "*==========*\n";
            cout << "|HIDDEN CARD|\n";
            x+=c;                       //dealer hides second card till its 
        }                               //his turn
        if(p[x].num=="ACE")
        {
            ++acnt;
        }
        cout << "*==========*\n\n";
    }
    if(val<=21)
    {
        if(acnt>1&&val+10<=21)
              val+=10;          //when able to Ace will=11 instead of 10
    }
    if(val>=22)
        cout<< "bust\n";
    cout << "card values="<<val;    //card values
    cout << endl;
    return val;
}

