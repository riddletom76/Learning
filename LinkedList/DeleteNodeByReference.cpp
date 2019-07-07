#include<iostream>
#include"LinkedList.h"
using namespace std;

void DeleteNodeByReference(Node* head, Node* refernceNode){
	if(head == refernceNode){
		if(head->next == NULL){
			cout<<"cant delete the only node in the linked list as this might make the linked list empty"<<endl;
			return;
		}
		head->data = head->next->data;
		Node* del = head->next;
		head->next = head->next->next;
		delete(del);
		return;
	}
	Node* prev = head;
	Node* curr = head->next;
	while(curr!=NULL){
		if(curr == refernceNode){
			prev->next = curr->next;
			Node* del = curr;
			delete(del);
			return;
		}else{
			prev = curr;
			curr = curr->next;
		}
	}
}

int main(){
	Node* head = NULL;
	head = Push(head, 1);
	head = Push(head, 2);
	head = Push(head, 3);
	Node* temp = head;
	DeleteNodeByReference(head, temp);
	PrintLinkedList(head);
}
