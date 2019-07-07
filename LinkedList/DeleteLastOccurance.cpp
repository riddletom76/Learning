#include<iostream>
#include"LinkedList.h"
using namespace std;

Node* DeleteLastOccurance(Node* head, int key){
	Node* temp = head;
	Node* prevNode = NULL;
	Node* lastNode = NULL;
	Node* prevToLastNode = NULL;
	while(temp!=NULL){
		if(temp->data == key){
			lastNode = temp;
			if(prevNode != NULL){
				prevToLastNode = prevNode;
			}
		}
		prevNode = temp;
		temp = temp->next;
	}
	Node* del = NULL;

	if(prevToLastNode == NULL){
		del = head;
		head = head->next;
	}else{
		prevToLastNode->next = lastNode->next;
		del = lastNode;
	}
	delete(del);
	return head;
}

// Input:   1->2->3->5->2->10, key = 2
// Output:  1->2->3->5->10

int main(){
	Node* head = NULL;
	head = Push(head, 1);
	head = Push(head, 2);
	head = Push(head, 3);
	head = Push(head, 5);
	head = Push(head, 2);
	head = Push(head, 10);
	PrintLinkedList(head);
	head = DeleteLastOccurance(head, 2);
	PrintLinkedList(head);
}