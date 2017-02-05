#include <iostream>
#include <set>
#include <utility>
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
    if(a == NULL) return b;
    if(b == NULL) return a;
    node * aptr = a;
    node * bptr = b;
    while(aptr->next != NULL && bptr->next != NULL){
        node * tempa = aptr;
        aptr = aptr->next;
        node * tempb = bptr;
        bptr = bptr->next;
        tempa->next = tempb;
        tempb->next = aptr;
    }
    if(aptr->next == NULL){ // tack on rest of b
        aptr->next = bptr;
    }
    else{   // bptr->next == NULL
        // add last b node to a list
        node * tempa = aptr;
        aptr = aptr->next;
        tempa->next = bptr;
        bptr->next = aptr;
    }
    return a;
}

node*& intersection(node* one, node* two)
{

  set<int> common;
  node * curr = one;
  node * newHead = NULL;
  node * currNewHead = NULL;

  while (curr)
  {
    common.insert(curr->val);
    curr = curr->next;
  }

  curr = two;
  bool isNew = true;
  while(curr)
  {
    isNew = get<1>(common.insert(curr->val));
	common.erase(curr->val);

    if (!isNew)
	{

        if (!newHead)
        {
          newHead = new node ();
          newHead->val = curr->val;
          currNewHead = newHead;
          isNew = true;
        }
        else
        {
          node * temp = new node ();
          temp->val = curr->val;
          currNewHead->next = temp;
			currNewHead = currNewHead->next;
          isNew = true;
        }

	}
        curr = curr->next;
  }

  return newHead;

}

// Write a method intersection that takes in two node * (the heads of two linked lists) as parameters and returns a node * (the head of a new list). The returned list should be a new dynmically allocated linked list that has the values in the set intersection (no duplicates) of the two lists in sorted order.
//
// Example:
//
// List 1: 5 9 0 3 0
// List 2: 3 5 6 7 0 0
// Returned list: 0 3
// Something about writing a main method and test cases... oh that's right, you should be writing a main method with your own test cases!
//

int main(){

  node * head = NULL;
  node * sechead = NULL;

  head = new node ();
  sechead = new node ();

  node * curr = head;

  head->val = -1;
  node * inter;

  for (int i = -1; i < 6; i++)
  {
      inter = new node ();
      inter->val = 2*i;
      curr -> next = inter;
      curr = curr->next;
  }

  curr = sechead;
  sechead->val = -2;
  for (int i = -1; i < 2; i++)
  {
      inter = new node ();
      inter->val = 2*i;
      curr -> next = inter;
      curr = curr->next;
  }

for (int i = -1; i < 3; i++)
  {
      inter = new node ();
      inter->val = (i % 2 == 0)? 2 : 0;
      curr -> next = inter;
      curr = curr->next;
  }


  printList(head);
  cout << "And secondHead" << endl;
  printList(sechead);


  cout <<"____________" << endl;
  cout << "\n\n\n";

  node * newHead = intersection(head, sechead);
  printList(newHead);

  curr = newHead;
  while (curr != NULL)
  {
    node * toDelete = curr;
    curr = curr->next;
    delete toDelete;
  }

  // curr = sechead;
  // while (curr != NULL)
  // {
  //   node * toDelete = curr;
  //   curr = curr->next;
  //   delete toDelete;
  // }


  return 0;
}
