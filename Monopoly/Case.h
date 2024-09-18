#ifndef CASE_H
#define CASE_H
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include "Joueur.h"
using namespace std;

// PLateau contains a lot of class, so maybe an aggregation,
// vector of case that will contain 22 case.


class Case
{

protected:

    int caseNumber{0};
    int valeurCase{0};
    char typeCase{' '};
    Joueur* proprietaire{nullptr};
    //Joueur* playerOfTurn{nullptr};
    std::vector<Joueur*> playersOfTurn;
    //std::vector<Joueur*> owner;

private:

public:

    Case();
    // Create the constructor with all these parameters.
    Case(int, int);

    Case(int);
    Case (const Case&); // constructor par copie
    Case& operator= (const Case&); // reference constructor
    virtual ~Case();


    // define the action function:
    // getters:
    int get_caseNumber()
    {
        return caseNumber;
    };
//////
    int get_valeurCase()
    {
        return valeurCase;
    };
//////
    Joueur* get_proprietaire()
    {
        return proprietaire;
    };
///////
//    Joueur* get_playerOfTurn()
//    {
//        return playerOfTurn;
//    };
//////
    char get_typeCase()
    {
        return typeCase;
    };


    //vector<int> get_vOfProperties(){return vOfProperties;};


    // setters:
    //void set_caseNumber(int);
    void set_valeurCase(int);
    void set_proprietaire(Joueur*);
    void set_playersOfTurn(std::vector<Joueur*>);
    void set_typeCase(char);


    //////////////////////////////////////////
    virtual void action(Joueur*); //




    //void set_vOfProperties(vector<int>);
    // The functions that display the board:

    void displaceFirstLine();
    void displaceSecondLine();
    void displaceThirdLine();
    void displaceFourthLine();
    void lastLine();


    // The functions that add and remove the player from the vector Players of Turn
    void add_playersOfTurn(Joueur*);

    void remove_playersOfTurn(Joueur*);






};



/// the functions here will be virtual.

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
///////////////////// Case PROPRIETAIRE:

class Depart:public Case
{

private:



public:

    Depart()=default;
    Depart(int, int,std::vector<Joueur*>);
    Depart (const Depart&); // constructor par copie
    Depart& operator= (const Depart&); // reference constructor
    virtual ~Depart();






protected:

};

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
///////////////////// Case PROPRIETAIRE:

class Property:public Case
{

private:

    int rentToPay{0};



public:
    Property()=default;
    Property(int, int, int );
    Property (const Property&); // constructor par copie
    Property& operator= (const Property&); // reference constructor
    virtual ~Property();


    int get_rentToPay()
    {
        return rentToPay;
    };


    void set_rentToPay(int);


    //One fucntion that checks if the property has an owner .


// Changes the owner, if another player buys this property.
    void changeOwner(std::vector<Joueur*> & newOwneroftheProperty);
//Definir esta funcion
//void payRent();


//esta funcion va a usar changeOwner y payRent:
    void action(Joueur*) override;


protected:

};


/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
///////////////////// Case CHANCE:

class Chance:public Case
{

private:

    std::default_random_engine generator;

public:
    Chance()=default;
    Chance(int, int);
    Chance (const Chance&); // constructor par copie
    Chance& operator= (const Chance&); // reference constructor
    virtual ~Chance();



    void action(Joueur*) override;

    int card_pick(int nb_cartes);







protected:

};

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
///////////////////// Case CHANCE:

class Prison:public Case
{

private:

//Move this to the class Prison:
//Vector of the Players that are in Jail;

    std::vector<std::string> playersInJail;


public:
    Prison()=default;
    Prison(int);

    Prison (const Prison&); // constructor par copie
    Prison& operator= (const Prison&); // reference constructor
    virtual ~Prison();

//
    void action(Joueur*) override; // create the function with empty



protected:

};

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

class Policier:public Case
{

private:

    Case* prison{};


public:
    Policier()=default;

    Policier(int, Case*);

    Policier(const Policier&); // constructor par copie
    Policier& operator= (const Policier&); // reference constructor
    virtual ~Policier();


    void action(Joueur*) override;





protected:

};

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
class Gare:public Case
{

private:





public:
    Gare()=default;
    Gare(int, int);
    Gare(const Gare&); // constructor par copie
    Gare& operator= (const Gare&); // reference constructor
    virtual ~Gare();




protected:


    void action(Joueur*) override;






};









#endif // CASE_H
