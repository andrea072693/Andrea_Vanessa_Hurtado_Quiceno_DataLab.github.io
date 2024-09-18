#include <iostream>
#include "Plateau.h"
#include <vector>
#include <cstdlib>
#include <unistd.h>
using namespace std;


Plateau::Plateau(std::vector<Joueur*> players_): // Now it has the acces to the players.
    players{players_}
{

    Case* c1= new Depart( 1, 500, players_);// as a constructor,

    Case* c2= new Property( 2, 200,0);// as a constructor,
    Case* c3= new Property( 3, 100,0);// as a constructor,
    Case* c4= new Property( 4, 50,0); // as a constructor,
    Case* c5= new Gare( 5, 75 );// as a constructor,
    Case* c6= new Chance( 6, 0);// as a constructor,
    Case* c7= new Property( 7, 150,0);// as a constructor,
    Case* c8= new Property( 8, 50,0);// as a constructor,
    Case* c9= new Property( 9, 100,0);// as a constructor,
    Case* c10= new Prison( 10);// as a constructor,


    Case* c11= new Property( 11, 200,0);// as a constructor,
    Case* c12= new Chance( 12, 0);// as a constructor,

    Case* c13= new Property( 13, 100,0);// as a constructor,
    Case* c14= new Property( 14, 100,0);// as a constructor,
    Case* c15= new Property( 15, 50,0);// as a constructor,
    Case* c16= new Gare( 16, 75);// as a constructor,
    Case* c17= new Chance( 17, 0);// as a constructor,
    Case* c18= new Property( 18, 150,0);// as a constructor,
    Case* c19= new Property( 19, 300,0);// as a constructor,
    Case* c20= new Property( 20, 350,0);// as a constructor,
    Case* c21= new Policier(21,c10);// as a constructor,

    Case* c22= new Property( 22, 50,0);// as a constructor,

    // in the element number zero
    grille.push_back(c1);
    grille.push_back(c2);
    grille.push_back(c3);
    grille.push_back(c4);
    grille.push_back(c5);
    grille.push_back(c6);
    grille.push_back(c7);
    grille.push_back(c8);
    grille.push_back(c9);
    grille.push_back(c10);
    //////
    grille.push_back(c11);
    grille.push_back(c12);

    grille.push_back(c13);
    grille.push_back(c14);
    grille.push_back(c15);
    grille.push_back(c16);
    grille.push_back(c17);
    grille.push_back(c18);
    grille.push_back(c19);
    grille.push_back(c20);
    grille.push_back(c21);
    grille.push_back(c22);

    /// Constructor for the aleatory function:
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    generator = std::default_random_engine(seed);


    // Is a pointer for Case:

    gares.push_back(c5);
    gares.push_back(c16);


}

Plateau::~Plateau()
{
    //dtor
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
//definition of the function that display the Plateau:

void Plateau::displayPlateau()
{
//This is to update the Board.
    system("clear");



// and for every player, which he is on, by knowing the position, goes to tje appropiate cell to ,
// to give its own memory address to the player of turn



// Here I need to make the for loop:
    for(Case* x:grille)
    {
        if (x-> get_caseNumber()<=10 )
            x->displaceFirstLine();
    }
    cout << endl;
/////
    for(Case* x:grille)
    {
        if (x-> get_caseNumber()<=10 )
            x->displaceSecondLine();

    }

    cout << "|" << endl;
/////
    for(Case* x:grille)
    {
        if (x-> get_caseNumber()<=10 )
            x->displaceThirdLine();
    }

    cout <<  "|" << endl;
/////
    for(Case* x:grille)
    {
        if (x-> get_caseNumber()<=10 )
            x->displaceFourthLine();
    }

    cout <<  "|" << endl;

    for(Case* x:grille)
    {
        if (x-> get_caseNumber()<=10 )
            x->lastLine();
    }
    cout  << endl;

///////////////////////// Second line:

    grille[21] -> displaceSecondLine() ; // is pointer of Case
    cout << "|                                               " ;
    grille[10] ->displaceSecondLine()  ;
    cout << "|"<< endl;

////////////////////

    grille[21] -> displaceThirdLine();
    cout << "|                                               " ;
    grille[10] ->displaceThirdLine();
    cout << "|"<< endl;

////////////////////

    grille[21] -> displaceFourthLine();
    cout << "|                                               ";
    grille[10] -> displaceFourthLine();
    cout << "|"<< endl;


///////////////////////////////////// Third  line:
// I have to use the reverse for:

    for(Case* x:grille)
    {
        if (x-> get_caseNumber()<=10 )
            x->displaceFirstLine();
    }
    cout <<endl;

////////

    for(int i=20 ; i>=11 ; i--)
    {

        grille[i]->displaceSecondLine();

    }


    cout << "|" << endl;



    for(int i=20 ; i>=11 ; i--)
    {

        grille[i]->displaceThirdLine();

    }


    cout << "|" << endl;

    for(int i=20 ; i>=11 ; i--)
    {

        grille[i]->displaceFourthLine();

    }


    cout << "|" << endl;



    for(int i=20 ; i>=11 ; i--)
    {

        grille[i]->lastLine();

    }


    cout << endl;

    for(int i=0; i< players.size(); i++)
    {

        cout << players[i]->get_nom() << " is in " << players[i]->get_position() << " : " << "Actual budget is  "  << players[i]->get_budget() << endl;


    }






}

///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
void Plateau::updateJoueur( Joueur* player )
{


//turn of the player:
//the player is free
    if (player->get_turnInJail()==0)
    {

        int newPos= dice_toss() + player->get_position();

        if(newPos>22)
        {

            newPos-=22; //to not going beyond our boundary

            int newBudget= player->get_budget();
            newBudget +=200;
            player->set_budget(newBudget);

            cout << "The player" << player->get_nom() << "got 200 from the depart case !!!" << endl;
        }

        int oldPos=player->get_position(); //
        player->deplacement(newPos);

        // delete the player from its old cell and change it to the new cell:
        grille[oldPos-1]->remove_playersOfTurn(player);
        grille[newPos-1]->add_playersOfTurn(player);






    }
// the player is in Jail:
    else
    {

// the following three lines is to drecrease the values of turns in Jail from 3 to 1:
        int turnJail=player->get_turnInJail();

        turnJail--;

        player->set_turnInJail(turnJail);


//another way to make the player means:

        if(dice_toss()==6 && turnJail!=0 )
        {

            cout << "You are free since you got a number 6 " << endl;

            player->set_turnInJail(0);

        }

        else
        {

            cout << "You have to wait " << turnJail << " turns " << endl;

        }

    }







    displayPlateau();



}


//////////////////////////////////////////////////////////////////////////////////////////////////////
void Plateau::specificAction(Joueur* player)
{

//call the action
    int  pos= player->get_position();

    grille[pos-1]->action(player);   //which cell we are going to call, and call action with that player.


}
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////

//
//// First function that define the aleatory:

int Plateau::card_pick(int nb_cartes)
{
    std::uniform_int_distribution<int> card_distribution(1, nb_cartes);// start of the interval and the end.

    return card_distribution(generator);
}

/////////////////////////////////////////////
int Plateau::dice_toss()
{
//    int yourdice;
//    cout << "Give the dice number " << endl;
//    cin >> yourdice;


    // return yourdice;

    return card_pick(6);

}

///////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
void Plateau::numberGaresOwn()
{

//makes sures to continue with the code or not,
    if(doubled==true)
    {
        //kill the function
        return;
    }
//comparing th e gare number i:

    for(int i=0; i < gares.size()-1; i++)
    {
        if(gares[i]->get_proprietaire()==nullptr || gares[i+1]->get_proprietaire()==nullptr) // (to make sure i+1, reaches the last cell, unreacheble by i).
        {
            cout << "NOT all gare are own by the same person " << endl;
            return;
        }



        if(gares[i]->get_proprietaire()!=gares[i+1]->get_proprietaire())
        {

            cout << "NOT all gare are own by the same person " << endl;
            return ;
        }

    }


    doubled=true;

    for(int i=0; i < gares.size()-1; i++)
    {
        int b=gares[i]->get_valeurCase()*2;

        gares[i]->set_valeurCase(b);

    }

    cout << "The GARES doubles the price!!! " << endl;

}





