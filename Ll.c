#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtFront(Node **head, Node **tail, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) *head = *tail = newNode;
    else { newNode->next = *head; *head = newNode; }
}

void insertAtEnd(Node **head, Node **tail, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) *head = *tail = newNode;
    else { (*tail)->next = newNode; *tail = newNode; }
}

void deleteFront(Node **head, Node **tail) {
    if (*head == NULL) return;
    Node* temp = *head;
    *head = (*head)->next;
    if (*head == NULL) *tail = NULL;
    free(temp);
}

void deleteEnd(Node **head, Node **tail) {
    if (*head == NULL) return;
    if (*head == *tail) { free(*head); *head = *tail = NULL; return; }
    Node* temp = *head;
    while (temp->next != *tail) temp = temp->next;
    free(*tail);
    *tail = temp;
    temp->next = NULL;
}

void printList(Node *head) {
    while (head) { printf("%d -> ", head->data); head = head->next; }
    printf("NULL\n");
}

Node* copyList(Node *head, Node **tail) {
    if (!head) return NULL;
    Node *newHead = createNode(head->data);
    *tail = newHead;
    Node *currOld = head->next, *currNew = newHead;
    while (currOld) {
        currNew->next = createNode(currOld->data);
        currNew = currNew->next;
        *tail = currNew;
        currOld = currOld->next;
    }
    return newHead;
}

Node* concatenate(Node* head1, Node** tail1, Node* head2, Node* tail2) {
    if (!head1) { *tail1 = tail2; return head2; }
    (*tail1)->next = head2;
    if (tail2) *tail1 = tail2;
    return head1;
}

Node* reverseList(Node* head, Node** tail) {
    Node *prev = NULL, *curr = head, *next = NULL;
    *tail = head;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main() {
    Node *head = NULL, *tail = NULL;
    int choice, value;
    
    while (1) {
        printf("\n1. Insert at Front\n2. Insert at End\n3. Delete Front\n4. Delete End\n5. Display\n6. Copy List\n7. Reverse List\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter value: "); scanf("%d", &value);
                insertAtFront(&head, &tail, value);
                break;
            case 2:
                printf("Enter value: "); scanf("%d", &value);
                insertAtEnd(&head, &tail, value);
                break;
            case 3:
                deleteFront(&head, &tail);
                break;
            case 4:
                deleteEnd(&head, &tail);
                break;
            case 5:
                printList(head);
                break;
            case 6: {
                Node *copyTail = NULL;
                Node *copyHead = copyList(head, &copyTail);
                printList(copyHead);
                break;
            }
            case 7:
                head = reverseList(head, &tail);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
