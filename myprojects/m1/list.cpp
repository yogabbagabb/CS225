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
    // lots more member functions



private:

  struct listNode {
  public:
    LIT data;
    listNode * next;
    listNode(LIT e): data(e), next(NULL) {} ;
    listNode(): next(NULL) {} ;


};
    listNode * head;
    listNode * tail;
    int size; // the number of data elements in the list
    listNode * Find(int k, listNode * curr);
    void removeAll(listNode * curr);
    void print(listNode * curr);
    listNode* reverse(listNode * next, listNode * prev);
    void printReverse(listNode * curr);

};

template<class LIT>
List<LIT>::List()
{
  head = tail = NULL;
  size = 0;
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
  listNode* theTail = reverse(NULL, head);
  head = theTail;

}

template<class LIT>
typename List<LIT>::listNode* List<LIT>::reverse(listNode * prev, listNode * curr)
{
  if (curr->next == NULL)
  {
    curr->next = prev;
    listNode * catcher = curr;
    return catcher;
  }

  listNode * catcher = reverse(curr, curr->next);
  curr->next = prev;
  return catcher;

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
  if (c)
  {
    listNode* prevNext = c->next;
    c->next = add;
    add->next = prevNext;
  }
  else{
    head = add;
    head->next = NULL;
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

  ListNode * zeroNode = NULL;
  bool firstTime = true;
  ListNode * curr = head;
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

  zeroNode->next = NULL


  ListNode * oneNode = NULL;
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

  oneNode ->next = NULL


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

  cout << "After" << endl;
  d.print();

  cout << "printing in rev" << endl;
  d.printReverse();

  d.reverse();
  d.print();



}
