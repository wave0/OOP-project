#ifndef DICT_H
#define DICT_H

#include <string>
#include <vector>
#include <map>

using std::vector;
using std::string;
using std::map;

class Dict
{
public:
	Dict(string File);
	~Dict();
	
	const vector<string> &wordList() {
		return m_WordList;
	}
	
	string search(string word);
	
private:
	string m_DictFile, m_IndexFile;
	map<string, int> m_Index;
	vector<string> m_WordList;
};

#endif // DICT_H
