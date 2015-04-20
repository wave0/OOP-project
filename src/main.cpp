#include "dict.h"
#include <iostream>

using namespace std;

int main()
{
	Dict d("OALD");
	cout << d.search("world") << endl;
	cout << "Hello World!" << endl;
	return 0;
}

