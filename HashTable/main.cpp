#include <iostream>
#include <sstream>
#include "HashTable.h"
#include "Node.h"

using namespace std;

int main()
{
	int quit = 0;
	stringstream ss;

	HashTable ht;
	ht.insert(1);
	ht.insert(2);
	ht.insert(3);
	ht.insert(4);
	ht.insert(5);
	ht.insert(5);
	ht.insert(5);
	ht.insert(5);
	ht.insert(6);
	ht.insert(7);
	ht.print();
	ht.search(4,false);
	ht.search(8,false);

	/*while (quit == 0)
	{
		quit = 1;
	}*/
	return 0;
}