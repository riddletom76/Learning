//My solution for: My Solution for: https://www.geeksforgeeks.org/write-a-function-to-get-nth-node-in-a-linked-list/
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

//iterative implementation (0 based indexing)
int GetNthNode(Node* head, int index){
    if(index==0){
        return head->data;
    }else{
        int counter = 0;
        Node* prev = NULL;
        while((counter<index)&&(head!=NULL)){
            counter++;
            prev = head;
            head = head->next;
        }
        if(head!=NULL){
            //if the index is out of bounds for the linked list
            return head->data;    
        }else{
            return -1;   
        }
    }
}

//recursive implementation (1 based indexing)
int GetNthNodeRecursive(Node* head, int index){
    int count = 1;
    if(head == NULL){
        return -1;
    }
    if(count==index){
        return head->data;
    }
    return GetNthNodeRecursive(head->next,index-1);
}

int main(int argc, char const *argv[])
{
    Node *head = NULL;
    Push(&head, 10);
    Push(&head, 20);
    Push(&head, 30);
    Push(&head, 40);
    PrintLinkedList(head);
    cout<<GetNthNode(head,2)<<endl;
    cout<<GetNthNode(head,0)<<endl;
    cout<<GetNthNodeRecursive(head,2)<<endl;
    cout<<GetNthNodeRecursive(head,5)<<endl;
    return 0;
}