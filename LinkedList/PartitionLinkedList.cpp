#include<iostream>
#include"LinkedList.h"
using namespace std;

Node* PartitionWithOrder(Node* head, int key){
	Node* temp = head;
	Node* lessFirst = NULL;
	Node* lessTail = NULL;
	Node* greaterFirst = NULL;
	Node* greatTail = NULL;
	while(temp!=NULL){
		if(temp->data < key){
			if(lessFirst == NULL){
				lessFirst = temp;
				lessTail = lessFirst;
				temp = temp->next;
				continue;
			}
			lessTail->next = temp;
			lessTail = lessTail->next;
		}else{
			if(greaterFirst==NULL){
				greaterFirst = temp;
				greatTail = greaterFirst;
				temp = temp->next;
				continue;
			}
			greatTail->next = temp;
			greatTail = greatTail->next;
		}
		cout<<"Less" << endl;
		PrintLinkedList(lessFirst);
		cout<<"Great" << endl;
		PrintLinkedList(greaterFirst);
		temp = temp->next;
	}
	if(lessFirst!=NULL){
		lessTail->next = greaterFirst;
		greatTail->next = NULL;
		head = lessFirst;	
	}	
	return head;
}

// Input : 1->4->3->2->5->2->3, 
//         x = 3
// Output: 1->2->2->3->3->4->5

// Input : 1->4->2->10 
//         x = 3
// Output: 1->2->4->10

// Input : 10->4->20->10->3 
//         x = 3
// Output: 3->10->4->20->10 

int main(){
	Node* head = NULL;
	// head = Push(head, 1);
	// head = Push(head, 4);
	// head = Push(head, 3);
	// head = Push(head, 2);
	// head = Push(head, 5);
	// head = Push(head, 2);
	// head = Push(head, 3);
	head = Push(head, 10);
	head = Push(head, 4);
	head = Push(head, 20);
	head = Push(head, 10);
	head = Push(head, 3);
	PrintLinkedList(head);
	head = PartitionWithOrder(head, 3);
	PrintLinkedList(head);
}