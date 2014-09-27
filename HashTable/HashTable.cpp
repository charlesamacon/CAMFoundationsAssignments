#include "HashTable.h"
#include "Node.h"


HashTable::HashTable()
{
	int i;
	for (i = 0; i < 7; i++)
	{
		cout << "Creating bucket " << i << endl;

		Node * b = new Node(NULL);
		bucket[i] = b;
	}

}


HashTable::~HashTable()
{
}


void HashTable::insert(int data)
{
	bucketIndex = ((data * data) % 7);

	//cout << "Trying to add: " << data << endl;

	if (search(data, true))
	{
		// SHHHH! SEARCH SILENTLY
		cout << "WARNING: duplicate input: " << data << endl;
	}
	else
	{
		if (bucket[bucketIndex]->getValue() == NULL)
		{
			bucket[bucketIndex]->setValue(data);
		}
		else
		{
			Node * last = new Node();
			last = bucket[bucketIndex]->getLast();

			Node * newNode = new Node(data);
			last->setNext(newNode);
		}
	}
}

void HashTable::print()
{
	int i;
	for (i = 0; i < 7; i++)
	{
		cout << "(";
		bucket[i]->printNodes();
		cout << ")";
		if (i < 6)
		{
			cout << "-";
		}
		else
		{
			cout << endl;
		}
	}
}

bool HashTable::search(int i, bool s)
{
	int testIndex = ((i * i) % 7);

	if (s == false)
	{
		return pSearch(i, bucket[testIndex]);
	}
	else
	{
		return pSilentsearch(i, bucket[testIndex]);
	}
}

bool HashTable::pSearch(int i, Node *n)
{
	cout << "Searching for " << i << endl;
	bool tf;
	if (n != NULL)
	{
		if (i == n->getValue())
		{
			cout << "Found" << endl;
			tf = true;
			return true;
		}
		else if (n->getNext() != NULL)
		{
			Node *ne = n->getNext();
			pSearch(i, ne);
		}
		else
		{
			cout << "Not Found" << endl;
			return false;
		}
	}
	else
	{
		cout << "Null Found" << endl;
		return false;
	}
}

bool HashTable::pSilentsearch(int i, Node *n)
{
	bool tf;
	if (n != NULL)
	{
		if (i == n->getValue())
		{
			tf = true;
			return true;
		}
		else if (n->getNext() != NULL)
		{
			Node *ne = n->getNext();
			pSilentsearch(i, ne);
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}