//https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/
#include<bits/stdc++.h>
class Node{
    public:
    int data;
    Node *next;
    Node(){
        next = NULL;
    }
};
Node* InsertFront(Node* head, Node* newNode){
    if(head==NULL){
        return newNode;
    }
    newNode->next = head;
    head = newNode;
    return head;
}
void PrintLinkedList(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
int main(){
    Node* linkedList = NULL;
    Node* node1 = new Node();
    Node* node2 = new Node();
    Node* node3 = new Node();
    node1->data = 10;
    node2->data = 20;
    node1->next = node2;
    node3->data = 30;
    node2->next = node3;
    linkedList = node1;
    Node *newNode = new Node();
    newNode->data = 9;
    linkedList = InsertFront(linkedList,newNode);
    PrintLinkedList(linkedList);
    return 0;
}