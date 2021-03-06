//my solution for - https://www.geeksforgeeks.org/intersection-of-two-sorted-linked-lists/
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

//worst implementation - noob implementation
// Node *InterSection(Node *head1, Node *head2)
// {
//     Node *temp = NULL;
//     Node *first = head1;
//     Node *second = head2;
//     if (first != NULL && second != NULL)
//     {
//         while (first != NULL)
//         {
//             second = head2;
//             while (second != NULL)
//             {
//                 if (second->data == first->data)
//                 {
//                     Push(&temp, second->data);
//                     break;
//                 }
//                 second = second->next;
//             }
//             first = first->next;
//         }
//     }
//     return temp;
// }

//alternate implementation
Node *InterSection(Node *head1, Node *head2)
{
    Node *dummyNode = NULL;
    Node *first = head1;
    Node *second = head2;
    if (first != NULL && second != NULL)
    {
        while (first != NULL && second != NULL)
        {
            if (first->data == second->data)
            {
                Push(&dummyNode, first->data);
                first = first->next;
                second = second->next;
                continue;
            }
            if (first->data < second->data)
            {
                first = first->next;
            }
            else
            {
                second = second->next;
            }
        }
    }
    return dummyNode;
}

//recursion
Node *InterSectionRecursive(Node *head1, Node *head2)
{
    if (head1 == NULL || head2 == NULL)
    {
        return NULL;
    }
    if (head1->data < head2->data)
    {
        return InterSectionRecursive(head1->next, head2);
    }
    else if (head1->data > head2->data)
    {
        return InterSectionRecursive(head1, head2->next);
    }
    else
    {
        Node *temp = new Node();
        temp->data = head1->data;
        head1 = head1->next;
        head2 = head2->next;
        temp->next = InterSectionRecursive(head1, head2);
        return temp;
    }
}

int main(int argc, char const *argv[])
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    Push(&head1, 1);
    Push(&head1, 2);
    Push(&head1, 3);
    Push(&head1, 4);
    Push(&head1, 6);
    Push(&head2, 2);
    Push(&head2, 4);
    Push(&head2, 6);
    Push(&head2, 8);
    cout << "first linked list " << endl;
    PrintLinkedList(head1);
    cout << "second linked list " << endl;
    PrintLinkedList(head2);
    Node *head3 = InterSectionRecursive(head1, head2); //InterSection(head1, head2);
    cout << "intersection of first and second linked list is " << endl;
    PrintLinkedList(head3);
    return 0;
}