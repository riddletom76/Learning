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

void RemoveDuplicate(Node** head){
    Node* temp = *head;
    Node* curr = temp;
    Node* prev = NULL;
    while(temp->next!=NULL){
        prev = curr;
        curr = temp->next;
        while((curr->data == prev->data) && (curr->next!=NULL)){
            Node* temp1 = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete(temp1);
        }
        if(prev->data == curr->data){
            prev->next = NULL;
            delete(curr);
            break;
        }
        temp = temp->next;
    }
}

int main(int argc, char const *argv[])
{
    Node* head = NULL;
    Push(&head,10);
    Push(&head,10);
    Push(&head,20);
    Push(&head,20);
    Push(&head,20);
    Push(&head,30);
    Push(&head,40); 
    PrintLinkedList(head);
    RemoveDuplicate(&head);
    PrintLinkedList(head);
    return 0;
}