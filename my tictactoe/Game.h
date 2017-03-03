class Game
{
public:
    char square[9] = {'1','2','3','4','5','6','7','8','9'};
    int choice;
    int ChooseWhoBeX;
    int turn;
    int input;
    char mark;
    void reset();
    void display();
    void WhoGoFirst(int);
    int getMove();
    bool checkwin();
    bool isFull();
    void switch_turn();
    void go(int);
    char GetTurn();
    bool isFree(int);

    int m;
    int getMoveByAI();
    int possWin(int);
    int make2inRow(int);
    int getAnyFreeSpace();



private:
    const char X = 'X';
    const char O = 'O';

};
