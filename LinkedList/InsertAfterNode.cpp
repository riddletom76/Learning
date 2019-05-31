//My solution for: http://geeksquiz.com/linked-list-set-2-inserting-a-node/
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
void PrintLinkedList(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
void InsertAfter(Node* prevNode, int data){
    Node *newNode = new Node();
    newNode->data = data;
    if(prevNode == NULL){
        prevNode = newNode;
        return;
    }
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}
int main(int argc, char const *argv[])
{
    /* code */
    Node* a = new Node();
    a->data = 10;
    Node* b = new Node();
    a->next = b;
    b->data = 30;
    Node* c = new Node();
    b->next = c;
    c->data = 50;
    Node* head = NULL;
    head = a;
    PrintLinkedList(head);
    InsertAfter(a,20);
    cout<<"inserted 20"<<endl;
    PrintLinkedList(head);
    InsertAfter(b,40);
    cout<<"inserted 40"<<endl;
    PrintLinkedList(head);
    InsertAfter(c,60);
    cout<<"inserted 60"<<endl;
    PrintLinkedList(head);
    return 0;
}