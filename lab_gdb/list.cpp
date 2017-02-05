/**
 * @file list.cpp
 * Singly Linked List (lab_gdb).
 *
 * @author Chase Geigle
 * @date (created) Fall 2011
 * @date (modified) Spring 2012, Fall 2012
 *
 * @author Jack Toole
 * @date (modified) Fall 2011
 *
 * @author Veer Dedhia
 * @date (modified) Spring 2014
 */

/**
 * Destroys the current List. This function should ensure that
 * memory does not leak on destruction of a list.
 */

 #include <iostream>
//
// namespace myutil
// {
//     template <class T>
//     void printFromNode(typename List<T>::ListNode * start)
//     {
//       while(start != NULL)
//       {
//         std::cout << start->data << " " <<std::endl;
//       }
//     }
// }

template <class T>
List<T>::~List()
{
    clear();
}

/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <class T>
void List<T>::clear()
{
    /// @todo Graded in MP3.1
      ListNode * current = head;
      while(current != NULL)
      {
        ListNode * toDelete = current;
        current = current -> next;
        delete toDelete;

      }

      head = NULL;

}
/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertFront(T const& ndata)
{

  ListNode * newNode = new ListNode(ndata);

  if(head == NULL)
  {
    head = newNode;
  }

  else
  {
    newNode -> next = head;
    head = newNode;
  }

    length++;


}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertBack(const T& ndata)
{
    // @todo Graded in lab_gdb
    // NOTE: Do not use this implementation for MP3!
    ListNode* temp = head;

    if (temp == NULL) {
        head = new ListNode(ndata);
		length++;
    } else {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new ListNode(ndata);
        length++;
    }
}

/**
 * Reverses the current List.
 */
template <class T>
void List<T>::reverse()
{
    if (head == NULL)
      return;
    head = reverse(head, NULL, length);
}

/**
 * Helper function to recursively reverse the enitre sequence of
 * linked memory inside a List.
 *
 * @param curr The current node we are reversing
 * @param prev The node that should be placed before the current node in the
 * final reversed list
 * @param len The length of the remaining list to be reversed
 */
template <class T>
typename List<T>::ListNode* List<T>::reverse(ListNode* curr, ListNode* prev,
                                             int len)
{
    // @todo Graded in lab_gdb
    if (head == NULL)
      return head;

	int a = len;
    ListNode* temp;
    if (len <= 1) {
        curr->next = prev;
        head = curr;
        return prev;
    } else {
        temp = reverse(curr->next, curr, len - 1);
        temp->next = prev;
        if (prev)
          return prev;
        else
          return head;
    }
}

/**
 * Shuffles the current list by applying a perfect shuffle once. This entails
 * splitting the list in half, then interleaving the two halves.
 * For example:
 * start : < 1, 2, 3, 4, 5 >
 * split : < 1, 2, 3 >    < 4, 5 >
 * final : < 1, 4, 2, 5, 3 >
 */
template <class T>
void List<T>::shuffle()
{
    if (head == NULL)
      return;
    // @todo Graded in lab_gdb

    // Find the center, and split the list in half
    // one should point at the start of the first half-list
    // two should point at the start of the second half-list
    ListNode *one, *two, *temp, *secondT;
    one = two = temp = secondT = head;

    for (int i = 0; i < length / 2; i++) {
          two = two->next;
    }
    if (length % 2 != 0)
      two = two->next;


    //   std::cout<< "Printing the second chain" << std::endl;
    //
    //   rand = two;
    //
    // while(rand != NULL)
    // {
    //   std::cout << rand->data << " " <<std::endl;
    //   rand = rand->next;
    // }

    // interleave

    if (length % 2 != 0)
    {

       while (two != NULL) {
            temp = one->next;
            one->next = two;
            secondT = two->next;
            two->next = temp;
            one = temp;
            two = secondT;
        }
          one->next = NULL;

    }
    if (length % 2 == 0)
    {
      while (two->next != NULL) {
           temp = one->next;
           one->next = two;
           secondT = two->next;
           two->next = temp;
           one = temp;
           two = secondT;
       }
         one->next = two;
         two->next = NULL;
    }
}
