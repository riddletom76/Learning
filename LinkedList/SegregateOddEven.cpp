//my solution for -https://www.geeksforgeeks.org/segregate-even-and-odd-elements-in-a-linked-list/
//Input: 17->15->8->12->10->5->4->1->7->6->NULL
//Output: 8->12->10->4->6->17->15->5->1->7->NULL
#include<iostream>
#include"LinkedList.h"
using namespace std;

//in this method there are two sublinked lists which keeps track of odd and even elements 
//in the end both are linked and the head is returned
Node* SegregateOddEven(Node* head){
	Node* evenStart = NULL;
	Node* evenEnd = NULL;
	Node* oddStart = NULL;
	Node* oddEnd = NULL;
	Node* temp = head;
	while(temp!=NULL){
		if(((temp->data)%2)==0){
			if(evenStart==NULL){
				evenStart = temp;
				evenEnd = evenStart;
			}else{
				evenEnd->next = temp;
				evenEnd = evenEnd->next;
			}
		}else{
			if(oddStart == NULL){
				oddStart = temp;
				oddEnd = oddStart;
			}else{
				oddEnd->next = temp;
				oddEnd = oddEnd->next;
			}
		}
		cout<<"even ";
		PrintLinkedList(evenStart);
		cout<<"odd ";
		PrintLinkedList(oddStart);
		temp = temp->next;
	}
	evenEnd->next = oddStart;
	oddEnd->next = NULL;
	head = evenStart;
	return head;
}

int main(){
	Node* head = NULL;
	head = Push(head, 17);
	head = Push(head, 15);
	head = Push(head, 8);
	head = Push(head, 12);
	head = Push(head, 10);
	head = Push(head, 5);
	head = Push(head, 4);
	head = Push(head, 1);
	head = Push(head, 7);
	head = Push(head, 6);
	PrintLinkedList(head);
	head=SegregateOddEven(head);
	PrintLinkedList(head);
}