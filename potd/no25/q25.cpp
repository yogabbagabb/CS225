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

// Write a sortlist method here.

void sortList(node ** head)
{
  if (! *head ||! (*head)->next)
    return;

  node * sen;
  sen ->next = *head;

  node * fCurr,  * sCurr, * mover;
  fCurr = sCurr = mover = sen;


  while (fCurr->next != NULL)
  {
    mover = sCurr =fCurr->next;
    int min;
    if (sCurr && sCurr->next)
      min = sCurr->val;
    else
    {
      fCurr = fCurr->next;
      continue;
    }

    bool changedMin = false;

    while(sCurr->next != NULL)
    {
      if (min > sCurr->next-> val)
      {
         mover = sCurr;
         changedMin = true;
      }

      sCurr = sCurr ->next;
    }

    // swap the fCurr and sCurr

    if (!changedMin)
    {
       fCurr = fCurr->next;
       continue;
    }
    // special case adjacent:
    if (fCurr->next == mover)
    {
        fCurr->next = mover->next;
        node * C = mover->next->next;
        mover->next->next = mover;
        mover->next = C;
    }

    else
    {
      node * C = fCurr -> next;
      node * Q = fCurr->next->next;
      node * P = mover ->next->next;
      fCurr->next = mover->next;
      fCurr->next->next=  Q;
      mover->next = C;
      mover->next->next = P;
    }


    fCurr = fCurr->next;
  }

  *head = sen->next;


}

int main(){

  node * head = NULL;

  head = new node ();

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

  printList(head);


  cout <<"____________" << endl;
  cout << "\n\n\n\n";

  sortList(&head);
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
