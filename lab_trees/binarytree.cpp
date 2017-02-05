/**
 * @file binarytree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

/**
 * @return The height of the binary tree. Recall that the height of a binary
 *  tree is just the length of the longest path from the root to a leaf, and
 *  that the height of an empty tree is -1.
 */
template <typename T>
int BinaryTree<T>::height() const
{
    // Call recursive helper function on root
    return height(root);
}

/**
 * Private helper function for the public height function.
 * @param subRoot
 * @return The height of the subtree
 */
template <typename T>
int BinaryTree<T>::height(const Node* subRoot) const
{
    // Base case
    if (subRoot == NULL)
        return -1;

    // Recursive definition
    return 1 + max(height(subRoot->left), height(subRoot->right));
}

/**
 * Prints out the values of the nodes of a binary tree in order.
 * That is, everything to the left of a node will be printed out before that
 * node itself, and everything to the right of a node will be printed out after
 * that node.
 */
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
    // Call recursive helper function on the root
    printLeftToRight(root);

    // Finish the line
    cout << endl;
}

/**
 * Private helper function for the public printLeftToRight function.
 * @param subRoot
 */
template <typename T>
void BinaryTree<T>::printLeftToRight(const Node* subRoot) const
{
    // Base case - null node
    if (subRoot == NULL)
        return;

    // Print left subtree
    printLeftToRight(subRoot->left);

    // Print this node
    cout << subRoot->elem << ' ';

    // Print right subtree
    printLeftToRight(subRoot->right);
}

/**
 * Flips the tree over a vertical axis, modifying the tree itself
 *  (not creating a flipped copy).
 */
template <typename T>
void BinaryTree<T>::mirror()
{
    mirror(root);
}

template <typename T>
typename BinaryTree<T>::Node *& BinaryTree<T>::mirror(Node *& subroot)
{
  if (subroot ==  NULL)
    return subroot;

  Node * formerLeft = subroot->left;
  subroot->left = mirror(subroot->right);
  subroot->right = mirror(formerLeft);

  return subroot;
}

/**
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */



template <typename T>
bool BinaryTree<T>::isOrdered() const
{
    return isOrdered(root);
}

template<typename T>
bool BinaryTree<T>::isOrdered(Node * const subroot) const
{
  if (!subroot)
    return true;

  bool leftOrder = isOrdered(subroot->left);
  bool rightOrder = isOrdered(subroot->right);

  int val = subroot->elem;
  int LMR, RML;



  Node * curr = subroot->left;
  if (curr)
  {
    while (curr->right)
    {
      curr = curr->right;
    }
  }
  if (curr)
    RML = curr->elem;
  else
    RML = subroot->elem;




  curr = subroot->right;
  if (curr)
  {
    while (curr->left)
    {
      curr = curr->left;
    }
  }
  if (curr)
    LMR = curr->elem;
  else
    LMR = subroot->elem;

  return leftOrder && rightOrder && LMR >= val && RML <= val;


}


template<typename T>
void BinaryTree<T>::printMaximals() const
{
  Node * curr = root->left;
  if (curr)
  {
    while (curr->right)
    {
      curr = curr->right;
    }
  }

  if (curr)
    cout << "The right most of left: " << curr->elem;

  curr = root->right;
  if (curr)
  {
    while (curr->left)
    {
      curr = curr->left;
    }
  }

  if (curr)
    cout << "The left most of right: " << curr->elem;
}

// template <typename T>
// BinaryTree<T>::triple<int, int, bool> BinaryTree<T>::isOrderedB(BinaryTree<T>::
// Node * const subroot) const
// {
//
//
//   if (!subroot)
//     return NULL;
//
//   triple<int, int, bool> leftT = isOrderedB(subroot->left);
//   triple<int, int, bool> rightT = isOrderedB(subroot->right);
//   bool immLeft, immRight, totalOrder;
//   int rightML, leftMR;
//
//   if (leftT)
//   {
//     immLeft = get<1>(lefT) <= subroot -> elem;
//     rightML = 0;
//   }
//   else
//     immLeft = true;
//
//
//   if (righT)
//     immRight = get<0>(righT) >= subroot -> elem;
//   else
//     immRight = true;
//
//   bool totalOrder = get<2>(lefT) && get<2>(righT);
//
//   triple<int, int, bool> outcome = make_tuple();
//   return
//
// }


/**
 * Prints out all the possible paths from the root of the tree to any leaf node.
 * That is, all sequences starting at the root node and continuing downwards,
 * ending at a leaf node. Paths ending in a left node should be printed before
 * paths ending in a node further to the right.
 */
template <typename T>
void BinaryTree<T>::printPaths() const
{
    vector<T> paths;
    printPaths(paths, root);
}

template <typename T>
void BinaryTree<T>::printPaths(vector<T> paths, Node * subroot) const
{
  if (subroot == NULL)
    return;

  paths.push_back(subroot->elem);


  if (!subroot->left && !subroot->right)
  {
    cout << "Path: ";
    for (int i = 0; i < (int)paths.size(); i++)
    {
      cout << paths[i] << " ";
    }
    cout << "\n";

    return;
  }

  printPaths(paths, subroot->left);
  printPaths(paths, subroot->right);



}




/**
 * Each node in a tree has a distance from the root node - the depth of that
 * node, or the number of edges along the path from that node to the root. This
 * function returns the sum of the distances of all nodes to the root node (the
 * sum of the depths of all the nodes). Your solution should take O(n) time,
 * where n is the number of nodes in the
 * @return The sum of the distances of all nodes to the root
 */
template <typename T>
int BinaryTree<T>::sumDistances() const
{
    // your code here
    return sumDistances(root, 0);
}

template <typename T>
int BinaryTree<T>::sumDistances(Node * subroot, int depth) const
{
    if (!subroot)
      return 0;

    return depth + sumDistances(subroot->left, depth + 1) + sumDistances(
      subroot->right, depth + 1);
}
