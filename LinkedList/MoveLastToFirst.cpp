//my solution for - https://www.geeksforgeeks.org/move-last-element-to-front-of-a-given-linked-list/
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

void LastToFirst(Node** head){
    Node* temp = *head;
    Node* prev = NULL;
    while(temp->next!=NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    temp->next = *head;
    *head = temp;
}

int main(int argc, char const *argv[])
{
    Node *head = NULL;
    Push(&head, 10);
    Push(&head, 20);
    Push(&head, 30);
    Push(&head, 40);
    Push(&head, 50);
    Push(&head, 60);
    PrintLinkedList(head);
    LastToFirst(&head);
    PrintLinkedList(head);
    return 0;
}