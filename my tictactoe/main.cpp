#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
    Game a;            //creating an object a

    while (true)
    {
        a.reset();
        cout << "1: To play with another person\n"
             << "2: To play with the computer\n"
             << "Please make you choice by enter a number from the above: ";
        cin >> a.choice;

        if (a.choice == 1)
        {
            a.WhoGoFirst(a.choice);
            a.display();       //display the board
            do
            {
                int move = a.getMove();      //ask for input
                a.go(move);                  //get the move on the board
                a.display();                 //display the result of the move
                if (a.checkwin()) break;     //if anybody win in this turn, game over
                a.switch_turn();
            }
            while( !a.isFull() );              //if the board is full, game ends.
        }

        else if (a.choice == 2)
        {
            a.WhoGoFirst(a.choice);
            a.display();
            do
            {
                int move = a.getMove();      //ask for input
                a.go(move);                  //get the move on the board
                a.display();                 //display the result of the move
                if (a.checkwin()) break;     //if anybody win in this turn, game over
                a.switch_turn();
            }
            while( !a.isFull() );
        }

        if ( a.isFull() )   cout << "Draw"<<endl; //if its ful
        else if(a.GetTurn()=='X') cout << "Player X is winner\n"<<endl;
        else cout<<"Player O is Winner\n"<<endl;
        do
        {
            char option;
            cout << "Play it again?(Y/N): ";
            cin >> option;
            if (option=='Y'||option=='y')
            {
                cout<<endl;
                break;   //jump out of this loop and come back to the outer loop
            }
            else if (option=='N'||option=='n') return 0;    //end up the whole program
            else cout << "Invalid input!\n" <<endl;
        }
        while(true);
    }

    return 0;
}

