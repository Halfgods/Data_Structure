#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtFront(Node **head, Node **tail, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = *tail = newNode;
    }
    else
    {
        newNode->next = *head;
        *head = newNode;
    }
}

void insertAtEnd(Node **head, Node **tail, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = *tail = newNode;
    }
    else
    {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

void insertAtPosition(Node **head, Node **tail, int pos, int data)
{
    if (pos <= 1)
    {
        insertAtFront(head, tail, data);
        return;
    }
    Node *temp = *head;
    int count = 1;
    while (temp != NULL && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp == NULL || temp->next == NULL)
    {
        insertAtEnd(head, tail, data);
    }
    else
    {
        Node *newNode = createNode(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteFront(Node **head, Node **tail)
{
    if (*head == NULL)
        return;
    Node *temp = *head;
    *head = (*head)->next;
    if (*head == NULL)
        *tail = NULL;
    free(temp);
}

void deleteEnd(Node **head, Node **tail)
{
    if (*head == NULL)
        return;
    if (*head == *tail)
    {
        free(*head);
        *head = *tail = NULL;
        return;
    }
    Node *temp = *head;
    while (temp->next != *tail)
    {
        temp = temp->next;
    }
    free(*tail);
    *tail = temp;
    temp->next = NULL;
}

void deleteAtPosition(Node **head, Node **tail, int pos)
{
    if (*head == NULL)
        return;
    if (pos <= 1)
    {
        deleteFront(head, tail);
        return;
    }
    Node *temp = *head;
    int count = 1;
    while (temp->next != NULL && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
        return;
    Node *delNode = temp->next;
    temp->next = delNode->next;
    if (delNode == *tail)
        *tail = temp;
    free(delNode);
}

void Display(Node *head)
{
    while (head)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

Node *copyList(Node *head, Node **tail)
{
    if (!head)
        return NULL;
    Node *newHead = createNode(head->data);
    *tail = newHead;
    Node *currOld = head->next;
    Node *currNew = newHead;
    while (currOld)
    {
        currNew->next = createNode(currOld->data);
        currNew = currNew->next;
        *tail = currNew;
        currOld = currOld->next;
    }
    return newHead;
}
int main()
{
    Node *head = NULL, *tail = NULL;
    insertAtEnd(&head, &tail, 10);
    insertAtFront(&head, &tail, 5);
    insertAtPosition(&head, &tail, 2, 7);
    Display(head);
    deleteFront(&head, &tail);
    Display(head);
    deleteEnd(&head, &tail);
    Display(head);
    deleteAtPosition(&head, &tail, 1);
    Display(head);
    return 0;
}
