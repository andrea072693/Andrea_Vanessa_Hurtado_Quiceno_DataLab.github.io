#include <iostream>
#include "Joueur.h"
#include "Case.h"
#include "Plateau.h"
#include <chrono>
#include <random>
#include <vector>
#include <cstdlib>
#include <unistd.h>
using namespace std;
//Write a function that has an aleatory number from 1 to 6 (that will be the dice)

class MonSuperJeu
{

private:
    std::default_random_engine generator;


public:
    MonSuperJeu()
    {
        unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
        generator = std::default_random_engine(seed);
    }

    int card_pick(int nb_cartes)
    {
        std::uniform_int_distribution<int> card_distribution(1, nb_cartes);// start of the interval and the end.

        return card_distribution(generator);
    }

    int dice_toss()
    {
        return card_pick(6);
    }
};

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////


int main()
{


//MonSuperJeu jeu;
//    std::cout << "Bienvenue dans l'aléa: " << std::endl
//              << " - un jet de dé: " << jeu.dice_toss() << std::endl;
//              //<< " - on tire une carte: "<< jeu.card_pick(32) << std::endl;



    vector<Joueur*> players;



//How many player do we want:
    int numberOfPlayers;
    do
    {
        std::cout << "Please enter the number of players from 2 to 4 players maximum: ";
        std::cin >> numberOfPlayers;
    }
    while( numberOfPlayers>4 || numberOfPlayers<=1 );    // The condition of the bad.Repeat while this is bad.


//Here I am creating the players of the game:



//Asking again if he enters a wrong value:

    for ( int i=0; i< numberOfPlayers; i++)
    {

        string namePlayer;
        cout << "Give the initial letter in Mayuscule of your name: " << endl;
        cin >> namePlayer;

        Joueur* player= new Joueur(namePlayer, 1, 500);
//Joueur* player= new Joueur(namePlayer, 1 , 500, nullptr);

        players.push_back(player);

    }


    int pause;
    cout << "Give a number to continue " << endl;
    cin >> pause;



//loop that never ends (infinite look)
    Plateau* grille1=new Plateau(players);

//give a condition that is always true in order to make an infinity looop:
    int i=0;
    int k;
    do
    {

        if (players[i]->get_position()!=-1)
        {
            grille1->updateJoueur(players[i]);
            grille1->specificAction(players[i]);
            //this verifies
            grille1->numberGaresOwn();
        }


// resposable of the action function call:
        cout << "Give any number to continue" << endl;
        cin >> pause;

        i+=1;  //i++

        if (i== numberOfPlayers )
        {
            i=0;
        }

        k=0;


        for(int j=0; j< players.size(); j++  )
        {

            //weather the player is player or is not in the game anymore:

            if(players[j]->get_position()!=-1)
            {

                k++;

            }
        }

    }
    while( k >=2 );

    return 0;
}



