#include<iostream>
using namespace std;


template <class T>
class Box
{
public:
  void doesStuff();
  void doesNothing();
  Box();
  Box(const Box& ref);
  Box& operator=(const Box& ref);
  virtual ~Box();
  int getField()
  {
    return field;
  }

  void setField(int i)
  {
    field = i;
  }

private:
  void doesA();
  T object;
  int field;

};

template<class T>
Box<T>::Box(const Box<T>& ref): field(blank);
{

}

template<class T>
Box<T>& Box<T>::operator=(const Box<T>& ref)
{

}

template<class T>
Box<T>::~Box()
{

}

template<class T>
Box<T>::Box()
{

}

template<class T>
void Box<T>::doesStuff()
{
    cout << "Stuff" << endl;
}


template<class T>
void Box<T>::doesNothing()
{
  cout << "Nothing" << endl;
}

template<class T>
void Box<T>::doesA()
{
  cout << "A" << endl;
}

int main()
{
  // make a box of type int
  Box<int> b;

  // make a array of box instructions
  Box<int> * array [3];

  // make a dynamic array of Boxes
  Box<int> * darray = new Box<int> [3];




}
