/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 *
 * @author Chase Geigle
 * @date (created) Fall 2011
 * @date (modified) Spring 2012, Fall 2012
 *
 * @author Jack Toole
 * @date (modified) Fall 2011
 */

/**
 * Destroys the current List. This function should ensure that
 * memory does not leak on destruction of a list.
 */

 #include<iostream>
using namespace std;

template <class T>
List<T>::~List()
{
    /// @todo Graded in MP3.1
    if (this -> head != NULL)
    {
        clear();
    }

    length = 0;
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
      tail = NULL;
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

  if(tail == NULL)
  {
    tail = newNode;
    head = newNode;
  }

  else
  {
    newNode -> prev = NULL;
    newNode -> next = head;
    head -> prev = newNode;
    head = newNode;

    if (length == 1)
      tail -> prev = head;
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
  ListNode * newNode = new ListNode(ndata);

  if(tail == NULL)
  {
    tail = newNode;
    head = newNode;
  }

  else
  {
    newNode -> next = NULL;
    newNode -> prev = tail;
    tail -> next = newNode;
    tail = newNode;

    if (length == 1)
      head -> next = tail;
  }
    length++;
}

/**
 * Reverses the current List.
 */
template <class T>
void List<T>::reverse()
{
    reverse(head, tail);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <class T>
void List<T>::reverse(ListNode*& startPoint, ListNode*& endPoint)
{
    if (startPoint == NULL)
      return;
    if (startPoint == endPoint)
    {
      ListNode* temp = startPoint;
      startPoint = endPoint;
      endPoint = temp;
      return;
    }

    ListNode* startPointPrev = startPoint->prev;
    ListNode* endPointNext = endPoint->next;


    ListNode * current = startPoint;
    ListNode * temp;

    ListNode * sentinel = endPoint->next;
    while (current != sentinel)
    {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = temp;
    }

    // std::cout << "in call to reverse: " << endl;
    // cout << current->prev->data << endl;
    // cout << current->prev->next->data << endl;
    // cout << current->prev->next->prev->data << endl;

    temp = startPoint;
    startPoint = endPoint;
    endPoint = temp;

    startPoint->prev = startPointPrev;

    endPoint->next = endPointNext;

    if (startPointPrev)
      startPointPrev->next = startPoint;
    if (endPointNext)
      endPointNext->prev = endPoint;


}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
 template <class T>
 void List<T>::reverseNth(int n)
 {

    if (head == NULL)
     return;

    ListNode* start = head;
    ListNode* flag = start;
    bool firstTime, lastTime;
    firstTime = true;
    lastTime = false;
    int count = 1;


    while (start != NULL)
    {
        while (count < n && flag->next != NULL)
        {
          flag = flag->next;
          count++;
        }

        lastTime = (count < n) || flag->next == NULL;

        reverse(start,flag);
        // now start and flag are reversed
        if (firstTime)
        {
          // comment
          head = start;
          firstTime = false;
        }
        if (lastTime)
        {
          tail = flag;
        }
        // std::cout << "We test in medias " << "S,F:" << start->data << flag->data << std::endl;
        // print(std::cout);
        start = flag->next;
        flag = start;
        count = 1;
    }
}
/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail. This continues
 * until the next thing to be removed is either the tail (**not necessarily
 * the original tail!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail should be continuously updated, some nodes will
 * be moved more than once.
 */
template <class T>
void List<T>::waterfall()
{
    if (!head)
      return;
  waterRecurse(head, tail);
}

template<class T>
void List<T>::waterRecurse(ListNode*& head, ListNode*& tail)
{
  // good
  ListNode* second = head->next;
  if (!second || !(second->next))
    return;

  ListNode* saveHead = head;

  while(second && (second->next))
  {


    head->next = second->next;
    head->next->prev = head;
    head = head->next;

    tail->next = second;
    second->next = NULL;
    second->prev = tail;
    tail = second;

    second = head->next;
  }

  head = saveHead;
}

/**
 * Splits the given list into two parts by dividing it at the splitPoint.
 *
 * @param splitPoint Point at which the list should be split into two.
 * @return The second list created from the split.
 */
template <class T>
List<T> List<T>::split(int splitPoint)
{
    if (splitPoint > length)
        return List<T>();

    if (splitPoint < 0)
        splitPoint = 0;

    ListNode* secondHead = split(head, splitPoint);

    int oldLength = length;
    if (secondHead == head) {
        // current list is going to be empty
        head = NULL;
        tail = NULL;
        length = 0;
    } else {
        // set up current list
        tail = head;
        while (tail->next != NULL)
            tail = tail->next;
        length = splitPoint;
    }

    // set up the returned list
    List<T> ret;
    ret.head = secondHead;
    ret.tail = secondHead;
    if (ret.tail != NULL) {
        while (ret.tail->next != NULL)
            ret.tail = ret.tail->next;
    }
    ret.length = oldLength - splitPoint;
    return ret;
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List objects!
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <class T>
typename List<T>::ListNode* List<T>::split(ListNode* start, int splitPoint)
{
    if (splitPoint == 0)
    {
        ListNode* newHead = head;
        return newHead;
    }

    if (splitPoint == length)
    {
      return NULL;
    }

    int i = 0;
    ListNode* curr = start;
    while (i < splitPoint - 1)
    {
        curr = curr->next;
        i+= 1;
    }

    ListNode* nextHead = curr->next;
    curr->next = NULL;
    nextHead->prev = NULL;
    return nextHead;
}

/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <class T>
void List<T>::mergeWith(List<T>& otherList)
{
    // set up the current list
    head = merge(head, otherList.head);
    tail = head;

    // make sure there is a node in the new list
    if (tail != NULL) {
        while (tail->next != NULL)
            tail = tail->next;
    }
    length = length + otherList.length;

    // empty out the parameter list

      otherList.head = NULL;
      otherList.tail = NULL;
      otherList.length = 0;

}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <class T>
typename List<T>::ListNode* List<T>::merge(ListNode* first, ListNode* second)
{
    if (!first && !second)
      return NULL;
    else if (!first)
      return second;
    else if (!second)
      return first;

    ListNode * newHead = NULL;
    ListNode * curr = NULL;


    if (first->data < second->data)
    {
      newHead = curr = first;
      first = first->next;
    }
    else
    {
      newHead = curr = second;
      second = second->next;
    }

    while (first && second)
    {
      if (first->data < second->data)
      {
        curr->next = first;
        first->prev = curr;
        curr = curr->next;
        first = first->next;
      }
      else
      {
        curr->next = second;
        second->prev = curr;
        curr = curr->next;
        second = second->next;
      }
    }

    if (!first)
    {
      curr->next = second;
      second->prev = curr;
    }
    else
    {
      curr->next = first;
      first->prev = curr;
    }

    return newHead;
}

/**
 * Sorts the current list by applying the Mergesort algorithm.
 */
template <class T>
void List<T>::sort()
{
    if (empty())
        return;
    head = mergesort(head, length);
    tail = head;
    while (tail->next != NULL)
        tail = tail->next;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <class T>
typename List<T>::ListNode* List<T>::mergesort(ListNode* start, int chainLength)
{

  if (chainLength <= 1)
    return start;

  int half = chainLength/2;
  ListNode* secondHalf = split(start,  half);
  start = mergesort(start, half);
  secondHalf = mergesort(secondHalf, chainLength - half);
  return merge(start, secondHalf);



  // if (chainLength <= 1)
  // {
  // 	return start;
  // }
  //
  // else
  // {
  // 	ListNode * temp = split(start, chainLength/2);
  // 	ListNode * ret1 = mergesort(start, chainLength/2);
  // 	ListNode * ret2 = mergesort(temp, chainLength - (chainLength/2));
  //
  // 	return merge(ret1, ret2);
  //  }


  // cout << "Printing after split:" << endl;
  // cout << "This list" << endl;
  // this->print(cout);
  // cout << "Other list" << endl;
  // secondHalf.print(cout);
  //
  // int secondLength = chainLength - half;
  //
  // ListNode * thisHead = this->mergesort(this->head, half);
  // ListNode * otherHead = secondHalf.mergesort(secondHalf.head, secondLength);
  // cout << "After mergesorting components:" << endl;
  // ListNode * curr = thisHead;
  // cout << "the component from this" << endl;
  // printNodes(curr);
  // curr = otherHead;
  //
  // cout << "the component from secondHalf" << endl;
  // printNodes(curr);
  // ListNode* result = merge(thisHead, otherHead);
  // printNodes(result);
  // return result;


}
