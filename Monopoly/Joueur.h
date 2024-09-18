#ifndef JOUEUR_H
#define JOUEUR_H
#include <iostream>
#include <vector>


using namespace std;


class Plateau;





class Joueur
{

private:

    std::string nom{"A"};
    int position{0};

    int budget{0}; // initializationof the default constructor

    int turn;
    int numberOfDice{0};

    int turnInJail{0};






protected:

    bool bankrupt{false};
    //Will ask the player if is in Jail o not.
    bool playerInJail{false};


//Vector of properties that the Player owns;
//    std::vector<Property*> vOfProperties;
//    std::vector<Gare*> vOfGares;

    Plateau* plateau{nullptr};



public:

    Joueur()=default; // constructor by default

    //This constructor will check the name of the player and will convert to ASCCI code:
    Joueur(std::string);

    //Constructor of parameters:

    Joueur(std::string, int, int);
    //Joueur(std::string, int, int,Plateau*);

    Joueur(const Joueur&); // constructor par copie
    Joueur& operator= (const Joueur&); // reference constructor
    virtual ~Joueur(); // destuctor




// gets


    std::string get_nom()
    {
        return nom;
    };
    int get_position()
    {
        return position;
    };
    int get_budget()
    {
        return budget;
    };

    bool get_bankrupt()
    {

        return bankrupt;
    };

    bool get_playerInJail()
    {
        return playerInJail;
    };


    int get_turnInJail()
    {

        return turnInJail;
    };

//    std::vector<Property*> get_vOfProperties(){
//
//
//    return vOfProperties;
//    };
//
//    std::vector<Gare*> get_vOfGares(){
//
//
//    return vOfGares;
//
//    };
//int get_turn(){return turn;};


//sets
    void set_nom(std::string);
    void set_position(int);
    void set_budget(int);
    void set_bankrupt(bool);
    void set_playerInJail(bool);
    void set_turnInJail(int);


// Function that deplace the Player, chaging its position to a new position.
    void deplacement(int);





// FUnction that checks if the budget of the player arrives to the minimum, it means that loss the game.



//Function to play the game:
    void play();




    //Function that sendds the player to Jail:
    void playertoJail(Joueur* );

    void updateJoueur(); // this update the board, after each turn.












    // Free the player from the Jail
    void free_from_jail(std::vector<std::string>& player_pos);



// Functions related to Money, where you can receive Money from other players (meaning that you owned a property and the player arriving to your property has
//to pay you a rent) or you need to pay an amount of money for rent in owned properties:
//Function to pay the rent:
    void rent(int rent)
    {
        std::cout << nom<< " has to pay " << rent << std::endl;
        budget-= rent;
    }

//Function to receive the rent
    void receiveRent(int receiveRent)
    {
        std::cout <<"The player " <<nom << " receives " << receiveRent << std::endl;
        budget += receiveRent;


        std::cout << "Your new total bugdet is "<< budget << std::endl;

    }



    // Send the Player to Jail:

    void sentToJail();



    //

//    void add_toProperties(Property*);
//    void remove_toProperties(Property*);
//
//    void add_toGare(Gare*);
//    void remove_toGare(Gare*);



};

///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////

class Human:public Joueur
{

private:


public:

    Human()=default; // constructor by default

    //This constructor will check the name of the player and will convert to ASCCI code:
    // Human(std::string);

    // Constructor of parameters:


    //Human(std::string, int, int);


    Human(const Human&); // constructor par copie
    Human& operator= (const Human&); // reference constructor
    virtual ~Human(); // destuctor



protected:


};


///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////

class Ordi:public Joueur
{

private:


public:

    Ordi()=default; // constructor by default


//  Ordi(std::string, int, int);
    Ordi(const Ordi&); // constructor par copie
    Ordi& operator= (const Ordi&); // reference constructor
    virtual ~Ordi(); // destuctor



protected:


};








#endif // JOUEUR_H
