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

 Node* GetMiddleNode(Node* head){
 	if(head == NULL){
 		return NULL;
 	}else{
 		Node* slow = head;
 		Node* fast = head;
 		while(fast->next!=NULL && fast->next->next!=NULL){
 			slow = slow->next;
 			fast = fast->next;
 			fast = fast->next;
 		}
 		return slow;
 	}
 }

Node* Merge(Node* first, Node* last){
	Node* newList = NULL;
	
}

Node* MergeSort(Node* head){
	Node* firstHalf = head;
	Node* secondHalf = NULL;
	Node* temp = GetMiddleNode(firstHalf);
	secondHalf = temp->next;
	temp->next = NULL;
	return Merge(MergeSort(firstHalf), MergeSort(secondHalf));
}

 int main(){
 	Node* head = NULL;
 	head = Push(head, 10);
 	head = Push(head, 20);
 	head = Push(head, 30);
 	head = Push(head, 40);
 	head = Push(head, 50);
 	head = Push(head, 60);
 	PrintLinkedList(head);
 	Node* middle = GetMiddleNode(head);
 	cout<<middle->data;
 }