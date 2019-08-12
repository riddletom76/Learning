#include<iostream>
#include"Tree.h"

using namespace std;

int main(){
	Node* root = new Node();
	root->data = 1;
	root->left = new Node();
	root->left->data = 2;
	root->right = new Node();
	root->right->data = 3;
	root->left->left = new Node();
	root->left->left->data = 4;
	root->left->right = new Node();
	root->left->right->data = 5;
	PreorderTraversal(root);
	cout<<endl;
	PostorderTraversal(root);
	cout<<endl;
	InorderTraversal(root);
	cout<<endl;
}