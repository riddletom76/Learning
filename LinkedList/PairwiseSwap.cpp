//my solution for - https://www.geeksforgeeks.org/pairwise-swap-elements-of-a-given-linked-list/
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

void PairwiseSwap(Node **head)
{
    Node *temp = *head;
    while (temp != NULL && temp->next != NULL)
    {
        int tem = temp->next->data;
        temp->next->data = temp->data;
        temp->data = tem;
        temp = temp->next->next;
    }
}

//alternate solution - recursive
void PairwiseSwapRecursive(Node **head)
{
    if (*head != NULL && (*head)->next != NULL)
    {
        int temp = (*head)->data;
        (*head)->data = ((*head)->next)->data;
        ((*head)->next)->data = temp;
        PairwiseSwapRecursive(&(*head)->next->next);
    }
}

int main(int argc, char const *argv[])
{
    Node *head = NULL;
    Push(&head, 20);
    Push(&head, 10);
    Push(&head, 40);
    Push(&head, 30);
    Push(&head, 60);
    Push(&head, 50);
    PrintLinkedList(head);
    PairwiseSwap(&head);
    PairwiseSwapRecursive(&head);
    PrintLinkedList(head);
    return 0;
}