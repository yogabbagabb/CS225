#include <iostream>
using namespace std;

class Queue{

private:
  struct node
  {
    int val;
    node * next;

    node()
    {
      next = NULL;
    }
  };

  node * tail;
  node * head;
  int size;


public:

  Queue()
  {
    head = NULL;
    tail = NULL;
    size = 0;
  }

  ~Queue()
  {
    node * curr = head;
    while (curr)
    {
      node * toDelete = curr;
      curr = curr->next;
      delete toDelete;
    }
  }

  int getSize()
  {
    return size;
  }

  bool isEmpty()
  {
    return size == 0;
  }

  void push(int val)
  {
    if (!head && !tail)
    {
      node * x = new node ();
      x->val = val;
      head = tail = x;
    }
    else
    {
      node * x = new node();
      x->val = val;
      tail->next = x;
      tail = tail->next;
    }

    size++;
  }

  int pop()
  {
    node * toDelete = head;
    head = head->next;
    int val = toDelete->val;
    delete toDelete;
    size--;
    return val;
  }

  void print()
  {
    node * curr = head;
    std::cout << "< ";
    while (curr)
    {
      cout << curr->val << endl;
      curr = curr->next;
    }

    cout << ">" << endl;
  }


};


int main(){
    Queue a;
    a.print();
    cout << "is empty " << a.isEmpty() << endl;
    a.push(1);
    a.push(2);
    a.push(3);
    a.print();
    cout << "popped " << a.pop() << endl;
    a.pop();
    a.pop();
    cout << "size: " << a.getSize() << endl;
    cout << "is empty " << a.isEmpty() << endl;
    a.print();

    return 0;
}
