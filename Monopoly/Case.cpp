#include "Case.h"
#include <iostream>
using namespace std;



Case::Case(int caseNumber1, int valeurCase1 ):
    caseNumber{caseNumber1}, valeurCase{valeurCase1}
{

    proprietaire= nullptr; // there is not cell that is createed with the starting proprietaire.

}



Case::Case(int caseNumber2):
    caseNumber{caseNumber2}
{


}



Case::~Case()
{
    //dtor
}


///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
//Definition of the sets:
void Case::set_valeurCase( int valeCase1)
{

    valeurCase = valeCase1;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void Case::set_proprietaire( Joueur* proprietaire1 )
{

    proprietaire= proprietaire1 ;
}





///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
void Case::displaceFirstLine()
{

    std::string line= "------";
    cout << line;

}

///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
void Case::displaceSecondLine()
{

    if (caseNumber >9) // TWO DIGITS NUMBER
    {

        if(proprietaire==nullptr)
        {

            cout << "|" << caseNumber << "  " << typeCase;
        }
        else
        {

            cout << "|" << caseNumber << "  " << proprietaire->get_nom();

        }

    }


    else
    {


        if(proprietaire==nullptr)
        {

            cout << "|" << caseNumber << "   "<< typeCase;
        }
        else
        {

            cout << "|" << caseNumber << "   "<< proprietaire->get_nom();
        }

    }

}
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
void Case::displaceThirdLine()
{

////This checks the value of the property:

    if (valeurCase==0) //NUll just for pointers
    {
        cout << "|     " ;
    }


    else if(valeurCase % 100 == valeurCase)
    {
//cout << "|" << " " << valeurCase << "|" << endl;
        cout << "|" << "   " << valeurCase ;
    }


    else if( valeurCase % 1000== valeurCase ) // when it is a three digit number
    {
//cout << "|" << " " << valeurCase << "|" << endl;
        cout << "|" << "  " << valeurCase ;
    }

}
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
void Case::displaceFourthLine()
{

// This is suppose to change the player of the turn.

    if (playersOfTurn.size()==0)
    {

//cout << "|    |" << endl;
        cout << "|     ";
    }

    else
    {

        //space in a for loop and the

        cout << "|";

        //as much spaces as the player,
        for(int i=0; i <= 4 - playersOfTurn.size()  ; i++ )
        {

            cout << " ";

        }

        for (int i=0; i< playersOfTurn.size(); i++)
        {

            cout << playersOfTurn[i]->get_nom();

        }

    }

}
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
void Case::lastLine()
{

    string line= "------";
    cout << line;

}
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
void Case::add_playersOfTurn(Joueur* playersOfTurn1)
{

    playersOfTurn.push_back(playersOfTurn1);

}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void Case::remove_playersOfTurn(Joueur* playersOfTurn2)
{



    for (int i=0; i < playersOfTurn.size(); i++)
    {



        if ( playersOfTurn[i] ==playersOfTurn2 )
        {


            playersOfTurn.erase(playersOfTurn.begin()+ i); // erase the firt cel

        }

    }

}


/*This function I need to override in the case property: */

void Case::action(Joueur*)
{




}

///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor and destructor of the Proprietaire:

Property::Property(int caseNumber1, int valeurCase1, int rent1):Case{caseNumber1, valeurCase1}
{
    typeCase=' ';

    proprietaire=nullptr;

    rentToPay=rent1;


}


Property::~Property()
{

}


void Property::set_rentToPay( int rentToPay1)
{

    rentToPay =rentToPay1;
}


///////////////////////////////////
///////////////////////////////////
///////////////////////////////////
void Property::action(Joueur* player)
{
// Di el propiertaire es el jugador de turno, no have nada
// verify that the player in turn is the owner:


    if (proprietaire == player)
    {

        cout << "This is your property... " << endl;

        return; // because it is a void function, to stop the function.
    }
    if ( proprietaire == nullptr  )
    {

        int yesOrNo;
        cout << "Do you want the property for " << valeurCase  << " ? " <<endl;
        cout << "Click 0 to not buy it, or any other number to buy it !!! "<< endl;
        cin >> yesOrNo;

        if (yesOrNo==0 )
        {

            cout << "You did not buy the property" << endl;

        }



        else
        {
            if (player->get_budget() > valeurCase )
            {
                cout << "You are the owner of this property " << endl;

                int newBudget=player->get_budget();


                newBudget-=valeurCase;

                player->set_budget(newBudget);


                proprietaire=player;

                ///



                //this->valeurCase; // creater the access, we do not need this because we have the acces...



            }

            else
            {

                cout << "You cannot buy this property "<< endl;
            }

        }

        return;
    }

// If the case has a proprietaire, the player in turn need to pay the rent:
    if(proprietaire != player)
    {

        cout << "You need to pay " << valeurCase << " to " << proprietaire->get_nom() <<endl;

        //loose money the player

        int newBudgetpl= player->get_budget();

        newBudgetpl -=valeurCase;

        player->set_budget(newBudgetpl);


//win money the proprietaire
        int newBudgetpr= proprietaire->get_budget();

        newBudgetpr+=valeurCase;

        proprietaire->set_budget(newBudgetpr);


        if (player->get_budget()<=0)
        {

            cout << "The player " << player->get_nom() << " loose the GAME! "<< endl;

            /* We will have to remove this player from the plateau */
            remove_playersOfTurn(player);

            player->set_position(-1);
        }


    }

}

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
// Constructor and destructor of the Chance:
Chance::Chance(int caseNumber1, int valeurCase1):Case{caseNumber1, valeurCase1 }
{
    typeCase='*';

    proprietaire=nullptr;



}
//////////////////////////////////////////////////////////////////////////////////////
Chance::~Chance()
{
    //dtor
}

int Chance::card_pick(int nb_cartes)
{
    std::uniform_int_distribution<int> card_distribution(1, nb_cartes);// start of the interval and the end.

    return card_distribution(generator);

}


void Chance::action(Joueur* player)
{



    int  theCardNumber=card_pick(3); // pick a number from 1 to 3.

    if(theCardNumber==1)
    {

        int winMoney= player->get_budget()+100;

        player->set_budget(winMoney);

        cout << "The player " << player->get_nom() <<" Picks the card WIN MONEY Congrats you won 100 " <<endl;
    }



    if(theCardNumber==2)
    {

        int looseMoney= player->get_budget()-50;

        player->set_budget(looseMoney);

        cout << "The player " << player->get_nom() <<" Picks the card LOOSE MONEY you loose 50 " <<endl;




        if(looseMoney<=0)
        {

            cout << "Game Over!!! " << endl;


            remove_playersOfTurn(player);

            player->set_position(-1);
        }

    }



//     if(theCardNumber==3){
//
//
//
//
//     }




}





//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
// Constructor and destructor of the Prison:
Depart::Depart(int caseNumber1, int valeurCase1, std::vector<Joueur*> pot):Case{caseNumber1, valeurCase1}
{
    typeCase='.';

    proprietaire= nullptr;

    playersOfTurn=pot;

}

Depart::~Depart( )
{
    //dtor
}




/////////////////////////////////////////////////////////////////////////
// Constructor and destructor of the Prison:
Prison::Prison(int caseNumber1):Case{caseNumber1}
{
    typeCase='+';

    proprietaire=nullptr;




}

Prison::~Prison()
{
    //dtor
}


void Prison::action(Joueur* player  )
{

/////////////////////////////////////////////////////////////////////////

}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

// Constructor and destructor of the Policier:

Policier::Policier(int caseNumber1, Case* prison_):Case{caseNumber1} // empty vector
{
    prison= prison_;

    typeCase='-';

    proprietaire=nullptr;

}


Policier::~Policier()
{
    //dtor
}


void Policier::action(Joueur* player)
{
    cout <<  player->get_nom() <<  "is now in Prison " << endl;

//dynamic access:
    int theNUmberofThePrison= prison->get_caseNumber();

    player->deplacement(theNUmberofThePrison); //the position of the Prison

//update the table:

    remove_playersOfTurn(player);


    prison->add_playersOfTurn(player);


    // make him wait three turns before going out from prison,

    player->set_turnInJail(3);

}







// Constructor and destructor of the Gare:

Gare::Gare(int caseNumber1, int valeurCase1):Case{caseNumber1, valeurCase1}
{
    typeCase='=';

    proprietaire=nullptr;

    // increasing the number gares.


}

Gare::~Gare()
{

}


////////////////////////////




void Gare::action(Joueur* player)
{
// Di el propiertaire es el jugador de turno, no have nada
// verify that the player in turn is the owner:



    if (proprietaire == player)
    {

        cout << "This is your gare... " << endl;

        return; // because it is a void function, to stop the function.
    }
    if ( proprietaire == nullptr  )
    {

        int yesOrNo;
        cout << "Do you want the gare" << valeurCase  << " ? " <<endl;

        cin >> yesOrNo;

        if (yesOrNo==0 )
        {

            cout << "You did not buy the gare" << endl;

        }




        else
        {
            if (player->get_budget() > valeurCase )
            {
                cout << "You are the owner of this gare " << endl;

                int newBudget=player->get_budget();


                newBudget-=valeurCase;

                player->set_budget(newBudget);


                proprietaire=player;

            }


            else
            {

                cout << "You cannot buy this gare "<< endl;
            }

        }

        return;
    }

// If the case has a proprietaire, the player in turn need to pay the rent:
    if(proprietaire != player)
    {

        cout << "You need to pay " << valeurCase << " to " << proprietaire->get_nom() <<endl;

        //loose money the player

        int newBudgetpl= player->get_budget();

        newBudgetpl -=valeurCase;

        player->set_budget(newBudgetpl);


//win money the proprietaire
        int newBudgetpr= proprietaire->get_budget();

        newBudgetpr+=valeurCase;

        proprietaire->set_budget(newBudgetpr);


        if (player->get_budget()<=0)
        {

            cout << "The player " << player->get_nom() << " loose the GAME! "<< endl;

            /* We will have to remove this player from the plateau */
            remove_playersOfTurn(player);

            player->set_position(-1);
        }


    }

}









