#include<iostream>
#include"LinkedList.h"
using namespace std;

void AddOne(Node* head){
	Node* temp = head;
	int carry = 0;
	temp->data = temp->data +1;
	while(temp!=NULL){
		temp->data = temp->data + carry;
		if(temp->data > 9){
			carry = 1;
			temp->data = temp->data % 10;
		}
		temp = temp->next;
	}
}

int main(){
	Node* head = NULL;
	head = Push(head, 9);
	head = Push(head, 9);
	head = Push(head, 9);
	head = Push(head, 1);
	PrintLinkedList(head);
	AddOne(head);
	PrintLinkedList(head);
}