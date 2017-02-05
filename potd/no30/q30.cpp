#include <iostream>
using namespace std;

class Stack{
    private:
        struct node{
            int val;
            node * next;
        };
        node * head;

        int size;
    public:
        Stack()
        {
          head = NULL;
          size = 0;
        }
        ~Stack()
        {
          node * curr = head;
          node * toDelete;
          while(curr)
          {
            toDelete = curr;
            curr = curr->next;
            delete toDelete;
          }
        }

        int getSize();

        bool isEmpty()
        {
          return size == 0;
        }
        void push(int value)
        {
          node * toAdd = new node;
          toAdd->val = value;
          toAdd->next = head;
          head = toAdd;
          size++;
        }
        int pop()
        {
          int val = head->val;
          head = head->next;
          size--;
          return val;
        }
        void print()
        {
          node * curr = head;
          cout << "<";
          while (curr)
          {
            cout << curr->val << "," ;
            curr = curr->next;
          }
          cout << ">" << endl;
        }
};

int Stack::getSize()
{
  return size;
}



int main(){
    Stack a;
    a.print();
    cout << "is empty " << a.isEmpty() << endl;
    a.push(1);
    a.push(2);
    a.push(3);
    cout << "popped " << a.pop() << endl;
    cout << "size: " << a.getSize() << endl;
    cout << "is empty " << a.isEmpty() << endl;
    a.print();

    return 0;
}
