//https://www.geeksforgeeks.org/search-an-element-in-a-linked-list-iterative-and-recursive/
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
//head->next = newNode;
return newNode;
}

void PrintLinkedList(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main()
{
    /* code */
    Node* head = NULL;
    head = PushData(head, 30);
    head = PushData(head, 20);
    head = PushData(head, 10);
    PrintLinkedList(head);
    cout<<"element 20 searched in linked list "<<SearchLinkedListIterave(head,20);
    cout<<"element 20 searched in linked list "<<SearchLinkedListRecursive(head,20);
    return 0;
}