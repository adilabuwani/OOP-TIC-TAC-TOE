#include "Game.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void Game::reset()
{
    if(square[0] != '1' && square[1] != '2' && square[2] != '3'
        && square[3] != '4' && square[4] != '5' && square[5] != '6'
        && square[6] != '7' && square[7] != '8' && square[8] != '9')
        {
            for(int i=0; i<9; i++)
            {
                square[i] = (char)(i+48);
            }
        }
}

void Game::display()
{
	cout << "Player 1 = X    Player 2 = O" << "\n\n" << endl;

	cout << "     |     |     " << endl;
	cout << "  " << square[0] << "  |  " << square[1] << "  |  " << square[2] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[3] << "  |  " << square[4] << "  |  " << square[5] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[6] << "  |  " << square[7] << "  |  " << square[8] << endl;

	cout << "     |     |     " << "\n" << endl;
}

void Game::WhoGoFirst(int choice)
{
    if (choice==1) turn = 1;

    if (choice==2)                               //play with computer
    {
        cout << "\n1: You go first as player X\n"
             << "2: The computer go first as player X\n"
             << "Please make you choice by enter a number from the above: ";
        cin >> ChooseWhoBeX;
        turn = 1;
    }
}

void Game::switch_turn()
{
    turn++;
}

char Game::GetTurn()
{
    if (turn%2==1) return X;
    else return O;
}

int Game::getMove()
{
    mark = GetTurn();

    if (choice==1 && mark==X)  //play with people
    {
        cout<<"Player 1, enter your position for X: ";
        cin >> input;
        cout << endl;
        return input;
    }

    else if(choice==1 && mark==O)
    {
        cout<<"Player 2, enter your position for O: ";
        cin>>input;
        cout<<endl;
        return input;
    }



    if (choice==2)  //play with computer
    {
        if (ChooseWhoBeX==1)       //you go first as X
        {
            if (mark==X)
            {
                cout << "It's your turn. Enter your position for X: ";
                cin >> input;
                cout << endl;
                return input;
            }
            else if (mark==O)
            {
                cout << "It's the computer's turn. She is making her move..." <<endl;
                input =getMoveByAI();
                cout << endl;
                return input;
            }
        }

        else if (ChooseWhoBeX==2)    //the computer go first as X
        {
            if (mark==X)
            {
                cout << "It's the computer's turn. She is making her move...";
                input =getMoveByAI();
                cout << endl;
                return input;
            }
            else if (mark==O)
            {
                cout << "It's your turn. Enter your position for O: ";
                cin >> input;
                cout << endl;
                return input;
            }
        }
    }
}


bool Game::isFree(int Input)
{
    if (square[Input-1] == (Input+48))  //Compare the value of input with the corresponding element of the array
        return true;                    //by converting the input from the int type to the char type.

    else return false;
}



void Game::go(int input)
{
    if (isFree(input))
        square[input-1] = mark;
    else
    {
        cout<<"Invalid move! Try again!\n"<<endl;
        turn--;
        cin.ignore();
    }
}



bool Game::checkwin()
{
    if (   (square[0] == square[1] && square[1] == square[2])
        || (square[0] == square[3] && square[3] == square[6])
        || (square[0] == square[4] && square[4] == square[8])

        || (square[1] == square[4] && square[4] == square[7])

        || (square[2] == square[5] && square[5] == square[8])
        || (square[2] == square[4] && square[4] == square[6])

        || (square[3] == square[4] && square[4] == square[5])

        || (square[6] == square[7] && square[7] == square[8])
        )
        return true;

    else return false;
}


bool Game::isFull()
{
    if ( square[0] != '1' && square[1] != '2' && square[2] != '3'
        && square[3] != '4' && square[4] != '5' && square[5] != '6'
        && square[6] != '7' && square[7] != '8' && square[8] != '9'
        && !checkwin() )
        return true;

    else return false;
}

int Game::getMoveByAI()
{
    do {
        m= rand()%9 ; // random move
    }
    while ( !isFree(m) );
    return m;
}


