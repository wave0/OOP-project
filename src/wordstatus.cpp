#include "wordstatus.h"

WordStatus::WordStatus(string word, int correct, int total)
{
	m_Word = word;
	m_CorrectCount = correct;
	m_TotalCount = total;
	m_LastStep = 0;
}

WordStatus::~WordStatus()
{
	
}

void WordStatus::setWord(string text)
{
	m_Word = text;
}

void WordStatus::setCorrentCount(int value)
{
	m_CorrectCount = value;
}

void WordStatus::setTotalCount(int value)
{
	m_TotalCount = value;
}

string WordStatus::getWord() const
{
	return m_Word;
}

int WordStatus::getCorrectCount() const
{
	return m_CorrectCount;
}

int WordStatus::getTotalCount() const
{
	return m_TotalCount;
}

double WordStatus::getCorrentRate() const
{
	return static_cast<double>(m_CorrectCount) / m_TotalCount;
}

bool WordStatus::readFrom(istream &o)
{
	if (o >> m_Word >> m_CorrectCount >> m_TotalCount)
		return 1;
	return 0;
}

void WordStatus::writeTo(ostream &o) const
{
	o << m_Word << ' ' << m_CorrectCount << ' ' << m_TotalCount << endl;
}

void WordStatus::increaseCurrentCount(int value)
{
	m_CorrectCount += value;
}

void WordStatus::increaseTotalCount(int value)
{
	m_TotalCount += value;
}

void WordStatus::correct()
{
	increaseCurrentCount();
	increaseTotalCount();
	m_LastStep = 1;
}

void WordStatus::incorrect()
{
	increaseTotalCount();
	m_LastStep = 2;
}

int WordStatus::cancel()
{
	switch (m_LastStep) {
		case 1:
			increaseCurrentCount(-1);
			increaseTotalCount(-1);
			m_LastStep = 0;
			return 1;
		case 2:
			increaseTotalCount(-1);
			m_LastStep = 0;
			return 2;
		default:
			return 0;
	}
}

