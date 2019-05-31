//my solution for - https://www.geeksforgeeks.org/swap-nodes-in-a-linked-list-without-swapping-data/
#include <iostream>
using namespace std;

class Node
{
  public:
    int data;
    Node *next;
    bool visited;
    Node()
    {
        next = NULL;
        visited = false;
    }
};

void Push(Node **head, int key)
{
    Node *newNode = new Node();
    newNode->data = key;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void PrintLinkedList(Node *head)
{
    if (head == NULL)
    {
        cout << "Linked list is empty" << endl;
        return;
    }
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void SwapKeys(Node **head, int a, int b)
{
    Node* temp = *head;
    Node* prev = NULL;
    Node* first = NULL;
    Node* prevFirst = NULL;
    while(temp!=NULL){
        if(temp->data == a){
            prevFirst = prev;
            first = temp;
            break;
        }else{
            prev = temp;
            temp = temp->next;
        }
    }
    temp = *head;
    prev = NULL;
    Node* second = NULL;
    Node* prevSecond = NULL;
    while(temp!=NULL){
        if(temp->data == b){
            prevSecond = prev;
            second = temp;
            break;
        }else{
            prev = temp;
            temp = temp->next;
        }
    }
    if((first == NULL) || (second==NULL)){
        return;
    }
    if(prevFirst == NULL){
        *head = second;
    }else{
        prevFirst->next = second;
    }
    if(prevSecond == NULL){
        *head = first;
    }else{
        prevSecond->next = first;
    }
    temp = first->next;
    first->next = second->next;
    second->next = temp;
}

int main(int argc, char const *argv[])
{
    Node *head = NULL;
    Push(&head, 10);
    Push(&head, 30);
    Push(&head, 20);
    Push(&head, 50);
    Push(&head, 80);
    Push(&head, 70);
    PrintLinkedList(head);
    SwapKeys(&head,10,70);
    PrintLinkedList(head);
    return 0;
}