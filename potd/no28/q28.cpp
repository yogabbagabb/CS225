#include <iostream>

using namespace std;

struct node{
    int val;
    node * left;
    node * right;
};


void printRight(node * root){
    if(root == NULL){
        cout << "NULL ";
        return;
    }

    cout << root->val << " ";
    printRight(root->right);
}

void printTree(node * root){
    if(root == NULL){
        cout << "NULL ";
        return;
    }
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}


void helper(node * root, node *& developing)
{
	if (!root)
		return;

	helper(root->right, developing);
	helper(root->left, developing);
	if (!developing)
		developing = root;

	else
	{
		root->right = developing;
		developing = root;
	}
}


void helperTwo(node * root, node *& developing)
{
	if (!root)
		return;

	if (!developing)
		developing = root;

	else
	{
		root->right = developing;
		developing = root;
	}
  helperTwo(root->right, developing);
  helperTwo(root->left, developing);

}


void smoosh(node * root){

	node * developing = NULL;
	printTree(root);
	cout << "\n";
  // note I change this below to helperTwo
	helperTwo(root, developing);
  cout << "exit" << endl;
}



int main(){
	node * root = new node;
	root->val = 1;
	node * temp = root;
    temp->left = new node;
    temp->left->val = 2;
    temp = temp->left;
    temp->left = new node;
    temp->left->val = 3;
    temp->left->left = NULL;
    temp->left->right = NULL;
    temp->right = new node;
    temp->right->val = 4;



    temp->right->left = NULL;
    temp->right->right = NULL;
    temp = root;
    temp->right = new node;
    temp->right->val = 5;
    temp->right->left = NULL;
    temp = temp->right;
    temp->right = new node;
    temp->right->val = 6;
	temp = temp->right;
    temp->left = new node;
	temp->left->val = 7;
    temp->left->right = NULL;
    temp->left->left = NULL;
    temp->right = new node;
    temp->right->right = NULL;
    temp->right->left = NULL;
	temp->right->val = 8;
    printTree(root);
    cout << endl;
    smoosh(root);
    printRight(root);
    return 0;
}
