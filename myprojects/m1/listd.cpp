#include<stddef.h>
#include <iostream>
using namespace std;

template <class LIT>
class List{


public:
    List();
    List(const LIT & e);
    List(const List & orig);
    ~List();
    void insert(int loc, const LIT & e);
    void removeLast();
    void print();
    void reverse();
    void printReverse();
    void pairZeros();
    void printAll();
    void reverseNth(int n);
    // lots more member functions



private:

  struct listNode {
  public:
    LIT data;
    listNode * next;
    listNode * prev;
    listNode(LIT e): data(e), next(NULL) {} ;
    listNode(): next(NULL) {} ;


};
    listNode * head;
    listNode * tail;
    int size; // the number of data elements in the list
    listNode * Find(int k, listNode * curr);
    void removeAll(listNode * curr);
    void print(listNode * curr);
    void reverse(listNode * next);
    void printReverse(listNode * curr);

};

template<class LIT>
List<LIT>::List()
{
  head = tail = NULL;
  size = 0;
}


template<class LIT>
void List<LIT>::printAll()
{
  cout << "Printing forwards" << endl;
  print();

  listNode * curr = tail;
  cout << "Printing backwards" << endl;
  cout << "<" << " ";
  while (curr)
  {
    cout << curr->data << " ";
    curr = curr->prev;
  }

  cout << ">" << endl;
}

template<class LIT>
void List<LIT>::print()
{
  cout << "<";
  print(head);
}

template<class LIT>
void List<LIT>::print(listNode * curr)
{
  if (curr ->next == NULL)
  {
    cout << curr->data;
    cout << ">" << endl;
    return;
  }

  cout << curr->data << " ";
  print(curr->next);


}

template<class LIT>
void List<LIT>::printReverse()
{
  printReverse(head);
  cout << ">" << endl;
}

template<class LIT>
void List<LIT>::printReverse(listNode * c)
{
  if (c->next == NULL)
  {
    cout << "<" << c->data << " ";
    return;
  }

  printReverse(c->next);
  cout << c->data << " ";

}




template<class LIT>
void List<LIT>::reverse()
{
  reverse(head);
  listNode * temp = head;
  head = tail;
  tail = temp;
}

template<class LIT>
void List<LIT>::reverse(listNode * curr)
{
  if (curr->next == NULL)
  {
    listNode* temp = curr->next;
    curr->next = curr->prev;
    curr->prev = temp;
    return;
  }

  reverse(curr->next);

  listNode* temp = curr->next;
  curr->next = curr->prev;
  curr->prev = temp;



}

template<class LIT>
int List<LIT>::reverseNth(int n)
{
  int count = 0;
  listNode* curr = head;
  bool firstTime = true;
  bool lastTime = false;
  while (count < size)
  {
    int innerc = 0;
    listNode * innerHead = curr;
    while (innerc < n && count < size)
    {
        innerHead = innerHead ->next;
        innerc += 1;
        count += 1;
    }

    lastTime = (innerc < n || count == size);

    listNode * originalNext = innerHead ->next;
    listNode * originalPrev = curr ->prev;
    reverse(curr, innerHead);

    listNode * temp = curr;
    if (firstTime)
    {
      firstTime = false;
      temp = head;
      head = innerHead;
      innerHead = temp;
    }

    else if (lastTime)
    {
      temp = tail;
      tail = curr;
      curr = temp;
    }

    originalNext->prev = curr;
    originalPrev->next = innerHead;
    curr->next = originalNext;
    innerHead->prev = originalPrev;



    curr = innerHead->next;
    innerHead = innerHead ->next;
  }
}

template<class LIT>
void List<LIT>::reverse(listNode * curr, listNode * sen)
{
  if (curr->next == sen)
  {
    listNode* temp = curr->next;
    curr->next = curr->prev;
    curr->prev = temp;
    return;
  }

  reverse(curr->next);

  listNode* temp = curr->next;
  curr->next = curr->prev;
  curr->prev = temp;



}

template<class LIT>
List<LIT>::List(const LIT & e)
{

}

template<class LIT>
List<LIT>::List(const List & orig)
{

}

template<class LIT>
List<LIT>::~List()
{

}

template<class LIT>
void List<LIT>::removeAll(listNode * curr)
{
  if (curr)
  {
    removeAll(curr->next);
    delete curr;
    curr = NULL;
    size--;
  }

}

template<class LIT>
void List<LIT>::insert(int loc, const LIT & e)
{
  listNode * add = new listNode(e);

  listNode * c = Find(loc, head);


  bool last = false;

  if (c)
    last = (c->next == NULL);

  if (c)
  {
    listNode* prevNext = c->next;
    listNode * prevPrev = c->prev;
    c->next = add;
    c->next->prev = c;
    add->next = prevNext;
    if (prevNext)
      prevNext->prev = add;
  }
  else if (size == 0){
    head = add;
    tail = add;
    head->next = NULL;
    head->prev = NULL;
    tail->next = NULL;
    tail->prev = NULL;
  }

  else
  {
    add->next = head;
    add->next->prev = add;
    add->prev = head->prev;
    head = add;
  }

  if (last)
  {
    tail = add;
  }
  size++;

}

template<class LIT>
void List<LIT>::removeLast()
{

}

template<class LIT>
void List<LIT>::pairZeros()
{

  listNode * zeroNode = NULL;
  bool firstTime = true;
  listNode * curr = head;
  while (curr != NULL)
  {
    if (curr->data == 0 && firstTime)
    {
      zeroNode = curr;
      firstTime = false;
    }

    else if (curr->data == 0)
    {
      zeroNode ->next = curr;
    }

    curr = curr->next;
  }

  zeroNode->next = NULL;


  listNode * oneNode = NULL;
  firstTime = true;
  curr = head;
  while (curr != NULL)
  {
    if (curr->data == 1 && firstTime)
    {
      oneNode = curr;
      firstTime = false;
    }

    else if (curr->data == 1)
    {
      oneNode ->next = curr;
    }
  }

  oneNode ->next = NULL;
}

template<class LIT>
typename List<LIT>::listNode* List<LIT>::Find(int k, listNode * curr)
{
  listNode * c = curr;
  int i = 1;
  while (i < k)
  {
    c = c->next;
    i++;
  }

  return c;
}

int main()
{

  // Test inserting some nodes:
  List<int> d;
  cout << "Before" << endl;
  for (int i = 0; i < 10; i++)
  {
      cout << i << endl;
      d.insert(i,i);
  }

  d.insert(3,6);
  d.insert(8,16);
  cout << "before reverse" << endl;
  d.printAll();

  cout << "After" << endl;
  d.reverse();
  d.printAll();



}
