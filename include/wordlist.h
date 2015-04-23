#ifndef WORDLIST_H
#define WORDLIST_H

#include "wordstatus.h"
#include <string>
#include <vector>

using std::vector;

class WordList
{
public:
	WordList(string File);
	~WordList();
	
	void setFile(string File);
	void clear();
	void addWord(string text);
	
	string getFile() const;
	const vector<WordStatus*> &getList() const;
	WordStatus *find(string text);
	
	void load();
	void save();
	
private:
	
	string m_File;
	vector<WordStatus*> m_List;
};

#endif // WORDLIST_H
