#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

class HashTable
{
private:
	Node * bucket[7];
	int bucketIndex;
	bool pSearch(int i, Node *n);
	bool pSilentsearch(int i, Node *n);
public:
	HashTable();
	~HashTable();

	void insert(int data);
	void listCollision(int pos);
	void print();
	bool search(int i, bool s);
};

