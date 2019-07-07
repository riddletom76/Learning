#include<iostream>
#include"LinkedList.h"
using namespace std;

//iterative
Node* DeleteGreaterRight(Node* head){
	Node* temp = head;
	Node* prev = NULL;
	while(temp!=NULL && temp->next!=NULL){
		Node* next = temp->next;
		if(temp->data < (temp->next)->data){
			if(temp == head){
				head = next;
				prev = NULL;
			}
			if(prev!=NULL){
				prev->next = temp->next;
			}
			Node* del = temp;
			delete(del);
		}else{
			prev = temp;
		}
		temp = next;
	}	
	return head;
}

Node* Reverse(Node* head){
	Node* temp = head;
	Node* prev = NULL;
	while(temp!=NULL){
		Node* next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next;
	}
	return prev;
}

int main(){
	Node* head = NULL;
	head = Push(head, 12);
	head = Push(head, 15);
	head = Push(head, 10);
	head = Push(head, 11);
	head = Push(head, 5);
	head = Push(head, 6);
	head = Push(head, 2);
	head = Push(head, 3);
	PrintLinkedList(head);
	head = DeleteGreaterRight(head);
	PrintLinkedList(head);
	Node* head2 = NULL;
	head2 = Push(head2, 10);
	head2 = Push(head2, 20);
	head2 = Push(head2, 30);
	head2 = Push(head2, 40);
	head2 = Push(head2, 50);
	head2 = Push(head2, 60);
	PrintLinkedList(head2);
	head2 = DeleteGreaterRight(head2);
	PrintLinkedList(head2);
}