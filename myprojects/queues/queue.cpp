#include<queue>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;





void insertAt(queue<int> & x, int pos, int val)
{
  queue<int> y;

  for (int i = 0; i < pos; i++)
  {
    y.push(x.front());
    x.pop();
  }

  y.push(val);

  while(!x.empty())
  {
    y.push(x.front());
    x.pop();
  }

  while(!y.empty())
  {
    x.push(y.front());
    y.pop();
  }

}

void printQueue(queue<int> x)
{
  while (!x.empty())
  {
    cout << x.front() << endl;
    x.pop();
  }
}

void removeAt(queue<int> &x, int pos)
{
  queue<int> y;

  for (int i = 0; i < pos; i++)
  {
    y.push(x.front());
    x.pop();
  }

  x.pop();

  while(!x.empty())
  {
    y.push(x.front());
    x.pop();
  }

  while(!y.empty())
  {
    x.push(y.front());
    y.pop();
  }
}

bool compare(string a, string b){
    return (a.compare(b) < 0);
}



int main()
{

  vector<string> y;
  cout << (find(y.begin(), y.end(), "hello") == y.end()) << endl;
  y.push_back("h");
  y.push_back("a");
  y.push_back("e");
  sort(y.begin(), y.end(), compare);

  for (string q: y)
    cout << q <<endl;



  queue<int> x;
  x.push(1);
  x.push(2);
  x.push(3);


  insertAt(x, 1, 4);
  printQueue(x);

  removeAt(x,1);
  printQueue(x);

}
