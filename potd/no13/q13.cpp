#include <cmath>
#include<iostream>


int* raise(int * array, int exp)
{
  int * result;


  int i = 0;
  while (array[i] >= 0)
  {
    i++;
  }

  int size = i + 1;

  result = new int[size];
  for (int j = 0 ; j < size - 1; j++)
  {
    result[j] = std::pow(array[j], exp);
  }
  result[size - 1] = array[size - 1];

  return result;
}



int main()
{
  return 0;
}
