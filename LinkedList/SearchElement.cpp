//My solution for: https://www.geeksforgeeks.org/search-an-element-in-a-linked-list-iterative-and-recursive/
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

bool SearchLinkedListIterave(Node* head, int key){
    while(head!=NULL){
        if(head->data == key){
            return true;
        }
        head = head->next;
    }
    return false;
}

bool SearchLinkedListRecursive(Node* head, int key){
    if(head == NULL){
        return false;
    }
    if(head->data == key){
        return true;
    }
    return SearchLinkedListRecursive(head->next, key);
}

int main()
{
    /* code */
    Node* head = NULL;
    head = PushData(head, 30);
    head = PushData(head, 20);
    head = PushData(head, 10);
    PrintLinkedList(head);
    cout<<"element 20 searched in linked list "<<SearchLinkedListIterave(head,20)<<endl;
    cout<<"element 20 searched in linked list "<<SearchLinkedListRecursive(head,20)<<endl;
    cout<<"element 40 searched in linked list "<<SearchLinkedListIterave(head,40)<<endl;
    cout<<"element 40 searched in linked list "<<SearchLinkedListRecursive(head,40)<<endl;
    return 0;
}