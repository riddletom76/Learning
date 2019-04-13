//my solution for - https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/
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

//unoptimized solution - noob solution
void IntersectionPoint(Node *first, Node *second)
{
    bool found = false;
    Node *head1 = first;
    Node *head2 = second;
    if (head1 != NULL && head2 != NULL)
    {
        while (head1 != NULL && (found == false))
        {
            head2 = second;
            while (head2 != NULL && (found == false))
            {
                if (head1 == head2)
                {
                    cout << "intersection point of the two linked list is " << head1->data << endl;
                    found = true;
                }
                head2 = head2->next;
            }
            head1 = head1->next;
        }
    }
}

int LengthOfLinkedList(Node* head){
    int count=0;
    while(head!=NULL){
        count++;
        head = head->next;
    }
    return count;
}

//alternative solution
void IntersectionPointNew(Node *head1, Node *head2)
{
    int lenFirst = LengthOfLinkedList(head1);
    int lenSecond = LengthOfLinkedList(head2);
    Node* first = NULL;
    Node* second = NULL;
    if(lenFirst < lenSecond){
        first = head2;
        second = head1;
    }else{
        first = head1;
        second = head2;
    }
    int count = abs(lenFirst - lenSecond);
    int pos = 0;
    while(pos<count){
        first = first->next;
        pos++;
    }
    while(first!=NULL){
        if(first == second){
            cout<<"intersection point is "<<first->data<<endl;
            break;
        }
        first = first->next;
        second = second->next;
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
    head2 = head1->next->next->next;
    cout << "first linked list " << endl;
    PrintLinkedList(head1);
    cout << "second linked list " << endl;
    PrintLinkedList(head2);
    IntersectionPointNew(head1, head2);
    return 0;
}