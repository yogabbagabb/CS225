#include "common.h"
#include <iostream>
#include <queue>

/*
  As a reminder, useful STL queue methods include:
  empty : Test whether container is empty (public member function)
  size : Return size (public member function)
  front : Access next element (public member function)
  push : Insert element (public member function)
  pop : Remove next element (public member function)
*/

using namespace std;

int insertAt(queue<int> &q, int data, int pos)
{
	if (pos < 0 || pos > q.size())
		return -1;

	queue<int> temp;
	int ourSize = q.size() - pos;
	
	for (int i = 0; i < pos; i++)
	{
		temp.push(q.front()); q.pop();		
	}

	temp.push(data);

	while(!q.empty())
	{
		temp.push(q.front()); q.pop();
	}

	while(!temp.empty())
	{
		q.push(temp.front()); temp.pop();
	}
	
	return 1;


}
