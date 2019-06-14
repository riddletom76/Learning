#include<iostream>
#include"LinkedList.h"
using namespace std;
void AlterNateSplit(Node* head){
	Node* temp = head;
	Node* newList = NULL;
	Node* tail = NULL;
	while(temp!=NULL && temp->next!=NULL){
		if(newList == NULL){
			newList = temp->next;
			temp->next = newList->next;
			tail = newList;
			temp = temp->next;
			continue;	
		}
		tail->next = temp->next;
		tail = tail->next;
		temp->next = tail->next;
		temp = temp->next;		
	}
	PrintLinkedList(head);
	PrintLinkedList(newList);
}
int main(){
	Node* head = NULL;
	head = Push(head, 0);
	head = Push(head, 1);
	head = Push(head, 0);
	head = Push(head, 1);
	head = Push(head, 0);
	head = Push(head, 1);
	PrintLinkedList(head);
	AlterNateSplit(head);
}