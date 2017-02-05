#include "linkedlist.h"
#include <iostream>
using namespace std;

int getSize(LinkedList &mylist)
{
	Node * curr = mylist.head;
	int i = 0;
	while ( curr!= NULL)
	{
		curr = curr->next;
		i++;
	}

	return i;
}

bool removeAt(LinkedList &mylist, int pos)
{

	int data = getSize(mylist);
	Node * head = mylist.head;

	if (pos < 0 || pos > data - 1)
		return 0;
	if (pos == 0)
	{
		mylist.head = mylist.head->next;
		data--;
		return 1;
	}

	else
	{
		Node* curr = mylist.head;
		// Node* prev = curr;
		int count = 0;
		while (count < pos - 1)
		{
			curr = curr->next;
			count++;
		}

		curr->next = curr->next->next;
		data--;
		return 1;
	}

	
}
