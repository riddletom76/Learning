#include<iostream>
#include"LinkedList.h"

using namespace std;

//iterative method
Node* ReverseLinkedList(Node* head){
	Node* curr = head;
	Node* prev = NULL;
	while(curr!=NULL){
		Node* temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	head = prev;
	return head;
}

//recursive solution from GFG
void ReverseRecursive(Node** head){
	if(*head == NULL){
		return;
	}
	Node* first = *head;
	Node* rest = first->next;
	if(rest == NULL){
		return;
	}
	ReverseRecursive(&rest);
	first->next->next = first;
	first->next = NULL;
	*head = rest;
}

int main(){
	Node* head = NULL;
	head = Push(head, 10);
	head = Push(head, 20);
	head = Push(head, 30);
	head = Push(head, 40);
	head = Push(head, 50);
	head = Push(head, 60);
	head = Push(head, 70);
	head = Push(head, 80);
	PrintLinkedList(head);
	head = ReverseLinkedList(head);
	PrintLinkedList(head);
	ReverseRecursive(&head);
	PrintLinkedList(head);
}