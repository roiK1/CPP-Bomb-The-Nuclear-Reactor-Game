#include "ScoreGiverObject.h"

//-----------------------------------------------------------------------------
ScoreGiverObject::ScoreGiverObject(int &totalScore , int scoreAmount)
	:m_totalScore(totalScore) , m_scoreAmount(scoreAmount)
{
}

//-----------------------------------------------------------------------------
void ScoreGiverObject::addScore()
{
	m_totalScore += m_scoreAmount;
}

//-----------------------------------------------------------------------------