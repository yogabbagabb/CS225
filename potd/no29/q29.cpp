#include <iostream>
using namespace std;

struct node{
    int val;
    node * next;
};

void printList(node * head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

node *createList(int arr[], int size){
    node * ret = new node;
    ret->val = arr[0];
    node * temp = ret;
    for(int i = 1; i < size; i ++){
        temp->next = new node;
        temp = temp->next;
        temp->val = arr[i];
    }
    temp->next = NULL;
    return ret;
}

void sortList(node ** head)
{
  int array[] = {1,3,5};
  node * newHead = NULL;
  node * pnewHead = NULL;
  node * curr = *head;

  for (int stage = 0; stage < 3; stage++)
  {
      while (curr)
      {
        if (curr->val == array[stage])
        {
          if (!newHead)
          {
            newHead = new node();
            newHead->val = curr->val;
            pnewHead = newHead;
          }
          else
          {
            newHead->next = new node();
            newHead = newHead->next;
            newHead->val = curr->val;
          }
        }

        curr = curr->next;
      }

      curr = *head;
  }
    *head = pnewHead;

}

void deleteList(node * p)
{
  node * curr = p;
  node * toDelete = NULL;
  while (curr)
  {
    toDelete = curr;
    curr = curr->next;
    delete toDelete;
  }
}


int main(){
    int arr[6] = {1, 3, 3, 5, 1, 5};
    node * n = createList(arr, 6);
    printList(n);
    cout << endl;
    sortList(&n);
    printList(n);
    deleteList(n);
    return 0;
}
