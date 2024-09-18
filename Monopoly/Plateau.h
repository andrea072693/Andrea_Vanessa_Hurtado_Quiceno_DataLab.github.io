#ifndef PLATEAU_H
#define PLATEAU_H
#include <vector>
#include <iostream>
#include <chrono>
#include <random>
#include "Case.h"
#include "Joueur.h"
using namespace std;



class Plateau
{

private:

// This will create the Board, which is of type Case*:
    std::vector<Joueur*>players;
    std::vector<Case*> grille;
//will make the aleatory of the Dice:
    std::default_random_engine generator;



public:

    Plateau(std::vector<Joueur*>);
    //   Plateau();
    virtual ~Plateau();
    Plateau (const Plateau&); // constructor par copie
    Plateau& operator= (const Plateau&); // reference constructor

//gets of the varable members:
    int get_endPoints();


//function that display the Plateau:
    void displayPlateau();
    void updateJoueur(Joueur*); // this update the board, after each turn.



//Aleatory functions, dice and carte:
    int card_pick(int nb_cartes);
    int dice_toss();


    //ask on of the class to call the action function for an specific case:
    void specificAction(Joueur*);


    bool doubled=false;

    std::vector<Case*> gares;



    void numberGaresOwn();




protected:


};

#endif // PLATEAU_H
