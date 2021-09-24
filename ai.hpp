#ifndef AI
#define AI_H

#include "myDefines.h"

using namespace std;

class AI
{
  private:
    int m_difficulty; //1 for easy, 2 for medium, 3 for hard
  public:
    AI(int difficulty);
    void aiMove();

    //getters/setters
    int getDifficulty();
    void setDifficulty(int diff);
};
#endif

