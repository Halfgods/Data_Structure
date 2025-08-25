#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void add_begin(int val) {
    Node* newNode = createNode(val);
    newNode->next = head;
    head = newNode;
}

void add_end(int val) {
    Node* newNode = createNode(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

void insert_after(int key, int val) {
    Node* temp = head;
    while (temp != NULL && temp->data != key) temp = temp->next;
    if (temp == NULL) return;
    Node* newNode = createNode(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

void insert_before(int key, int val) {
    if (head == NULL) return;
    if (head->data == key) {
        add_begin(val);
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != key) temp = temp->next;
    if (temp->next == NULL) return;
    Node* newNode = createNode(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

void delete_node(int key) {
    if (head == NULL) return;
    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != key) temp = temp->next;
    if (temp->next == NULL) return;
    Node* del = temp->next;
    temp->next = del->next;
    free(del);
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int count_nodes() {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    add_begin(10);
    add_begin(20);
    add_end(30);
    add_end(40);
    insert_after(20, 25);
    insert_before(10, 15);
    display();
    printf("Count = %d\n", count_nodes());
    delete_node(25);
    display();
    printf("Count = %d\n", count_nodes());
    return 0;
}
