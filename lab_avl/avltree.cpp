/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    Node * y = t->right;
    t->right = y->left;
    y->left = t;
    // t->height -= 1;
    t->height = std::max(heightOrNeg1(t->left), heightOrNeg1(t->right)) + 1;
    // I claim that this above is correct

    t =  y;
    t->height = std::max(heightOrNeg1(t->left), heightOrNeg1(t->right)) + 1;
    // t->height += 1;
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    Node * y = t->left;
    t->left = y->right;
    y->right = t;
    t->height = std::max(heightOrNeg1(t->left), heightOrNeg1(t->right)) + 1;
    // t->height -= 1;
    t = y;
    t->height = std::max(heightOrNeg1(t->left), heightOrNeg1(t->right)) + 1;
    // t->height += 1;
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    *_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    rotateRight(t->right);
    rotateLeft(t);
}

template <class K, class V>
int AVLTree<K, V>::getHeightBalance(Node*& subtree)
{
  int right = heightOrNeg1(subtree->right);

  int left = heightOrNeg1(subtree->left);

  return right - left;
}
template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    if(getHeightBalance(subtree) == -2)
    {
      Node *& left = subtree->left;
      if (left && getHeightBalance(left) == 1)
      {
        rotateLeftRight(subtree);
      }
      else
        rotateRight(subtree);
    }

    else if (getHeightBalance(subtree) == 2)
    {
      Node *& right = subtree->right;
      if (right && getHeightBalance(right) == -1)
        rotateRightLeft(subtree);
      else
        rotateLeft(subtree);
    }

    // We have to add one here, unless we make a wrapper

}

template <class K, class V>
int AVLTree<K, V>::getHeight(Node*& subtree)
{
  if (!subtree)
    return -1;
  else return std::max(getHeight(subtree->left), getHeight(subtree->right)) + 1;
}



template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    if (!subtree)
    {
      subtree = new Node (key, value);
      return;
    }

    if (key > subtree->key)
    {
      insert(subtree->right, key, value);
    }
    else
    {
      insert(subtree->left, key, value);
    }

    subtree->height = getHeight(subtree);
    rebalance(subtree);
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

// template <class K, class V>
// typename AVLTree<K,V>::Node* AVLTree<K, V>::getPreIOP(Node * subtree, Node * secondtree, int times)
// {
//   if (times == 1)
//   {
//     subtree = subtree->left;
//     secondtree = secondtree->left;
//   }
//
//   if (subtree->right == NULL)
//     return secondtree;
//
//   else
//   {
//       if (times == 1)
//       {
//           return getPreIOP(subtree->right, secondtree, times + 1);
//
//       }
//       else
//         return getPreIOP(subtree->right, secondtree->right, times + 1);
//   }
//
//
// }

template <class K, class V>
typename AVLTree<K,V>::Node* AVLTree<K, V>::getPreIOP(Node *& subtree)
{
  Node * left = subtree->left;
  Node * trueLeft = left;
  while(left->right != NULL)
  {
    trueLeft = left;
    left = left->right;
  }

  return trueLeft;
}

template<class K, class V>
void AVLTree<K, V>::processIOPremoval(Node *& iopPred, Node *& subtree)
{
  if (iopPred->right == NULL)
  {
      subtree->key = iopPred->key;
      subtree->value = iopPred->value;

      subtree->left = iopPred->left;
      delete iopPred;
      iopPred = NULL;
  }
  else
  {
    subtree->key = iopPred->right->key;
    subtree->value = iopPred->right->value;

    if (iopPred->right->left)
    {
      Node * temp = iopPred->right;
      iopPred->right = iopPred->right->left;
      delete temp;
      temp = NULL;
    }

    else
    {
      delete iopPred->right;
      iopPred->right =  NULL;
    }
  }
}

template <class K, class V>
void AVLTree<K, V>::balanceAll(Node*& subtree)
{
  if (subtree)
  {
    balanceAll(subtree->left);
    balanceAll(subtree->right);
    subtree->height = getHeight(subtree);
    rebalance(subtree);
  }
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    if (subtree == NULL)
        return;

    if (key < subtree->key) {
        remove(subtree->left, key);
        subtree->height = getHeight(subtree);
        rebalance(subtree);
    } else if (key > subtree->key) {
        remove(subtree->right, key);
        subtree->height = getHeight(subtree);
        rebalance(subtree);
    } else {
        if (subtree->left == NULL && subtree->right == NULL) {
            delete subtree;
            subtree = NULL;
        } else if (subtree->left != NULL && subtree->right != NULL) {
            Node * nodeBeforeIOP  = getPreIOP(subtree);
            processIOPremoval(nodeBeforeIOP, subtree);
            balanceAll(subtree);
        } else {
            if (subtree->left)
            {

              Node * temp = subtree;
              subtree = subtree->left;
              delete temp;
              temp = NULL;

            }
            else if (subtree->right)
            {
              Node * temp = subtree;
              subtree = subtree->right;
              delete temp;
              temp = NULL;

              // subtree->key = subtree->right->key;
              // subtree->value = subtree->right->value;
              //
              // Node * right = subtree->right;
              // subtree->left = subtree->right->left;
              // subtree->right = subtree->right->right;


            }
        }

    }
}
