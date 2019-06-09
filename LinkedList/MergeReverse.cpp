// a: 5->10->15->40
// b: 2->3->20 

#include<iostream>
#include"LinkedList.h"
using namespace std;

Node* Reverse(Node* head){
	Node* curr = head;
	Node* prev = NULL;
	while(curr!=NULL){
		Node* temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	return prev;
}

Node* Merge(Node* head1, Node* head2){
	if(head1 == NULL){
		return Reverse(head2);
	}
	if(head2 == NULL){
		return Reverse(head1);
	}
	Node* temp1 = head1;
	Node* temp2 = head2;
	Node* result = NULL;
	Node* resultEnd = NULL;
	while(temp1!=NULL && temp2!=NULL){
		if(temp1->data<=temp2->data){
			if(result==NULL){
				result = temp1;
				resultEnd = result;
			}else{
				resultEnd->next = temp1;
				resultEnd = temp1;
			}
			temp1 = temp1->next;
		}else{
			if(result == NULL){
				result = temp2;
				resultEnd = result;
			}else{
				resultEnd->next = temp2;
				resultEnd = temp2;
			}
			temp2 = temp2->next;
		}
	}
	while(temp1!=NULL){
		resultEnd->next = temp1;
		resultEnd = temp1;
		temp1 = temp1->next;
	}
	while(temp2!=NULL){
		resultEnd->next = temp2;
		resultEnd = temp2;
		temp2 = temp2->next;
	}
	return Reverse(result);
}
int main(){
	Node* head1 = NULL;
	head1 = Push(head1, 5);
	head1 = Push(head1, 10);
	head1 = Push(head1, 15);
	head1 = Push(head1, 40);
	Node* head2 = NULL;
	head2 = Push(head2, 2);
	head2 = Push(head2, 3);
	head2 = Push(head2, 20);
	cout<<"LinkedList1"<<endl;
	PrintLinkedList(head1);
	cout<<"LinkedList2"<<endl;
	PrintLinkedList(head2);
	Node* head3 = Merge(head1, head2);
	PrintLinkedList(head3);
}