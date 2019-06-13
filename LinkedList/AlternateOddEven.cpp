#include<iostream>
#include"LinkedList.h"
using namespace std;

Node* AlternateOddEven(Node* head){
	Node* temp = head;
	Node* newHead = NULL;
	Node* evenHead = NULL;
	Node* evenTail = NULL;
	Node* newTail = NULL;
	Node* prev = NULL;
	while(temp!=NULL){
		Node* next = temp->next;
		if(temp->data%2!=0){
			if(newHead = NULL){
				newHead = temp;
				newTail = newHead;
			}else{
				temp->next= NULL;
				newTail->next = temp;
				newTail = temp;
			}
			prev = temp;
			temp = next;
		}else{
			//Node* next = temp->next;
			if(evenHead == NULL){
				evenHead = temp;
				evenTail = evenHead;
			}else{
				temp->next = NULL;
				evenTail->next = temp;
				evenTail = temp;
			}
			if(prev){
				prev->next = next;
			}
			temp = next;
		}		
	}
	PrintLinkedList(newHead);
	PrintLinkedList(evenHead);
	temp = newHead;
	Node* evenTemp = evenHead;
	while(temp!=NULL && evenTemp!=NULL){
		Node* evenTempNext = evenTemp->next;
		Node* tempNext = temp->next;
		temp->next = evenTemp;
		evenTemp->next = tempNext;
		temp = tempNext;
		evenTemp = evenTempNext;
	}
	return newHead;
}
//11 -> 20 -> 40 -> 55 -> 77 -> 80 -> NULL
//10 -> 1 -> 2 -> 3 -> 5 -> 6 -> 7 -> 8 -> NULL
int main(){
	Node* head = NULL;
	/*head = Push(head, 11);
	head = Push(head, 20);
	head = Push(head, 40);
	head = Push(head, 55);
	head = Push(head, 77);
	head = Push(head, 80);*/
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