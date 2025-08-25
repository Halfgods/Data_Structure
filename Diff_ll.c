#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head1 = NULL;
Node* head2 = NULL;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void add_end(Node** head, int val) {
    Node* newNode = createNode(val);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Node* copy(Node* head) {
    if (head == NULL) return NULL;
    Node* newHead = createNode(head->data);
    Node* temp1 = head->next;
    Node* temp2 = newHead;
    while (temp1 != NULL) {
        temp2->next = createNode(temp1->data);
        temp2 = temp2->next;
        temp1 = temp1->next;
    }
    return newHead;
}

Node* concatenate(Node* h1, Node* h2) {
    if (h1 == NULL) return h2;
    Node* temp = h1;
    while (temp->next != NULL) temp = temp->next;
    temp->next = h2;
    return h1;
}

void split(Node* head, Node** first, Node** second, int pos) {
    if (head == NULL) return;
    *first = head;
    Node* temp = head;
    for (int i = 1; i < pos && temp->next != NULL; i++) temp = temp->next;
    *second = temp->next;
    temp->next = NULL;
}

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int count(Node* head) {
    int c = 0;
    while (head != NULL) {
        c++;
        head = head->next;
    }
    return c;
}

int main() {
    add_end(&head1, 10);
    add_end(&head1, 20);
    add_end(&head1, 30);
    add_end(&head1, 40);
    add_end(&head2, 50);
    add_end(&head2, 60);

    printf("List1: "); display(head1);
    printf("List2: "); display(head2);

    Node* copied = copy(head1);
    printf("Copied List: "); display(copied);

    Node* concat = concatenate(copy(head1), copy(head2));
    printf("Concatenated: "); display(concat);

    Node* f = NULL; Node* s = NULL;
    split(head1, &f, &s, 2);
    printf("Split First: "); display(f);
    printf("Split Second: "); display(s);

    Node* rev = reverse(head2);
    printf("Reversed List2: "); display(rev);

    printf("Count List1 = %d\n", count(head1));
    return 0;
}
