#include<iostream>
#include"LinkedList.h"
using namespace std;

Node* AlternateOddEven(Node* head){
	Node* temp = head->next;
	Node* prev = head;
	Node* even = NULL;
	while(temp!=NULL){
		Node* next = temp->next;
		if(temp->data%2!=0){
			prev->next = temp->next;
			temp->next = head;
			head = temp;
		}else{
			prev = temp;
		}	
		temp = next;
	}
	temp = head;
	while(temp->data%2!=0){
		prev=temp;
		temp = temp->next;
	}
	prev->next = NULL;
	even = temp;
	temp = head;
	Node* evenNode = even;
	while(temp!=NULL && evenNode!=NULL){
		Node* tempNext = temp->next;
		Node* evenNodeNext = evenNode->next;
		temp->next = evenNode;
		evenNode->next = tempNext;
		temp = tempNext;
		evenNode = evenNodeNext;
	}
	return head;
}
//11 -> 20 -> 40 -> 55 -> 77 -> 80 -> NULL
//10 -> 1 -> 2 -> 3 -> 5 -> 6 -> 7 -> 8 -> NULL
int main(){
	Node* head = NULL;
	head = Push(head, 11);
	head = Push(head, 20);
	head = Push(head, 40);
	head = Push(head, 55);
	head = Push(head, 77);
	head = Push(head, 80);
	PrintLinkedList(head);
	head = AlternateOddEven(head);
	PrintLinkedList(head);
	head = NULL;
	head = Push(head, 10);
	head = Push(head, 1);
	head = Push(head, 2);
	head = Push(head, 3);
	head = Push(head, 5);
	head = Push(head, 6);
	head = Push(head, 7);
	head = Push(head, 8);
	PrintLinkedList(head);
	head = AlternateOddEven(head);
	PrintLinkedList(head);
}