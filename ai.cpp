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
	  int rand_x,rand_y;
	  srand(time(NULL));
	  REDO:;
	  for(int i = 0; i < 2; i++) {
		  if (i == 1) {
			  rand_x = rand() % 9;
		  } else {
			  rand_y = rand() % 8;
		  }
	  }
	  if(hitsArr[rand_x][rand_y] == 1) {
		  goto REDO;
	  }
	  guess[0] = rand_x;
	  guess[1] = rand_y;
	  hitsArr[rand_x][rand_y] = 1;
	  return guess;
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
			  if((playerBoard.get_shipArr()[i][j] == 'S') && (hitsArr[i][j] != 1)) //checks to ensure
			  {
				  guess[0] = i;
				  guess[1] = j;
				  hitsArr[i][j] = 1; //marks where the ai has already hit
				  return guess; //returns an array containing the row and column of the ai's guess
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

