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

void requeue(node ** head, int times)
{
  node * curr = *head;
  while (curr->next != NULL)
    curr = curr->next;


  if (*head == curr)
  {

  }

  else
  {
    node * temp = NULL;
    for (int i = 0; i < times; i++)
    {
      // temp = *head;
      // *head = *head->next;
      //
      // curr->next = temp;
      // temp->next = NULL;


      temp = *head;

      *head = temp->next;

      curr->next = temp;
      curr = curr->next;
      temp->next = NULL;
    }
  }
}


int main(){
    int arr[3] = {1,2,3};
    node * n = createList(arr, 3);
    printList(n);
    requeue(&n, 3);
    cout << endl;
    printList(n);
    return 0;
}
