/* Your code here! */

#include "dsets.h"

int DisjointSets::find(int elem)
{
  if (house[elem] < 0)
    return elem;
  else
    return house[elem] = find(house[elem]);
}

void DisjointSets::setunion(int a1, int b1)
{
  int a = find(a1);
  int b = find(b1);
  int size1 = house[a];
  int size2 = house[b];

  if (size1 - size2 < 0)
  {
    house[b] = a;
    house[a] = size1 + size2;
  }
  else if (size1 - size2 == 0)
  {
    house[b] = a;
    house[a] = size1 + size2;
  }
  else
  {
    house[a] = b;
    house[b] = size1 + size2;
  }
}

void DisjointSets::addelements(int num)
{
  for (int i = 0; i < num; i++)
  {
    house.push_back(-1);
  }
}
