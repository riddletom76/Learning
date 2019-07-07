#include<iostream>
#include"LinkedList.h"
using namespace std;

void ReverseUsing2Ptr(Node** head){
	Node* curr = *head;
	Node* next = NULL;
	while(curr->next!=NULL){
		next = curr->next;
		curr->next = next->next;
		next->next = *head;
		*head = next;
	}
}

int main(){
	Node* head = NULL;
	head = Push(head, 10);
	head = Push(head, 20);
	head = Push(head, 30);
	head = Push(head, 40);
	head = Push(head, 50);
	head = Push(head, 60);
	PrintLinkedList(head);
	ReverseUsing2Ptr(&head);
	PrintLinkedList(head);
}