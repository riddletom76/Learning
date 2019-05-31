//my solution for - https://www.geeksforgeeks.org/remove-duplicates-from-an-unsorted-linked-list/
#include <iostream>
#include <set>
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
//with ttwo loops and co,mplexity O(N^2)
void RemoveDuplicate(Node** head){
    Node* temp = *head;
    while(temp!=NULL){
        Node* temp2 = temp->next;
        Node* prev = temp;
        while(temp2!=NULL){
            if(temp->data == temp2->data){
                prev->next = temp2->next;
                delete(temp2);
                temp2 = prev->next;
            }else{
                prev = temp2;
                temp2 = temp2->next;
            }
        }
        temp = temp->next;
    }
}
//alternate solution - with a set
void RemoveDuplicateUnordered(Node** head){
    Node* temp = *head;
    Node* prev = *head;
    temp = temp->next;
    set<int> x;
    x.insert(prev->data);
    while(temp!=NULL){
        if(x.find(temp->data)!=x.end()){
            prev->next = temp->next;
            delete(temp);
            temp = prev->next;
        }else{
            prev = temp;
            x.insert(prev->data);
            temp = temp->next;
        }
    }
}

int main(int argc, char const *argv[])
{
    Node* head = NULL;
    Push(&head,10);
    Push(&head,30);
    Push(&head,10);
    Push(&head,10);
    Push(&head,20);
    Push(&head,10);
    Push(&head,10);
    Push(&head,20);
    Push(&head,50);
    Push(&head,20);     
    PrintLinkedList(head);
    //RemoveDuplicate(&head);
    RemoveDuplicateUnordered(&head);
    PrintLinkedList(head);
    return 0;
}