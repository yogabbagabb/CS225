#include <iostream>
using namespace std;

struct node{
    int val;
    node * next;
};

void printList(node * head){
    node * curr = head;

    if (curr == NULL)
      cout << "Empty list" << endl;

    int i = 0;
    while (curr != NULL)
    {
      cout << "Node " << i << ": " << curr->val << endl;
      curr = curr->next;
      i += 1;
    }
}

int main(){

node * head = NULL;
printList(head);

head = new node();
head -> val = 0;
printList(head);

delete head;

// delete above or comment it out to test portion below

    // node * head = new node();
    // head -> val = -1;
    // node * curr = new node();
    // head->next = curr;
    // for (int i = 0; i < 10; i++)
    // {
    //   curr -> val = i;
    //   node * anotherCurr = new node ();
    //   curr->next = anotherCurr;
    //   curr = anotherCurr;
    // }
    // printList(head);
    //
    //
    // curr = head;
    // while (curr != NULL)
    // {
    //   node * toDelete = curr;
    //   curr = curr->next;
    //   delete toDelete;
    // }
    // return 0;
}
