#ifndef Linked_List_Include
#define Linked_List_Include
#include<iostream>
class Node{
public:
	int data;
	Node* next;
	Node(){
		next = NULL;
	}
};
Node* Push(Node* head, int newNodeData);
void PrintLinkedList(Node* head);

#endif