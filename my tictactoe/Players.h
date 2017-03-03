
class Player
{
private:
    char square[10] = {'0','1','2','3','4','5','6','7','8','9'};
    char player1 = 'X';
    char player2 ='O';

public:
    int player=1;
    int i;
    int in;
    char mark;
    void display();
    int checkwin();
    void switch_turn();
    void go();
};
