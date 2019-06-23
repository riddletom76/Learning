#include<iostream>
#include"LinkedList.h"
using namespace std;

Node* AddTwoNumbers(Node* head1, Node* head2){
	if(head1 == NULL){
		return head2;
	}
	if(head2 == NULL){
		return head1;
	}
	Node* temp1 = head1;
	Node* temp2 = head2;
	Node* res = NULL;
	int carry = 0;
	PrintLinkedList(temp1);
	PrintLinkedList(temp2);
	while(temp1!=NULL && temp2!=NULL){
		int localres = temp1->data + temp2->data + carry;
		if(localres > 9){
			carry = 1;
			localres = localres%10;
		}else{
			carry = 0;
		}
		res = Push(res, localres%10);
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	PrintLinkedList(res);
	while(temp1!=NULL){
		int localres = temp1->data + carry;
		if(localres > 9){
			carry = 1;
			localres = localres%10;
		}else{
			carry = 0;
		}
		res = Push(res, localres%10);
		temp1 = temp1->next;
	}
	while(temp2!=NULL){
		int localres = temp2->data + carry;
		if(localres > 9){
			carry = 1;
			localres = localres%10;
		}else{
			carry = 0;
		}
		res = Push(res, localres%10);
		temp2 = temp2->next;
	}
	return res;
}
// 5->6->3
// 8->4->2
int main(){
	Node* head1 = NULL;
	Node* head2 = NULL;
	Node* result = NULL;
	// head1 = Push(head1, 5);
	// head1 = Push(head1, 6);
	// head1 = Push(head1, 3);
	// head2 = Push(head2, 8);
	// head2 = Push(head2, 4);
	// head2 = Push(head2, 2);
	head1 = Push(head1, 7);
	head1 = Push(head1, 5);
	head1 = Push(head1, 9);
	head1 = Push(head1, 4);
	head1 = Push(head1, 6);
	head2 = Push(head2, 8);
	head2 = Push(head2, 4);
	result = AddTwoNumbers(head1, head2);
	PrintLinkedList(result);
}