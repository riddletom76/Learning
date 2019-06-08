#include<iostream>
#include "LinkedList.h"
using namespace std;

Node* Push(Node* head, int newNodeData){
	Node* newNode = new Node();
	newNode->data = newNodeData;
	if(head == NULL){
		head = newNode;
	}else{
		Node* temp = head;
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}
	return head;
}

void PrintLinkedList(Node* head){
	Node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}