/**
 * @file quackfun.cpp
 * This is where you will implement the required functions for the
 *  stacks and queues portion of the lab.
 */

namespace QuackFun {

/**
 * Sums items in a stack.
 * @param s A stack holding values to sum.
 * @return The sum of all the elements in the stack, leaving the original
 *  stack in the same state (unchanged).
 *
 * @note You may modify the stack as long as you restore it to its original
 *  values.
 * @note You may use only two local variables of type T in your function.
 *  Note that this function is templatized on the stack's type, so stacks of
 *  objects overloading the + operator can be summed.
 * @note We are using the Standard Template Library (STL) stack in this
 *  problem. Its pop function works a bit differently from the stack we
 *  built. Try searching for "stl stack" to learn how to use it.
 * @hint Think recursively!
 */
template <typename T>
T sum(stack<T>& s)
{
    if (s.size() == 0)
      return 0;

    if (s.size() == 1)
    {
      return s.top();
    }
    else
    {
      T obj = s.top();
      s.pop();
      T rem = sum(s);
      s.push(obj);
      return obj + rem;
    }
}

/**
 * Reverses even sized blocks of items in the queue. Blocks start at size
 * one and increase for each subsequent block.
 * @param q A queue of items to be scrambled
 *
 * @note Any "leftover" numbers should be handled as if their block was
 *  complete.
 * @note We are using the Standard Template Library (STL) queue in this
 *  problem. Its pop function works a bit differently from the stack we
 *  built. Try searching for "stl stack" to learn how to use it.
 * @hint You'll want to make a local stack variable.
 */
template <typename T>
void scramble (queue<T>& q)
{

    stack<T> s;
    // Your code here

    int i = 1;
    int size = q.size();
    int countOff = 1;

    while (i <= size)
    {

      int j = 0;
      if (countOff % 2 == 1)
      {
        while (j < countOff && i <= size)
        {
          q.push(q.front());
          q.pop();
          j++;
          i++;
        }
      }

      else
      {
        while (j < countOff && i <= size)
        {
          s.push(q.front());
          q.pop();
          j++;
          i++;
        }

        while(!s.empty())
        {
          q.push(s.top());
          s.pop();
        }
      }

      countOff ++;
    }

}

bool firstTime = true;

template <typename T>
bool checkFirstLength(stack<T>& s, queue<T>& q)
{
  if (firstTime)
  {
    firstTime = false;
    return (s.size() == q.size());
  }

  else
    return true;
}

/**
 * @return true if the parameter stack and queue contain only elements of
 *  exactly the same values in exactly the same order; false, otherwise.
 *
 * @note You may assume the stack and queue contain the same number of items!
 * @note There are restrictions for writing this function.
 * - Your function may not use any loops
 * - In your function you may only declare ONE local boolean variable to use in
 *   your return statement, and you may only declare TWO local variables of
 *   parametrized type T to use however you wish.
 * - No other local variables can be used.
 * - After execution of verifySame, the stack and queue must be unchanged. Be
 *   sure to comment your code VERY well.
 */
template <typename T>
bool verifySame(stack<T>& s, queue<T>& q)
{

    bool sameLength = checkFirstLength(s,q);

    if (s.size() == 0 || q.size() == 0)
    {
      return (s.size() == 0 && q.size() == 0);
    }

    if (s.size() == 1)
    {
        T temp1 = s.top();
        T temp2 = q.front();
        q.pop();
        q.push(temp2);

        return (temp1 == temp2);
    }

    bool retval = false; // optional
    T temp1; // rename me
    T temp2; // rename :)

    temp1 = s.top();
    s.pop();

    retval = verifySame(s, q);

    temp2 = q.front();
    q.pop();
    q.push(temp2);
    s.push(temp1);

    return (temp1 == temp2) && retval && sameLength;

}

}
