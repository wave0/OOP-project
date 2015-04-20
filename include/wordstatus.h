#ifndef WORDSTATUS_H
#define WORDSTATUS_H

#include <string>
#include <iostream>

using namespace std;

class WordStatus
{
public:
	WordStatus(string word = "", int correct = 0, int total = 0);
	~WordStatus();
	
	void setWord(string text);
	void setCorrentCount(int value);
	void setTotalCount(int value);
	
	string getWord() const;
	int getCorrectCount() const;
	int getTotalCount() const;
	double getCorrentRate() const;
	
	bool readFrom(istream &o);
	void writeTo(ostream &o) const;
	
	void increaseCurrentCount(int value = 1);
	void increaseTotalCount(int value = 1);
	
	void correct();
	void incorrect();
	int cancel();
	
private:
	string m_Word;
	int m_CorrectCount, m_TotalCount, m_LastStep;
};

#endif // WORDSTATUS_H
