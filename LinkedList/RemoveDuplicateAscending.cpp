//my solution for - https://www.geeksforgeeks.org/remove-duplicates-from-a-sorted-linked-list/
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    bool visited;
    Node(){
        next = NULL;
        visited = false;
    }
};

void Push(Node** head, int key){
    Node* newNode = new Node();
    newNode->data = key;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
void PrintLinkedList(Node* head){
    if(head==NULL){
        cout<<"Linked list is empty"<<endl;
        return;
    }
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
//recursive solution
Node* RecursiveDuplicateRemoval(Node* head){
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        return head;
    }
    Node* temp = head->next;
    if(head->data == temp->data){
        head->next = temp->next;
        delete(temp);
        return RecursiveDuplicateRemoval(head);
    }else{
        head->next = RecursiveDuplicateRemoval(head->next);
        return head;
    }    
}

//Iteravive solution
void RemoveDuplicate(Node** head){
    Node* current = *head;
    Node* next = *head;
    current=current->next;
    while(current->next!= NULL){
        if(next->data == current->data){
            next->next = current->next;
            delete(current);
            current = next->next;
        }else{
            next = current;
            current = current->next;
        }
    }
    if(next->data == current->data){
        next->next = NULL;
        delete(current);
    }
}

int main(int argc, char const *argv[])
{
    Node* head = NULL;
    Push(&head,10);
    Push(&head,10);
    Push(&head,10);
    Push(&head,10);
    Push(&head,10);
    Push(&head,20);
    Push(&head,20);
    Push(&head,20);
    Push(&head,30);
    Push(&head,50); 
    PrintLinkedList(head);
    //RemoveDuplicate(&head);
    head = RecursiveDuplicateRemoval(head);
    PrintLinkedList(head);
    return 0;
}