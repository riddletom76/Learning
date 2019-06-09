#include<iostream>
#include "LinkedList.h"
using namespace std;

Node* ReverseNNodes(Node* head, int key){
	int pos = 1;
	Node* temp = head;
	while(pos<key){
		temp = temp->next;
		pos++;
	}
	Node* restOfList = temp->next;
	temp->next = NULL;
	Node* temp1 = head;
	Node* prev = NULL;
	while(temp1!=NULL){
		Node* x = temp1->next;
		temp1->next = prev;
		prev = temp1;
		temp1 = x;
	}
	head = prev;
	temp = prev;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = restOfList;
	return head;
}

int main(){
	Node* head = NULL;
	head = Push(head, 1);
	head = Push(head, 2);
	head = Push(head, 3);
	head = Push(head, 4);
	head = Push(head, 5);
	head = Push(head, 6);
	head = Push(head, 7);
	PrintLinkedList(head);
	head = ReverseNNodes(head, 3);
	PrintLinkedList(head);
}