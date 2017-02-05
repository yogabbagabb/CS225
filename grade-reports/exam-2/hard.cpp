#include "linkedlist.h"



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

void alternatingSplit(LinkedList* lst,
    LinkedList* even,
    LinkedList* odd)
{

	int data = getSize(lst);
	
	if (!lst)
	{
		even = NULL;
		odd = NULL;
		return;
	}

	if (data == 1)
	{
		odd = new LinkedList();
		odd->head = lst->head;
		odd->head->next = NULL;
		lst = NULL;
		return;
	}

	int i = 1;
	odd = new LinkedList();
	even = new LinkedList();

	Node * curr = lst->head;
	

	odd->head = curr;
	even->head = curr->next;

	Node * evenN = even->head;
	Node * oddN = odd->head;
	
	while (curr != NULL)
	{
		if (i % 2 == 0)
		{
			evenN ->next = curr;
		}

		if (i % 2 == 1)
		{
			oddN ->next = curr;
		}
	
		curr = curr->next;		
		i++;
	}
}
