#include "Game.h"
#include "ComputerAI.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int ComputerAI::getMoveByAI()
{
    do {
        m= rand()%9 ; // random move
    }
    while ( !a.isFree(m) );
    return m;
}
