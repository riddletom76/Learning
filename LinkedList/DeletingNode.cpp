//http://geeksquiz.com/linked-list-set-3-deleting-node/
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
Node* DeleteNode(Node* head, int key){
    if(head!=NULL){
        Node* temp = head;
        Node* prevNode = NULL;
        while(temp!=NULL){
            if(temp->data == key){
                if(prevNode == NULL){
                    prevNode = temp;
                    head = temp->next;
                    delete(prevNode);
                    break;
                }
                prevNode->next = temp->next;
                prevNode = temp;
                delete(prevNode);
                break;
            }
            prevNode = temp;
            temp = temp->next;
        }
    }
    return head;
}
void PrintLinkedList(Node* head){
    if(head == NULL){
        cout<<"the linked list is empty"<<endl;
    }else{
        while(head!=NULL){
            cout<<head->data<<" ";
            head = head->next;
        }
        cout<<endl;
    }
}
int main(int argc, char const *argv[])
{
    Node *a = new Node();
    Node *b = new Node();
    a->data = 10;
    a->next = b;
    b->data = 20;
    Node *c = new Node();
    c->data = 30;
    b->next = c;
    Node* head = a;
    PrintLinkedList(head);
    head = DeleteNode(head,20);
    PrintLinkedList(head);
    head = DeleteNode(head,10);
    PrintLinkedList(head);
    head = DeleteNode(head,30);
    PrintLinkedList(head);
    return 0;
}
