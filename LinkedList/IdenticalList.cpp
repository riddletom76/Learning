#include<iostream>
#include"LinkedList.h"
using namespace std;
//iterative
bool IdenticalLists(Node* list1, Node* list2){
	Node* temp1 = list1;
	Node* temp2 = list2;
	while(temp1!=NULL && temp2!=NULL){
		if(temp1->data != temp2->data){
			return false;
		}
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	if(temp1!=NULL || temp2!=NULL){
		return false;
	}
	return true;
}
//recursive
bool IdenticalListsRecursive(Node* list1, Node* list2){
	if(list1==NULL && list2!=NULL){
		return false;
	}
	if(list1!=NULL && list2==NULL){
		return false;
	}
	if(list1->data != list2->data){
		return false;
	}
	else{
		return true;
	}
	return IdenticalLists(list1->next, list2->next);
}
int main(){
	Node* list1 = NULL;
	Node* list2 = NULL;
	list1 = Push(list1,1);
	list1 = Push(list1,2);
	list1 = Push(list1,3);
	list2 = Push(list2,1);
	list2 = Push(list2,2);
	list2 = Push(list2,3);
	//list2 = Push(list2,4);
	cout<<IdenticalLists(list1, list2);
}