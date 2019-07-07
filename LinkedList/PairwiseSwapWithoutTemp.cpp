#include<iostream>
#include"LinkedList.h"
using namespace std;

Node* PairWiseSwap(Node* head){
	Node* temp = head;
	Node* prev = NULL;
	while(temp!=NULL && temp->next!=NULL){
		Node* inter = NULL;
		if(temp == head){
			head = temp->next;
		}
		if(prev!=NULL){
			prev->next = temp->next;
		}
		prev = temp;
		inter = temp->next->next;
		temp->next->next = temp;
		temp->next = inter;
		temp = inter;
	}
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
	head = PairWiseSwap(head);
	PrintLinkedList(head);
}