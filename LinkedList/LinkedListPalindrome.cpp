//My solution for: https://www.geeksforgeeks.org/function-to-check-if-a-singly-linked-list-is-palindrome/
#include <iostream>
#include <stack>
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
void RemoveNode(Node** head, int key){
    Node* temp = *head;
    Node* prev = NULL;
    while(temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    delete(temp);
}
bool CheckPalindrome(Node* head){
    stack<int> st;
    Node* temp = head;
    while(temp!=NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    Node* temp2 = head;
    while(temp2!=NULL){
        int x = st.top();
        st.pop();
        if(temp2->data != x){
            return false;
        }
        temp2 = temp2->next;
    }
    return true;
}
int main(int argc, char const *argv[])
{
    Node* head = NULL;
    Push(&head,10);
    Push(&head,20);
    Push(&head,30);
    Push(&head,20);
    Push(&head,10);
    PrintLinkedList(head);
    cout<<CheckPalindrome(head)<<endl;
    RemoveNode(&head,30);
    PrintLinkedList(head);
    cout<<CheckPalindrome(head);
    return 0;
}