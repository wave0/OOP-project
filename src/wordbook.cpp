#include "wordbook.h"
#include "wordlist.h"
#include "wordstatus.h"

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
using std::vector;

WordBook::WordBook(const WordList* list)
{
	m_list = list;
}

WordBook::~WordBook()
{

}

WordStatus *WordBook::getNewWord()
{
	vector<WordStatus*> &list = m_list->getlist();

	srand((unsigned int) time(NULL));
	
	int size = list.size(), x;

	do {
		x = rand() / RAND_MAX * size;
	} while(!list[x]->getTotalCount());

	m_currWord = list[x];
	return m_currWord;
}

void WordBook::setWord(Familiar fmlr)
{
	m_currWord->setFamiliar(fmlr);
	m_currWord = nullptr;
}

WordStatus* WordBook::getOldWord()
{
	vector<WordStatus*> &list = m_list->getlist();
	int max = 0;

	for(auto *i : list)
		if(learnIndex(*i) > max)
		{
			max = learnIndex(*i);
			m_currWord = i;	
		}

	return m_currWord;
}

double WordBook::learnIndex(WordStatus* word)
{
	srand((unsigned int) time(NULL));

	double difficultIndex = word->getCorrectRate() * 10;
	double randIndex = rand() / RAND_MAX * 5;

	double timingIndex = 0, t;

	time_t lastTime = word->getTime();

	for(int i = 0; i < 5; ++i)
	{
		t = 20 * (1 - fabs(lastTime / 86400 - reviewdays[i]) / deltadays[i]);
		if(t > timingIndex)
			timingIndex = t;
	}

	return timingIndex + difficultIndex + randIndex;
}
