#include "Joueur.h"
#include <iostream>
#include <stdlib.h> // contains the exit function.

using namespace std;

//Constructor with arguments:
//Joueur::Joueur(std::string nom_, int position_, int budget_, Plateau* plateau_):
//    nom{nom_}, position{position_}, budget{budget_}, plateau{plateau_}
Joueur::Joueur(std::string nom_, int position_, int budget_):
    nom{nom_}, position{position_}, budget{budget_}
{
    //ctor
}

// Definition of the constructor of the name:
//Joueur::Joueur()
//{
//
//cout << "Give your name, your name must be a mayuscule letter from A-Z " << endl;
//cin >> nom;
//
//}






//Destructor:
Joueur::~Joueur()
{
    //dtor
}


///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
// defintion of the sets:

void Joueur::set_nom( string nom1 )
{

    nom= nom1 ;
}
void Joueur::set_position( int position1 )
{

    position= position1 ;
}


//////////////////////////////////////////

void Joueur::set_budget( int budget1 )
{
//I f he wins money because of chance, property, or rent will call this function:

    budget= budget1 ;

    if (budget>=2000)
    {

        cout << "The player " << nom << "WIN the game!!!" << endl;

        cout << "The game is OVER" << endl;

        // declare a library in order to make the game stop:
        exit(1);

    }



}






//////////////////////777
void Joueur::set_bankrupt( bool bankrupt1 )
{

    bankrupt= bankrupt1 ;
}

void Joueur::set_playerInJail( bool playerInJail1 )
{

    playerInJail= playerInJail1 ;
}

void Joueur::set_turnInJail(int turnInJail1)
{

    turnInJail= turnInJail1;

}

///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
void Joueur::deplacement( int newPositionPlayer)
{
// Need the external information
    position =  newPositionPlayer;                                          // increment and make it bigger
    std::cout <<"The player " << nom << " is in the case: " <<  position  << std::endl;


}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//) First check if the case is a policier and from here will start to make MY logic of the game:

void Joueur::play()
{

// this function will check all the cases one by one starting from Policier, Prison, chance, in order to start to play
    bool areYouInJail{false};

    std::cout << "Are you in Jail Yes or No ? " << std::endl;

// here the game must ask to the player if he is in Jail, or not.

    cin >> areYouInJail;






}




void Joueur::playertoJail(Joueur* player)
{





}





///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
//definition of the constructor of Human:




//Human::Human( )
//{
//
//
//
//}






Human::~Human()
{
    //dtor
}




///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
//definition of the constructor of Ordi:


//Ordi::Ordi( )
//{
//
//
//
//}


Ordi::~Ordi()
{
    //dtor
}

