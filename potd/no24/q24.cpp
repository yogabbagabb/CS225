#include <iostream>
using namespace std;

struct node{
    int val;
    node * next;
};

void printList(node * head){
    if(head == NULL){
        cout << "Empty list" << endl;
        return;
    }
    node * temp = head;
    int count = 0;
    while(temp != NULL){
        cout << "Node " << count << ": " << temp ->val << endl;
        count++;
        temp = temp->next;
    }
}

void insertSorted(node ** head, node * insert){

  if (*head == NULL)
  {   *head = insert;
      return;
  }

  node *prev = *head;
  node * curr = prev;

  while (curr != NULL && curr->val < insert->val)
  {
    prev = curr;
    curr = curr->next;
  }

  if (curr == NULL)
  {
    prev->next = insert;
    insert->next = curr;
    return;
  }

  if (curr == prev)
  {
    insert->next = *head;
    *head = insert;
    return;
  }

  prev->next = insert;
  insert->next = curr;

}


int main(){

    node * head = NULL;
    node * add = new node();
    add -> val= 1;
    printList(head);
    insertSorted(&head, add);
    cout << "After empty test" << endl;
    printList(head);
    cout << endl;
    head = new node ();

    printList(head);
    cout << "After" << endl;

    insertSorted(&head, add);
    printList(head);

    head->val = -1;
    node * inter;
    node * curr = head;

    for (int i = 0; i < 10; i++)
    {
        inter = new node ();
        inter->val = 2*i;
        curr -> next = inter;
        curr = curr->next;
    }

    printList(head);
    node * toAdd = new node();
    toAdd ->val = -2;
    insertSorted(&head, toAdd);
    cout << "After" << endl;
    printList(head);

    node * toTAdd = new node();
    toTAdd ->val = 100;
    insertSorted(&head, toTAdd);
    cout << "After" << endl;
    printList(head);

    node * toTwadd = new node();
    toTwadd ->val = 98;
    insertSorted(&head, toTwadd);
    cout << "After" << endl;
    printList(head);

    curr = head;
    while (curr != NULL)
    {
      node * toDelete = curr;
      curr = curr->next;
      delete toDelete;
    }

    return 0;
}
