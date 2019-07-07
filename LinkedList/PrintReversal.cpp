//my solution for - https://www.geeksforgeeks.org/write-a-recursive-function-to-print-reverse-of-a-linked-list/
#include<iostream>
#include "LinkedList.h"
using namespace std;

//revursive solution to print the reverse of a linked list without actually reversing it
void PrintReversal(Node* head){
	if(head == NULL){
		return;
	}
	PrintReversal(head->next);
	cout<<head->data<<" ";
}

int main(){
	Node* head = NULL;
	head = Push(head, 10);
	head = Push(head, 20);
	head = Push(head, 30);
	head = Push(head, 40);
	head = Push(head, 50);
	head = Push(head, 60);
	PrintLinkedList(head);
	PrintReversal(head);
	PrintLinkedList(head);
}