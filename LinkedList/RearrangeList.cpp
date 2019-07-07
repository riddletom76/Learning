#include<iostream>
#include"LinkedList.h"
using namespace std;

Node* GetLast(Node* head, int x){
	Node* temp = head;
	Node* prev = NULL;
	while(temp->next!=NULL){
		prev = temp;
		temp = temp->next;
	}
	if(x == 0){
		return prev;
	}
	return temp;
}

Node* Rearrange(Node* head){
	Node* temp = NULL;
	while(temp!=NULL){
		Node* last = GetLast(temp, 1);
		Node* prev = GetLast(temp, 0);
		prev->next = NULL;
		last->next = temp->next;
		temp->next = last;
		temp = last->next;
	}
	return head;
}

int main(){
	Node* head = NULL;
	head = Push(head, 1);
	head = Push(head, 2);
	head = Push(head, 3);
	head = Push(head, 4);
	PrintLinkedList(head);
	head = Rearrange(head);
	PrintLinkedList(head);
}