#include "ai.hpp"
AI::AI(int difficulty)
{
  m_difficulty = difficulty;
}



/*
@author Sam Jerguson
*/
void AI::aiMove()
{
  switch(m_difficulty)
  {
    case 1:
      //easy code here
      break;
    case 2:
      //medium code here
      break;
    case 3:
      //hard code here
      
      break;
    default:
      cout << "Invalid difficulty\n";
  }
}

