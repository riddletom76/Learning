#include<iostream>
#include"LinkedList.h"
using namespace std;

void SplitLists(Node* head, Node** list1, Node** list2){
	Node* temp = head;
	*list1 = Push(*list1, 0);
	*list2 = Push(*list2, 0);
	Node* l1 = *list1;
	Node* l2 = *list2;
	while(temp!=NULL){
		l1->next = temp;
		l1 = l1->next;
		temp = temp->next;
		if(temp!=NULL){
			l2->next = temp;
			l2 = l2->next;
			temp = temp->next;
		}
	}
	l1->next = NULL;
	l2->next = NULL;
	*list1 = (*list1)->next;
	*list2 = (*list2)->next;
}

void Reverse(Node** list){
	Node* temp = *list;
	Node* prev = NULL;
	while(temp!=NULL){
		Node* tempNext = temp->next;
		temp->next = prev;
		prev = temp;
		temp = tempNext;
	}
	*list = prev;
}

Node* MergeAscending(Node* temp1, Node* temp2){
	Node* head = NULL;
	Node* tail = NULL;
	Node* list1 = temp1;
	Node* list2 = temp2;
	while(list1 != NULL && list2 != NULL){
		if(list1->data < list2->data){
			if(head == NULL){
				head = list1;
				tail = head;
				list1 = list1->next;
				continue;
			}
			tail->next = list1;
			list1 = list1->next;
		}else{
			if(head == NULL){
				head = list2;
				tail = head;
				list2 = list2->next;
				continue;
			}
			tail->next = list2;
			list2 = list2->next;
		}
		tail = tail->next;
	}
	while(list1!=NULL){
		tail->next = list1;
		tail = tail->next;
		list1 = list1->next;
	}
	while(list2!=NULL){
		tail->next = list2;
		tail = tail->next;
		list2 = list2->next;
	}
	return head;
}

Node* SortedList(Node* head){
	Node* list1 = NULL;
	Node* list2 = NULL;
	SplitLists(head, &list1, &list2);
	if(list1->data < list1->next->data){
		Reverse(&list2);
	}else{
		Reverse(&list1);
	}
	head = MergeAscending(list1, list2);
	return head;
}

int main(){
	Node *head = NULL;
	head = Push(head, 10);
	head = Push(head, 40);
	head = Push(head, 53);
	head = Push(head, 30);
	head = Push(head, 67);
	head = Push(head, 12);
	head = Push(head, 89);
	PrintLinkedList(head);
	head = SortedList(head);
	PrintLinkedList(head);
}