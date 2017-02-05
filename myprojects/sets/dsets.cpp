
#include <vector>
#include <stdlib.h>
#include <iostream>
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
    int start = storage.size();
    storage.resize(storage.size() + num);
    for (int i = start; i < (int)storage.size(); i++)
    {
      storage[i] = -1;
    }
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
    else
    {
      int size = storage[second];
      storage[second] = first;
      storage[first] += size;
    }
  }

private:

  vector<int> storage;

};//

int main()
{
  DisjointSets s;
  int size = 10;
  s.addelements(size);
  for (int i = 0; i < size; i++)
  {
    cout << s.find(i) << endl;
  }

  s.setunion(0,1);
  s.setunion(1,2);
  s.setunion(2,9);

  for (int i = 0; i < size; i++)
  {
    cout << s.find(i) << endl;
  }
}
