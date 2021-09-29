#include "myDefines.h"
AI::AI()
{
	initializeHitsArr();
}



/*
@author Sam Jerguson
*/
int* AI::aiMove(GameBoard& playerBoard)
{
  int* guess = new int[2];
  switch(m_difficulty)
  {
    case 1:
      //easy code here
      break;
    case 2:
      //medium code here
      break;
    case 3:
	{
      //hard code here
	  for(int i = 0; i < 10; i++)
	  {
		  for(int j = 0; j < 11; j++)
		  {
			  if((playerBoard.get_shipArr()[i][j] == 'S') && (hitsArr[i][j] != 1))
			  {
				  guess[0] = i;
				  guess[1] = j;
				  hitsArr[i][j] = 1;
				  return guess;
			  }
		  }
	  }
	  return guess;
	  
      break;
	}
    default:
      cout << "Invalid difficulty\n";
  }
}

void AI::placeShips()
{
	
}

void AI::initializeHitsArr()
{
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 11; j++)
		{
			hitsArr[i][j] = 0;
		}
	}
}

void AI::setDifficulty(int diff)
{
	m_difficulty = diff;
}

int AI::getDifficulty()
{
	return m_difficulty;
}

