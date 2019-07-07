#include<iostream>
#include"LinkedList.h"
using namespace std;

Node* Sort(Node* head){
	Node* temp = head;
	Node* zeroHead = NULL;
	Node* oneHead = NULL;
	Node* twoHead = NULL;
	Node* zero = NULL;
	Node* one = NULL;
	Node* two = NULL;
	while(temp!=NULL){
		if(temp->data == 0){
			if(zeroHead == NULL){
				zeroHead = temp;
				zero = zeroHead;
				temp = temp->next;
				continue;
			}
			zero->next = temp;
			zero = zero->next;
		}else if(temp->data == 1){
			if(oneHead == NULL){
				oneHead = temp;
				one = oneHead;
				temp = temp->next;
				continue;
			}
			one->next = temp;
			one = one->next;
		}else if(temp->data == 2){
			if(twoHead == NULL){
				twoHead = temp;
				two = twoHead;
				temp = temp->next;
				continue;
			}
			two->next = temp;
			two = two->next;
		}
		temp = temp->next;
	}
	two->next = NULL;
	head = zeroHead;
	zero->next = oneHead;
	one->next = twoHead;
	return head;
}

int main(){
	Node* head = NULL;
	head = Push(head, 1);
	head = Push(head, 2);
	head = Push(head, 1);
	head = Push(head, 0);
	head = Push(head, 1);
	head = Push(head, 0);
	head = Push(head, 2);
	head = Push(head, 2);
	head = Push(head, 1);
	head = Push(head, 2);
	head = Push(head, 0);
	PrintLinkedList(head);
	head = Sort(head);
	PrintLinkedList(head);
}