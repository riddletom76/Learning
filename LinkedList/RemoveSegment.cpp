#include <bits/stdc++.h> 
using namespace std;  
  
// Node has 3 fields including x, y  
// coordinates and a pointer  
// to next node  
class Node  
{  
    public: 
    int x, y;  
    Node *next;  
};  
  
/* Function to insert a node at the beginning */
void push(Node ** head_ref, int x,int y)  
{  
    Node* new_node =new Node(); 
    new_node->x = x;  
    new_node->y = y;  
    new_node->next = (*head_ref);  
    (*head_ref) = new_node;  
}  
  
/* Utility function to print a singly linked list */
void printList(Node *head)  
{  
    Node *temp = head;  
    while (temp != NULL)  
    {  
        cout << "(" << temp->x << "," << temp->y << ")-> ";  
        temp = temp->next;  
    }  
    cout<<endl; 
  
}  
  
// Utility function to remove Next from linked list  
// and link nodes after it to head  
void deleteNode(Node *head, Node *Next)  
{  
    head->next = Next->next;  
    Next->next = NULL;  
    free(Next);  
}  

Node* DeleteMiddle(Node* head){
    Node* temp = head;
    while(temp!=NULL && temp->next->next!=NULL){
        Node* del = temp->next;
        if((temp->x == (temp->next)->x) && (temp->x == ((temp->next)->next)->x)){
            temp->next = temp->next->next;
            delete(del);
        }else if((temp->y == (temp->next)->y) && (temp->y == ((temp->next)->next)->y)){
            temp->next = temp->next->next;
            delete(del);
        }else{
            temp = temp->next;
        }
    }
    return head;
}

int main()  
{  
    Node *head = NULL;  
  
    push(&head, 40,5);  
    push(&head, 20,5);  
    push(&head, 10,5);  
    push(&head, 10,8);  
    push(&head, 10,10);  
    push(&head, 3,10);  
    push(&head, 1,10);  
    push(&head, 0,10);  
    cout << "Given Linked List: \n";  
    printList(head);  
  
    if (DeleteMiddle(head) != NULL);  
    {  
        cout << "Modified Linked List: \n";  
        printList(head);  
    }  
    return 0;  
}