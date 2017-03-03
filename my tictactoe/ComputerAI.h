class ComputerAI
{
public:
    int m;
    int getMoveByAI();
    int possWin(int);
    int make2inRow(int);
    int getAnyFreeSpace();
    bool isFree(int);
    friend class Game;

private:
    Game a;
};
