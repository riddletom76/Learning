#include<iostream>
#include"LinkedList.h"
using namespace std;
//iterative
Node* DeleteAlternate(Node* head){
	Node* temp = head;
	while(temp!=NULL && temp->next!=NULL){
		Node* del = temp->next;
		temp->next = del->next;
		delete(del);
		temp = temp->next;
	}
	return head;
}
//recursive
void DeleteAlternateRecursive(Node* head){
	if(head == NULL){
		return;
	}
	Node* del = head->next;
	if(del == NULL){
		return;
	}
	head->next = del->next;
	delete(del);
	DeleteAlternateRecursive(head->next);
}
int main(){
	Node* head = NULL;
	head = Push(head, 1);
	head = Push(head, 2);
	head = Push(head, 3);
	head = Push(head, 4);
	head = Push(head, 5);
	PrintLinkedList(head);
	head = DeleteAlternate(head);
	DeleteAlternateRecursive(head);
	PrintLinkedList(head);
}