#include<iostream>
#include"LinkedList.h"
using namespace std;

void SumEqual(Node* head1, Node* head2, Node* head3, int referenceSum){
	Node* temp1 = head1;
	Node* temp2 = head2;
	Node* temp3 = head3;
	while(temp1!=NULL){
		temp2 = head2;
		while(temp2!=NULL){
			temp3 = head3;
			while(temp3!=NULL){
				if(temp1->data + temp2->data + temp3->data == referenceSum){
					cout<<temp1->data<<" "<<temp2->data<<" "<<temp3->data<<" = "<<temp1->data + temp2->data + temp3->data<<endl;
				}
				temp3 = temp3->next;
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}

int main(){
	Node* head1 = NULL;
	Node* head2 = NULL;
	Node* head3 = NULL;
	head1 = Push(head1, 10);
	head2 = Push(head2, 20);
	head3 = Push(head3, 30);
	head1 = Push(head1, 40);
	head2 = Push(head2, 50);
	head3 = Push(head3, 60);
	head1 = Push(head1, 70);
	head2 = Push(head2, 80);
	head3 = Push(head3, 90);
	PrintLinkedList(head1);
	PrintLinkedList(head2);
	PrintLinkedList(head3);
	SumEqual(head1, head2, head3, 150);
}