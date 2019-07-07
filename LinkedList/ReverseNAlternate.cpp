#include<iostream>
#include"LinkedList.h"
using namespace std;

//Revusive Solution
Node* _Alternate(Node* head, int key, bool toReverse){
	if(head == NULL){
		return NULL;
	}
	Node* curr = head;
	Node* prev = NULL;
	Node* temp;
	int count = 1;
	while((count <= key) && (curr != NULL)){
		temp = curr->next;
		if(toReverse == true){
			curr->next = prev;
		}		
		prev = curr;
		curr = temp;
		count++;
	}
	
	if(toReverse == true){
		head->next = _Alternate(curr, key, !toReverse);
		return prev;
	}else{
		prev->next = _Alternate(curr, key, !toReverse);
		return head;
	}
}

Node* AlterNate(Node* head, int key){
	return _Alternate(head, key, true);
}


//Alternate Solution

Node* AlternateReverse(Node* head, int key){
	Node* curr = head;
	Node* prev = NULL;
	Node* next;
	int count = 1;
	while((count<=key) && (curr!=NULL)){
		count++;
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		cout<<"count "<<count<<endl;
		cout<<"curr ";
		PrintLinkedList(curr);
		cout<<"prev ";
		PrintLinkedList(prev);
	}
	cout<<"curr ";
	PrintLinkedList(curr);
	cout<<"prev ";
	PrintLinkedList(prev);
	if(head!=NULL){
		head->next = curr;
	}
	count = 1;
	while((curr!=NULL) && (count<key)){
		curr = curr->next;
		count++;
	}
	cout<<"curr after skipping"<<endl;
	PrintLinkedList(curr);
	if(curr!=NULL){
		curr->next = AlternateReverse(curr->next, key);
	}
	return prev;
}
int main(){
	Node* head = NULL;
	head = Push(head, 10);
	head = Push(head, 20);
	head = Push(head, 30);
	head = Push(head, 40);
	head = Push(head, 50);
	head = Push(head, 60);
	head = Push(head, 70);
	head = Push(head, 80);
	head = Push(head, 90);
	PrintLinkedList(head);
	head = AlterNate(head, 3);
	head = AlternateReverse(head,3);
	PrintLinkedList(head);
}