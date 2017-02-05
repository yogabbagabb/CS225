/**
 * @file heap.cpp
 * Implementation of a heap class.
 */

template <class T, class Compare>
size_t heap<T, Compare>::root() const
{
    /// @todo Update to return the index you are choosing to be your root.
    return 0;
}

template <class T, class Compare>
size_t heap<T, Compare>::leftChild(size_t currentIdx) const
{
    return 2*(currentIdx) + 1;
}

template <class T, class Compare>
size_t heap<T, Compare>::rightChild(size_t currentIdx) const
{
    return 2*currentIdx + 2;
}

template <class T, class Compare>
size_t heap<T, Compare>::parent(size_t currentIdx) const
{
    return (currentIdx-1)/2;
}

template <class T, class Compare>
bool heap<T, Compare>::hasAChild(size_t currentIdx) const
{
    return (leftChild(currentIdx) < _elems.size() || rightChild(currentIdx) < _elems.size());
}

template <class T, class Compare>
size_t heap<T, Compare>::maxPriorityChild(size_t currentIdx) const
{
  // at this point we assume the existence of some child;

  if (leftChild(currentIdx) < _elems.size() && rightChild(currentIdx) < _elems.size())
    return higherPriority(_elems[leftChild(currentIdx)], _elems[rightChild(currentIdx)])? leftChild(currentIdx) : rightChild(currentIdx);
  else if (leftChild(currentIdx) < _elems.size())
    return leftChild(currentIdx);
  else
    return rightChild(currentIdx);
}

template <class T, class Compare>
void heap<T, Compare>::swap(size_t a, size_t b)
{
  T temp = _elems[a];
  _elems[a] = _elems[b];
  _elems[b] = temp;
}

template <class T, class Compare>
void heap<T, Compare>::heapifyDown(size_t currentIdx)
{
  if (hasAChild(currentIdx))
  {
    size_t maxChild = maxPriorityChild(currentIdx);
    if (higherPriority(_elems[maxChild],_elems[currentIdx]))
    {
      swap(maxChild, currentIdx);
      heapifyDown(maxChild);
    }
  }
}

template <class T, class Compare>
void heap<T, Compare>::heapifyUp(size_t currentIdx)
{
    if (currentIdx == root())
        return;
    size_t parentIdx = parent(currentIdx);
    if (higherPriority(_elems[currentIdx], _elems[parentIdx])) {
        std::swap(_elems[currentIdx], _elems[parentIdx]);
        heapifyUp(parentIdx);
    }
}

template <class T, class Compare>
heap<T, Compare>::heap()
{
    /// @todo Depending on your implementation, this function may or may
    ///   not need modifying
}

template <class T, class Compare>
heap<T, Compare>::heap(const std::vector<T>& elems)
{
    _elems = elems;
    for (int i = _elems.size() - 1; i >= 0; i--)
    {
      size_t j = parent(i);
      heapifyDown(j);
    }
}

template <class T, class Compare>
T heap<T, Compare>::pop()
{
    T val = _elems[root()];
    _elems[root()] = _elems[_elems.size() - 1];
    _elems.resize(_elems.size()-1);
    heapifyDown(root());
    return val;
}

template <class T, class Compare>
T heap<T, Compare>::peek() const
{
    T val = _elems[root()];
    return val;
}

template <class T, class Compare>
void heap<T, Compare>::push(const T& elem)
{
    _elems.push_back(elem);
    heapifyUp(_elems.size()-1);
}

template <class T, class Compare>
bool heap<T, Compare>::empty() const
{
    return (_elems.size() == 0);
}
