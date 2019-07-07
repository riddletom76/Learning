#include<iostream>
#include"LinkedList.h"
using namespace std;

Node* DeleteNAfterM(Node* head, int m, int n){
	int pos = 0;
	Node* temp = head;
	Node* prev = NULL;
	while(temp!=NULL && pos<m){
		prev = temp;
		temp = temp->next;
		pos++;
	}
	int delNodes = 0;
	while(delNodes < n){
		Node* del = temp;
		if(del == head){
			head = head->next;
		}
		if(prev!=NULL){
			prev->next = temp->next;	
		}		
		temp = temp->next;
		delete(del);
		delNodes++;
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
	head = DeleteNAfterM(head, 0, 2);
	PrintLinkedList(head);
}