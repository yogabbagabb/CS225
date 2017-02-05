#include<iostream>
using namespace std;






int main()
{
  int n;
  cout << "Give me your number please" << endl;
  cin >> n;

  int ** arr = new int * [n];
  for (int i = 0; i < n; i++)
  {
    arr[i] = new int[n];
    for (int j = 0 ; j  < n; j++)
    {
      arr[i][j] = i + j;
      cout << i + j << " ";
    }

    cout << endl;
  }

  for (int i = 0; i < n; i++)
  {
      delete [] arr[i];
  }

  delete []arr;



}
