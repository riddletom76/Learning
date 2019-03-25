//https://www.geeksforgeeks.org/write-a-function-to-delete-a-linked-list/
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
//with the reference to reference
#pragma region double pointer
/*void DeleteLinkedList(Node** head){
    Node* temp = *head;
    Node* next = NULL;
    while(temp){
        next = temp->next;
        delete(temp);
        temp = next;
    }
    *head = NULL;
}

int main(int argc, char const *argv[])
{
    Node* head = NULL;
    head = PushData(head, 40);
    head = PushData(head,30);
    head = PushData(head,20);
    head = PushData(head,10);
    PrintLinkedList(head);
    DeleteLinkedList(&head);
    PrintLinkedList(head);
    return 0;
}*/
#pragma endregion

//returning the head
#pragma region 
Node* DeleteLinkedList(Node* head){
    Node* temp = head;
    Node* next = NULL;
    while(temp){
        next = temp->next;
        delete(temp);
        temp = next;
    }
    head = NULL;
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
    head = DeleteLinkedList(head);
    PrintLinkedList(head);
    return 0;
}
#pragma endregion
