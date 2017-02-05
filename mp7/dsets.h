/* Your code here! */

#ifndef _DSETS_H
#define  _DSETS_H

#include <vector>

class DisjointSets
{
private:
  std::vector<int> house;

public:
  int find(int elem);
  void setunion(int a, int b);
  void addelements(int num);



};


#endif
