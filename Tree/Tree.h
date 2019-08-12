#ifndef Tree_Header
#define Tree_Header
#include<iostream>

class Node{
public:
	int data;
	Node* right;
	Node* left;
	Node(){
		right = NULL;
		left = NULL;
	}
};

void PreorderTraversal(Node* root);
void PostorderTraversal(Node* root);
void InorderTraversal(Node* root);
Node* InsertNode(Node* root, int data);
#endif