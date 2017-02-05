#include<list>
#include<iostream>
#include<string>
using namespace std;


class printer
{
public:

  ~printer()
  {

  }

  printer()
  {

  }

  printer(printer & ref)
  {

  }

  printer& operator=(printer & ref)
  {

  }

  void operator()(string a)
  {
    cout << a << endl;
  }
};



int main()
{
  list<string>l;
  l.push_back("a");
  l.push_back("b");
  printer x;
  for(list<string>::iterator it  = l.begin(); it != l.end() ; it++)
  {
    x(*it);
  }

}
