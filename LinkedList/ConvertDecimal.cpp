#include<iostream>
#include"LinkedList.h"
#include<math.h>
using namespace std;

Node* Reverse(Node* head){
	Node* temp = head;
	Node* prev = NULL;
	while(temp!=NULL){
		Node* tempNext = temp->next;
		temp->next = prev;
		prev = temp;
		temp = tempNext;
	}
	return prev;
}

void ConvertDecimal(Node* head){
	head = Reverse(head);
	Node* temp = head;
	int result = 0;
	int power = 0;
	while(temp!=NULL){
		result += temp->data * pow(2,power);
		temp = temp->next;
		power++;
	}
	cout<<result<<endl;
}

// Input  : 0->0->0->1->1->0->0->1->0
// Output : 50   

// Input  : 1->0->0
// Output : 4

int main(){
	Node* head = NULL;
	head = Push(head, 0);
	head = Push(head, 0);
	head = Push(head, 0);
	head = Push(head, 1);
	head = Push(head, 1);
	head = Push(head, 0);
	head = Push(head, 0);
	head = Push(head, 1);
	head = Push(head, 0);
	// head = Push(head, 1);
	// head = Push(head, 0);
	// head = Push(head, 0);
	PrintLinkedList(head);
	ConvertDecimal(head);
}