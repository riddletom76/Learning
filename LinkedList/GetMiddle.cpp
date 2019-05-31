//My solution for: https://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/
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

void PrintMiddleOfLinkedList(Node* head){
    int length = 0;
    Node* temp = head;
    while(temp!=NULL){
        temp = temp->next;
        length++;
    }
    int pos = 0;
    if(length%2==0){
        pos = length/2;
    }else{
        pos = (length-1)/2;
    }
    int count = 0;
    while(count<pos){
        head = head->next;
        count++;
    }
    cout<<"Middle of this linked list is "<<head->data<<endl;
}

//alternate solution - using two pointers
void PrintMiddleOfLinkedListTwoPtr(Node* head){
    Node* slowPtr = head;
    Node* fastPtr = head;
    while((fastPtr->next!=NULL)){
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next;
        if(fastPtr->next!=NULL){
            fastPtr = fastPtr->next;    
        }
    }
    cout<<"Middle of this linked list is "<<slowPtr->data<<endl;
}

int main(int argc, char const *argv[])
{
    Node *head = NULL;
    Push(&head, 10);
    Push(&head, 20);
    Push(&head, 30);
    Push(&head, 40);
    PrintLinkedList(head);
    PrintMiddleOfLinkedList(head);
    PrintMiddleOfLinkedListTwoPtr(head);
    Push(&head, 50);
    PrintLinkedList(head);
    PrintMiddleOfLinkedList(head);
    PrintMiddleOfLinkedListTwoPtr(head);
    Push(&head, 60);
    PrintLinkedList(head);
    PrintMiddleOfLinkedList(head);
    PrintMiddleOfLinkedListTwoPtr(head);
    return 0;
}