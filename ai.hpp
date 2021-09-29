#ifndef AI
#define AI_H

using namespace std;

class AI
{
  private:
    int m_difficulty; //1 for easy, 2 for medium, 3 for hard
	int hitsArr[10][9];
  public:
    AI();
    int* aiMove(GameBoard& playerBoard);
	void placeShips();
	void initializeHitsArr();

    //getters/setters
    int getDifficulty();
    void setDifficulty(int diff);
};
#endif

