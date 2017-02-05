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
    node * temp = *head;
    if(temp == NULL){
        *head = insert;
        insert->next = NULL;
        return;
    }
    if(temp->val >= insert->val){   // this node becomes the new head
        insert->next = temp;
        *head = insert;
    }
    else{
        node * prev = *head;
        temp = temp->next;
        while(temp != NULL){
            if(temp->val >= insert->val){
                insert->next = temp;
                prev->next = insert;
                return;
            }
            temp = temp->next;
            prev = prev->next;
        }
        // we reached the end of list, this node must go at the end
        // prev points to last node, temp points to NULL
        prev->next = insert;
        insert->next = NULL;
    }
}

void sortList(node ** head){
    node * newHead = NULL;
    node * curHead = *head;
    node * insert;
    while(curHead != NULL){
        insert = curHead;
        curHead = curHead->next;
        insert->next = NULL;
        insertSorted(&newHead, insert);
    }
    *head = newHead;
}

node * shuffle(node * a, node * b){
    node * ac = a;
    node * bc = b;

    node * temp;

    while (ac || bc)
    {

      temp = ac->next;
      ac->next = bc;
      ac = temp;

      if (!ac && !bc)
        continue;

      temp = bc->next;
      bc->next = ac;
      bc = temp;
    }

    return ac;
}

int main(){

  node * head = NULL;
  node * sechead = NULL;

  head = new node ();
  sechead = new node ();

  node * curr = head;

  head->val = -1;
  node * inter;

  for (int i = -1; i < 10; i++)
  {
      inter = new node ();
      inter->val = 2*i;
      curr -> next = inter;
      curr = curr->next;
  }

  curr = sechead;
  sechead->val = -2;
  for (int i = -1; i < 10; i++)
  {
      inter = new node ();
      inter->val = 2*i;
      curr -> next = inter;
      curr = curr->next;
  }


  printList(head);
  cout << "And secondHead" << endl;
  printList(sechead);


  cout <<"____________" << endl;
  cout << "\n\n\n";

  node * newHead = shuffle(head, sechead);
  printList(newHead);

  curr = head;
  while (curr != NULL)
  {
    node * toDelete = curr;
    curr = curr->next;
    delete toDelete;
  }

  curr = sechead;
  while (curr != NULL)
  {
    node * toDelete = curr;
    curr = curr->next;
    delete toDelete;
  }


  return 0;
}
