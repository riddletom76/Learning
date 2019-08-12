#include<iostream>
#include "Tree.h"
using namespace std;

void PreorderTraversal(Node* root){
	if(root != NULL){
		cout<<root->data<<" ";
		PreorderTraversal(root->left);
		PreorderTraversal(root->right);
	}
}

void InorderTraversal(Node* root){
	if(root != NULL){
		InorderTraversal(root->left);
		cout<<root->data<<" ";
		InorderTraversal(root->right);
	}
}

void PostorderTraversal(Node* root){
	if(root != NULL){
		PostorderTraversal(root->left);
		PostorderTraversal(root->right);
		cout<<root->data<<" ";
	}
}

Node* InsertNode(Node* root, int data){
	Node* newNode =  new Node();
	newNode->data = data;
	if(root == NULL){
		root = newNode;
	}else{
		if(root->data > data){
			root->left = InsertNode(root->left, data);
		}else{
			root->right = InsertNode(root->right, data);
		}
	}
	return root;
}