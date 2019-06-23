#include<iostream>
#include"LinkedList.h"
using namespace std;

Node* Rotate(Node* head, int k){
	// if k is 0
	if(k == 0){
		return head;
	}
	Node* temp = head;
	int pos = 1;
	while(temp!=NULL && pos<k){
		temp = temp->next;
		pos++;
	}
	// if k = length of linked list then return the same linked list
	if(temp->next == NULL){
		return head;
	}
	//rotate the linked list for k =  head+1 from length-1
	Node* newHead = temp->next;
	temp->next = NULL;
	temp = head;
	Node* newtemp = newHead;
	while(newtemp->next != NULL){
		newtemp = newtemp->next;
	}
	while(temp!=NULL){
		newtemp->next = temp;
		temp = temp->next;
		newtemp = newtemp->next;
	}
	return newHead;
}

int main(){
	Node* head = NULL;
	head = Push(head, 10);
	head = Push(head, 20);
	head = Push(head, 30);
	head = Push(head, 40);
	head = Push(head, 50);
	head = Push(head, 60);
	head = Rotate(head, 6);
	PrintLinkedList(head);
}
