//My solution for: https://www.geeksforgeeks.org/write-a-c-function-to-detect-loop-in-a-linked-list/
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

//this method requires adding a flag "visited"
void DetectLoop(Node** head){
    Node* temp = *head;
    while(temp!=NULL){
        if(temp->visited == false){
            temp->visited = true;
            temp = temp->next;
        }
        else{
            cout<<"Origin of loop detected "<<temp->data<<endl;
            break;
        }
    }
}

//alternate method
void DetectLoopAlternate(Node** head){
    Node* slowPtr = *head;
    Node* fastPtr = *head;
    while(fastPtr!=NULL && fastPtr->next!=NULL){
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next;
        fastPtr = fastPtr->next;
        if(slowPtr->data == fastPtr->data){
            cout<<"Loop detected at "<<fastPtr->data<<endl;
            break;
        }
    }
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
    DetectLoop(&head);
    DetectLoopAlternate(&head);
    return 0;
}

