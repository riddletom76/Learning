//My solution for: https://www.geeksforgeeks.org/find-length-of-a-linked-list-iterative-and-recursive/
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(){
        next = NULL;
    }
};

Node* PushData(Node* head, int newData){
Node* newNode = new Node();
newNode->data = newData;
newNode->next = head;
//head->next = newNode;
return newNode;
}

void PrintLinkedList(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
void LengthOfLinkedListIterative(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    cout<<"length of linked list "<<count<<endl;
}

int LengthOfLinkedListRecursive(Node* head){
    if(head == NULL){
        return 0;
    }
    return 1+LengthOfLinkedListRecursive(head->next);
}
int main()
{
    /* code */
    Node* head = NULL;
    head = PushData(head, 30);
    head = PushData(head, 20);
    head = PushData(head, 10);
    PrintLinkedList(head);
    LengthOfLinkedListIterative(head);
    cout<<"length of linked list "<<LengthOfLinkedListRecursive(head)<<endl;
    return 0;
}