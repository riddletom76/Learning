#include<iostream>
#include"LinkedList.h"
using namespace std;

void ZigZag(Node* head){
	Node* temp = head;
	bool flag = true;
	while(temp!=NULL && temp->next!=NULL){
		if(flag){
			if(temp->data > temp->next->data){
				int tempVar = temp->data;
				temp->data = (temp->next)->data;
				(temp->next)->data = tempVar;
			}
		}else{
			if(temp->data < temp->next->data){
				int tempVar = temp->data;
				temp->data = (temp->next)->data;
				(temp->next)->data = tempVar;
			}
		}
		flag = !flag;
		temp = temp->next;
	}
}

// Input:  11->15->20->5->10
// Output: 11->20->5->15->10

int main(){
	Node* head = NULL;
	head = Push(head, 11);
	head = Push(head, 15);
	head = Push(head, 20);
	head = Push(head, 5);
	head = Push(head, 10);
	PrintLinkedList(head);
	ZigZag(head);
	PrintLinkedList(head);
}