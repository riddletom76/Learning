//my solution - https://www.geeksforgeeks.org/merge-sort-for-linked-list/
#include<iostream>
using namespace std;
 class Node{
 public:
 	int data;
 	Node* next;
 	Node(){
 		next = NULL;
 	}
 };

 Node* Push(Node* head, int data){
 	Node* newNode = new Node();
 	newNode->data = data;
 	if(head == NULL){
 		head = newNode;
 	}else{
 		Node* temp = head;
 		while(temp->next!=NULL){
 			temp = temp->next;
 		}
 		temp->next = newNode;
 	}
 	return head;
 }

 void PrintLinkedList(Node* head){
 	Node* temp = head;
 	while(temp!=NULL){
 		cout<<temp->data<<" ";
 		temp = temp->next;
 	}
 	cout<<endl;
 }

 int GetLengthOfLinkedList(Node* head){
 	int length = 0;
 	Node* temp = head;
 	while(temp!=NULL){
 		temp = temp->next;
 		length++;
 	}
 	return length;
 }

Node* Merge(Node* first, Node* second){
	Node* newList = NULL;
	if(first == NULL){
		return second;
	}
	if(second == NULL){
		return first;
	}
	if(first->data <= second->data){
		newList = first;
		newList->next = Merge(first->next, second);
	}else{
		newList = second;
		newList->next = Merge(first, second->next);
	}
	return newList;
}

Node* MergeSort(Node* head){
	int mid = GetLengthOfLinkedList(head)/2;
	Node* firstHalf = head;
	if(head->next==NULL){
		return head;
	}
	while(mid-1 > 0){
		firstHalf = firstHalf->next;
		mid--;
	}
	Node* secondHalf = firstHalf->next;
	firstHalf->next = NULL;
	firstHalf = head;
	return Merge(MergeSort(firstHalf), MergeSort(secondHalf));
}

 int main(){
 	Node* head = NULL;
 	head = Push(head, 31);
 	head = Push(head, 25);
 	head = Push(head, 54);
 	head = Push(head, 18);
 	head = Push(head, 5);
 	PrintLinkedList(head);
 	Node* result = MergeSort(head);
 	PrintLinkedList(result);
 }