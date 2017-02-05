#include <iostream>
#include <queue>
#include<vector>
using namespace std;

struct node
{
  int data;
  node * left;
  node * right;
};

node * initialize() {
	node * q = new node;
	node * w = new node;
	node * e = new node;
	node * r = new node;
	node * t = new node;
	node * y = new node;
	node * u = new node;

	q->data = 1;
	w->data = 1;
	e->data = 2;
	r->data = 3;
	t->data = 5;
	y->data = 13;
	u->data = 8;

	q->left = w;
	q->right = e;
	w->left = r;
	w->right = t;
	r->left = NULL;
	r->right = NULL;
	t->left = NULL;
	t->right = u;
	u->left = NULL;
	u->right = NULL;
	e->left = y;
	e->right = NULL;
	y->left = NULL;
	y->right = NULL;


  u->right = new node;
  u->right->data = 6;
  u->right->left = NULL;
  u->right->right = NULL;

  t->left = new node;
  node * a = t->left;
  a->data = 4;
  a->left = NULL;
  a->right = NULL;

  y->right = new node;
  node * b = y->right;
  b->data = 4;
  b->left = NULL;
  b->right = NULL;

  e->right = new node;
  node * c = y->right;
  c->data = 4;
  c->left = NULL;
  c->right = NULL;

  r->left = new node;
  node * d = y->right;
  d->data = 4;
  d->left = NULL;
  d->right = NULL;


	node * root = q;
	return root;
}

void preOrder(node * root)
{
  if (root)
  {
    cout << root->data;
    preOrder(root->left);
    preOrder(root->right);
  }
}



int abs(int x, int y)
{
  if (x>y)
    return x-y;
  else
    return y-x;
}

int max(int x, int y)
{
  if (x>y)
    return x;
  else
    return y;
}

int isHBalanced(node * root)
{
  if (!root)
    return 0;
  if (!root->left && !root->right)
    return 0;
  int LHeight = isHBalanced(root->left);
  int RHeight = isHBalanced(root->right);

  if (LHeight == -2 || RHeight == -2)
    return -2;

  if (abs(LHeight, RHeight) > 1)
      return -2;

  return max(LHeight, RHeight) + 1;
}

bool balanced(node * root)
{
  if (!root)
    return false;

  return (isHBalanced(root) != -2);
}

vector<node *> pathToLeaves(node* root)
{
  if (!root)
  {
    vector<node *> vec;
    return vec;
  }
  if (root->left == NULL && root->right == NULL)
  {
      vector<node *> vec;
      node * curr = new node;
      curr->left = NULL; curr->right = NULL;
      curr ->data = root->data;
      vec.push_back(curr);
      return vec;
  }
  // cout << root->data << endl;

  vector<node *> vecTwoLeft = pathToLeaves(root->left);
  vector<node *> vecTwoRight = pathToLeaves(root->right);
  vector<node *> newVecTwo;


    node * curr;
    for (int i = 0; i < vecTwoLeft.size(); i++)
    {
      curr = new node;
      curr->data = root->data;
      curr->left = vecTwoLeft[i];
      curr->right = NULL;
      newVecTwo.push_back(curr);
    }

    for (int i = 0; i < vecTwoRight.size(); i++)
    {
      curr = new node;
      curr->data = root->data;
      curr->right = vecTwoRight[i];
      curr->left = NULL;
      newVecTwo.push_back(curr);
    }


  return newVecTwo;
}

void levelOrder(node * root)
{
  queue<node *> q;
  q.push(root);

  node * curr = NULL;
  while (!q.empty())
  {

    curr = q.front(); q.pop();

    if (curr)
    {  cout << curr->data << endl;
      q.push(curr->left);
      q.push(curr->right);
    }
  }
}

void deleteNodes(node * root)
{
  if (!root)
  {}

  else
  {
    node * left = root->left;
    node * right = root->right;
    deleteNodes(left);
    deleteNodes(right);

    delete root;
  }
}


node * mirrorImage(node * root)
{
  if (!root)
    return NULL;

  node * formerLeft = root->left;
  root->left = mirrorImage(root->right);
  root->right = mirrorImage(formerLeft);

  return root;
}

void doSubtraction(node * root)
{
  if(!root)
  {

  }
  else
  {
    doSubtraction(root->left);
    doSubtraction(root->right);

    if (root->left && root->right)
    {
      root->data -= (root->left->data + root->right->data);
    }

    else if (root->left)
    {
      root->data -= (root->left->data);
    }

    else if (root->right)
    {
      root->data -= (root->right->data);
    }
  }
}

int main()
{
  node * root = initialize();
  levelOrder(root);
  cout << balanced(root) << endl;


  // root = mirrorImage(root);
  // cout << "Break in mirror" << endl;
  // levelOrder(root);
  // cout << "PreStart" << endl;




  // vector<node *> pathTo = pathToLeaves(root);
  //
  // cout << "going into loops" << endl;
  //
  // for (uint i  = 0; i < pathTo.size(); i ++)
  // {
  //
  //   levelOrder(pathTo[i]);
  //   cout << endl;
  // }
  //
  // cout << "going into deleteNodes" << endl;
  //
  // deleteNodes(root);
  //
  // for (uint i  = 0; i < pathTo.size(); i ++)
  // {
  //   deleteNodes(pathTo[i]);
  // }

    deleteNodes(root);
}
