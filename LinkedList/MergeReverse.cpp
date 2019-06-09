//my solution for - https://www.geeksforgeeks.org/merge-two-sorted-linked-lists-such-that-merged-list-is-in-reverse-order/
#include<iostream>
#include"LinkedList.h"
using namespace std;

Node* Merge(Node* head1, Node* head2){
	Node* temp1 = head1;
	Node* temp2 = head2;
	Node* result = NULL;
	while((temp1 != NULL) && (temp2 != NULL)){
		Node* temp = NULL;
		if(temp1->data <= temp2->data){
			temp = temp1->next;
			if(result == NULL){
				result = temp1;
				temp1->next = NULL;
			}
			else{
				temp1->next = result;
				result = temp1;
			}
			temp1 = temp;
		}else{
			temp = temp2->next;
			if(result == NULL){
				result = temp2;
				temp2->next = NULL;
			}
			else{
				temp2->next = result;
				result = temp2;
			}
			temp2 = temp;
		}
	}
	while(temp1!=NULL){
		Node* temp = temp1->next;
		if(result == NULL){
			result = temp1;
			temp1->next = NULL;
		}else{
			temp1->next = result;
			result = temp1;
		}
		temp1 = temp;
	}
	while(temp2!=NULL){
		Node* temp = temp2->next;
		if(result == NULL){
			result = temp2;
			temp2->next = NULL;
		}else{
			temp2->next = result;
			result = temp2;
		}
		temp2 = temp;
	}
	return result;
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