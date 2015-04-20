#include "dict.h"
#include <fstream>
#include <iostream>

Dict::Dict(string File) : m_DictFile(File), m_IndexFile(File+".idx")
{
	ifstream fin(m_IndexFile.c_str());
	string word;
	
	for (int i = 0; getline(fin, word); ++i) {
		m_Index.insert(make_pair(word, i));
		m_WordList.push_back(word);
	}
	
}

Dict::~Dict()
{
	
}

string Dict::search(string word)
{
	if (!m_Index.count(word))
		return string("Not Found!");
	ifstream fin(m_DictFile.c_str());
	int pos = m_Index[word];
	string str;
	for (int i = 0; i <= pos; ++i)
		getline(fin, str);
	return str;
}

