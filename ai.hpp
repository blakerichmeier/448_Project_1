#ifndef AI
#define AI_H

using namespace std;

class AI
{
  private:
    int m_difficulty; //1 for easy, 2 for medium, 3 for hard
	int hitsArr[10][9];
  public:

    /**
    @pre none
    @post this is the constructor for the ai class that initializes the AI board
    @param none*/
    AI();

    /**
    @pre the AI board is constructed
    @post the AI player makes a move on the board parameter
    @param playerBoard the AI gameboard from the GameBoard class passed by reference */
    int* aiMove(GameBoard& playerBoard);

    /**
    @pre the AI class is constructed
    @post the ships are placed into the AI's game board so that the player can guess
    @param none*/
	  void placeShips();

    /**
    @pre none
    @post the hits array is initialized after its called by the constructor
    @param none*/
	  void initializeHitsArr();

    //getters/setters

    /**
    @pre none
    @post this is retrieves the difficulty for the AI from the command line
    @param none*/
    int getDifficulty();

    /**
    @pre none
    @post this is a setter for the difficult of the AI
    @param none*/
    void setDifficulty(int diff);
};
#endif

