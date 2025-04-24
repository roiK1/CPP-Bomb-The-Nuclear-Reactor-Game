#pragma once

class ScoreGiverObject
{
public:
	ScoreGiverObject(int& totalScore  , int scoreAmount);
	~ScoreGiverObject() = default;

	void addScore();

private:
	int &m_totalScore ,
		 m_scoreAmount;
};

