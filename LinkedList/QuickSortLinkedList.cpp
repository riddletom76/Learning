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

void Push(Node** head, int value){
	Node* newNode = new Node();
	newNode->data = value;
	newNode->next = NULL;
	if(*head == NULL){
		*head = newNode;
	}else{
		Node* temp = *head;
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

void PrintLinkedList(Node* head){
	Node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}
/*int Partition(Node* head, int first, int last){
	int x = 0;
	Node* temp = head;
	while(x!=first){
		x++;
		temp = temp->next;
	}
	int pivot = temp->data;
	int i = first;
	int j = last;
	Node* tempI = head;
	Node* tempJ = head;
	x = 0;
	while(x!=first){
		tempI = tempI->next;
		x++;
	}
	x = 0;
	while(x!=last){
		tempJ = tempJ->next;
		x++;
	}
	while(i<j){
		while(tempI->data <= pivot){
			i++;
			tempI = tempI->next;
		}
		while(tempJ->data > pivot){
			j--;
			tempJ = tempJ->next;
		}
		int swapper = tempI->data;
		tempI->data = tempJ->data;
		tempJ->data = swapper;
	}
	x = 0;
	temp = head;
	while(x!=first){
		x++;
		temp = temp->next;
	}
	int swapper = tempJ->data;
	tempJ->data = temp->data;
	temp->data = swapper;
	return j;
}
void QuickSort(Node** head, int first, int last){
	if(first<last){
		int pivotIndex = Partition(*head, first, last);
		QuickSort(head, first, pivotIndex);
		QuickSort(head, pivotIndex+1, last);
	}
}*/
Node* GetLastNode(Node* head){
	Node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	return temp;
}

Node* Partition(Node* head, Node* end, Node** newHead, Node** newTail){
	cout<<"Patition Called"<<endl;
	Node* prev = NULL;
	Node* pivot = end;
	Node* curr = head;
	Node* tail = pivot;
	//cout<<"Hello"<<endl;
	
	while(curr!=pivot){
		if(curr->data < pivot->data){
			if(*newHead == NULL){
				*newHead = curr;
			}
			prev = curr;
			curr = curr->next;
		}
		else{
			if(prev){
				prev->next = curr->next;
			}
			Node* temp = curr->next;
			curr->next = NULL;
			tail->next = curr;
			tail = curr;
			curr = temp;
		}
		PrintLinkedList(curr);
	}
	if(*newHead == NULL){
		*newHead = pivot;
	}
	*newTail = tail;
	return pivot;
}
Node* QuickSortRecursive(Node* head, Node* tail){
	Node* newHead = NULL;
	Node* newTail = NULL;
	if(!head || head==tail){
		return head;
	}
	Node* pivot = Partition(head, tail, &newHead, &newTail);
	if(newHead != pivot){
		Node* temp = newHead;
		while(temp->next!=pivot){
			temp = temp->next;
		}
		temp->next = NULL;
		newHead = QuickSortRecursive(newHead, temp);
		temp = GetLastNode(newHead);
		temp->next = pivot;
	}
	pivot->next = QuickSortRecursive(pivot->next, newTail);
	return newHead;
}
void QuickSort(Node** head){
	*head = QuickSortRecursive(*head, GetLastNode(*head));
}
int main(){
	Node* head = NULL;
	Push(&head, 31);
	Push(&head, 25);
	Push(&head, 54);
	Push(&head, 18);
	Push(&head, 5);
	PrintLinkedList(head);
	QuickSort(&head);
	PrintLinkedList(head);
}

