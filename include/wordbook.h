#ifndef WORDBOOK_H
#define WORDBOOK_H

class WordList;
class WordStatus;

class WordBook
{
public: 
	enum Familiar{known, grey, unknown};

	WordBook(const Wordlist*);
	~WordBook();

	WordStatus* getNewWord();	// 获取一个指向某未学过新词的指针

	WordStatus* getOldWord();	// 获取一个指向当前最需要复习词的指针
	void setWord(Familiar);		// 反馈学新词/复习词的情况

private:
	static const int reviewdays = {1, 2, 4, 7, 15};
	static const int deltadays = {1, 1, 2, 3, 5};

	WordList* m_list;
	WordStatus* m_currWord;

	double learnIndex(WordStatus*);

};

#endif
