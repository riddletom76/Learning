#include<iostream>
#include"LinkedList.h"
using namespace std;

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
	PrintLinkedList(head);
}