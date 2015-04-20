#include "wordlist.h"
#include <fstream>

WordList::WordList(string File)
{
	setFile(File);
	load();
}

WordList::~WordList()
{
	save();
	clear();
}

void WordList::setFile(string File)
{
	m_File = File;
}

void WordList::clear()
{
	for (size_t i = 0; i < m_List.size(); ++i)
		delete m_List.at(i);
	m_List.clear();
}

void WordList::addWord(string text)
{
	m_List.push_back(new WordStatus(text));
}

string WordList::getFile() const
{
	return m_File;
}

const vector<WordStatus*> &WordList::getList() const
{
	return m_List;
}

WordStatus *WordList::find(string text)
{
	for (size_t i = 0; i < m_List.size(); ++i)
		if (m_List.at(i)->getWord() == text)
			return m_List.at(i);
	return 0;
}

void WordList::load()
{
	ifstream fin(m_File.c_str());
	clear();
	WordStatus word;
	while (word.readFrom(fin))
		m_List.push_back(new WordStatus(word));
}

void WordList::save()
{
	ofstream fout(m_File.c_str());
	for (size_t i = 0; i < m_List.size(); ++i)
		m_List.at(i)->writeTo(fout);
}

