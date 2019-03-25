//http://geeksquiz.com/linked-list-set-2-inserting-a-node/
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
Node* Append(Node* head, int data){
    Node* newNode = new Node();
    newNode->data = data;
    if(head == NULL){
        head = newNode;
    }else{
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}
void PrintLinkedList(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
int main(int argc, char const *argv[])
{
    Node* a = new Node();
    a->data = 10;
    Node* b = new Node();
    a->next = b;
    b->data = 20;
    Node* head = NULL;
    head = Append(head,1);
    head = a;
    head = Append(head, 30);
    PrintLinkedList(head);
    return 0;
}
