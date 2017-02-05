/* Your code here! */
#ifndef DSETS_H
#define DSETS_H
#include <vector>
#include <stdlib.h>
using namespace std;

class DisjointSets
{

public:

  int find(int i)
  {
    if (storage[i] < 0)
      return i;
    else
      return (storage[i] = find(storage[i]));
  }

  void addelements(int num)
  {
    storage.resize(storage.size() + num);
  }

  void setunion(int i, int j)
  {
    int first = find(i);
    int second = find(j);

    if (abs(storage[first]) < abs(storage[second]))
    {
      int size = storage[first];
      storage[first] = second;
      storage[second] += size;
    }
  }

private:

  vector<int> storage;

};


#endif
