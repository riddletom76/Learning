//https://www.geeksforgeeks.org/delete-a-linked-list-node-at-a-given-position/
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
    return newNode;
}

void PrintLinkedList(Node* head){
    if(head == NULL){
        cout<<"Linked list is empty"<<endl;
    }else{
        while(head!=NULL){
            cout<<head->data<<" ";
            head = head->next;
        }
        cout<<endl;
    }
}

Node* DeleteAtPos(Node* head, int pos){
    if(pos == 0){
        Node* temp = head;
        head = temp->next;
        delete(temp);
    }else{
        Node* temp = head;
        Node* prevNode = NULL;
        int internalPos = 0;
        while(temp!=NULL && internalPos<pos){
            prevNode = temp;
            temp = temp->next;
            internalPos++;
        }
        prevNode->next = temp->next;
        delete(temp);
    }
    return head;
}

int main(int argc, char const *argv[])
{
    Node* head = NULL;
    head = PushData(head, 40);
    head = PushData(head,30);
    head = PushData(head,20);
    head = PushData(head,10);
    PrintLinkedList(head);
    head = DeleteAtPos(head,0);
    PrintLinkedList(head);
    head = DeleteAtPos(head,2);
    PrintLinkedList(head);
    return 0;
}
