#include "myDefines.h"
AI::AI(int difficulty)
{
  m_difficulty = difficulty;
}



/*
@author Sam Jerguson
*/
int* AI::aiMove(GameBoard playerBoard)
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
	  for(int i = 0; i < playerBoard.get_col(); i++)
	  {
		  for(int j = 0; j < playerBoard.get_rows(); j++)
		  {
			  if(playerBoard.get_shipArr()[i][j] == 'S')
			  {
				  guess[0] = i;
				  guess[1] = j;
				  return guess;
			  }
		  }
	  }
	  
      break;
	}
    default:
      cout << "Invalid difficulty\n";
  }
}

void AI::placeShips()
{
	
}

