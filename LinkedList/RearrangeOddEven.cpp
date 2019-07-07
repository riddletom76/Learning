#include<iostream>
#include"LinkedList.h"
using namespace std;

Node* Rearrange(Node* head){
	if(head->next==NULL || head == NULL){
		return head;
	}
	Node* temp = head;
	Node* odd = NULL;
	Node* evenFirst = NULL;
	Node* evenTail = NULL;

	while(temp!=NULL){
		if(temp->data%2!=0){
			if(odd == NULL){
				odd = temp;
				head = odd;
				temp = temp->next;
				continue;
			}
			odd->next = temp;
			odd = odd->next;
		}else{
			if(evenFirst == NULL){
				evenFirst = temp;
				evenTail = evenFirst;
				temp = temp->next;
				continue;
			}
			evenTail->next = temp;
			evenTail = evenTail->next;
		}
		temp = temp->next;
	}
	odd->next = evenFirst;
	evenTail->next = NULL;
	return head;
}

int main(){
	Node* head =NULL;
	head = Push(head, 2);
	head = Push(head, 1);
	head = Push(head, 3);
	head = Push(head, 4);
	head = Push(head, 5);
	PrintLinkedList(head);
	head = Rearrange(head);
	PrintLinkedList(head);
}