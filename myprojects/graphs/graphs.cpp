

#include <iostream>
#include <vector>
#include <list>
using namespace std;


void printDoubleArray(int ** & array)
{
  for (int i =0; i < 10; i++)
  {
    for (int j =0; j < 10; j++)
    {
      cout << array[i][j] << " ";
    }
    cout << "\n";
  }

}

void printListArray(list<int> * & array)
{
  int * x= new int [10];
  for (int i = 0; i < 10; i++)
  {
    for (int j= 0; i < 10; j++)
    {
      array[i]
    }
  }
}

bool matrixIsComplete()
{

  int ** array = new int * [10];
  for (int i = 0; i < 10; i++)
  {
    array[i] = new int [10];
  }

  for (int i =0; i < 10; i++)
  {
    for (int j =i; j < 10; j++)
    {
      if (i == j)
      {
        array[i][j] = 1;
        array[j][i] = 1;
      }
      else if (rand() % 100 < 50)
      {
        array[i][j] = 1;
        array[j][i] = 1;
      }
      else
      {
        array[i][j] = 0;
        array[j][i] = 0;
      }
    }
  }

  printDoubleArray(array);
  for (int i = 0; i < 10; i++)
  {
    delete [] array[i];
  }
  delete [] array;

  return false;

}



bool adjacencyIsComplete()
{
  list<int> * array = new list<int> [10];
  for (int i =0; i < 10; i++)
  {
    for (int j =i+1; j < 10; j++)
    {

      if (rand() % 100 < 50)
      {
        array[i].push_back(j);
        array[j].push_back(i);
      }

    }
  }

  print
}


int main()
{
  matrixIsComplete();
}
