//My solution for: https://www.geeksforgeeks.org/write-a-function-that-counts-the-number-of-times-a-given-int-occurs-in-a-linked-list/
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

void Push(Node** head, int element){
    Node* newNode = new Node();
    newNode->data = element;
    if(*head==NULL){
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
    if(head==NULL){
        cout<<"Linked list is empty"<<endl;
    }else{
        while(head!=NULL){
            cout<<head->data<<" ";
            head = head->next;
        }
        cout<<endl;
    }
}

void PrintOccurenceIterative(Node* head, int key){
    int count = 0;
    while(head!=NULL){
        if(head->data == key){
            count++;
        }
        head = head->next;
    }
    cout<<"Occurance for the given key "<<key<<" in the given linked list is "<<count<<endl;
}

int OccuranceRecursive(Node* head, int key){
    if(head==NULL){
        return 0;
    }    
    if(head->data == key){
        return 1+OccuranceRecursive(head->next, key);
    }else{
        return OccuranceRecursive(head->next, key);
    }
}

int main(int argc, char const *argv[])
{
    Node *head = NULL;
    Push(&head, 10);
    Push(&head, 20);
    Push(&head, 10);
    Push(&head, 30);
    Push(&head, 10);
    Push(&head, 40);
    Push(&head, 10);
    Push(&head, 50);
    Push(&head, 10);
    Push(&head, 60);
    PrintLinkedList(head);
    PrintOccurenceIterative(head, 10);
    cout<<OccuranceRecursive(head,10);
    return 0;
}
