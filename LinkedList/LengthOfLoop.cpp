//My solution for: https://www.geeksforgeeks.org/find-length-of-loop-in-linked-list/

#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    bool visited;
    Node(){
        next = NULL;
        visited = false;
    }
};

void Push(Node** head, int key){
    Node* newNode = new Node();
    newNode->data = key;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
void PrintLinkedList(Node* head){
    if(head==NULL){
        cout<<"Linked list is empty"<<endl;
        return;
    }
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
void CreateLoop(Node** head){
    Node* temp = *head;
    Node* temp2 = *head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = temp2->next;
}

int Counter(Node* x){
    Node* temp = x;
    int count = 1;
    temp = temp->next;
    while(temp!=x){
        count++;
        temp = temp->next;
    }
    return count;
}

int LengthOfLoop(Node** head){
    Node* slowPtr = *head;
    Node* fastPtr = *head;
    while(fastPtr!=NULL && fastPtr->next!=NULL){
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next;
        fastPtr = fastPtr->next;
        if(slowPtr->data == fastPtr->data){
            break;
        }
    }
    return Counter(slowPtr);
}

int main(int argc, char const *argv[])
{
    Node* head = NULL;
    Push(&head,10);
    Push(&head,20);
    Push(&head,30);
    Push(&head,40);
    PrintLinkedList(head);
    CreateLoop(&head);
    cout<<"Loop is created"<<endl;
    cout<<"Length of loop is "<<LengthOfLoop(&head)<<endl;
    return 0;
}