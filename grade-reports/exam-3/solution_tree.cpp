#include "common.h"
#include <iostream>

using namespace std;

void updateDiff(Node<int> *&root)
{
	if (!root)
		return;

	updateDiff(root->left);
	updateDiff(root->right);

	if (!root->left & !root->right)
	{
	}

	else if (!root->left)
	{
		root->data -= root->right->data;
	}

	else if (!root->right)
	{
		root->data -= root->left->data;
	}
	
	else
	{
		root->data -= (root->left->data + root->right->data);
	}
}
