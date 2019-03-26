//My solution for: https://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list/
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

int GetNthFromEnd(Node* head,int index){
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    int pos = count-index;
    int c = 0;
    while(c<pos){
        head = head->next;
        c++;
    }
    return head->data;
}
//alternate solution
int GetNthFromEndTwoPtr(Node* head, int index){
    Node* main = head;
    Node* track = head;
    int count = 0;
    while(count<index){
        track = track->next;
        count++;
    }
    while(track!=NULL){
        main = main->next;
        track = track->next;
    }
    return main->data;
}

int main(int argc, char const *argv[])
{
    Node *head = NULL;
    Push(&head, 10);
    Push(&head, 20);
    Push(&head, 30);
    Push(&head, 40);
    Push(&head, 50);
    PrintLinkedList(head);
    cout<<GetNthFromEnd(head,2)<<endl;
    cout<<GetNthFromEndTwoPtr(head,2)<<endl;
    return 0;
}