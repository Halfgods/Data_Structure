#include <stdio.h>
#define SIZE 5

int deque[SIZE];
int front = -1, rear = -1;

int isFull() {
    return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
}

int isEmpty() {
    return (front == -1);
}

void insert_front(int x) {
    if (isFull()) {
        printf("Deque is FULL\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = SIZE - 1;
    } else {
        front--;
    }
    deque[front] = x;
}

void insert_rear(int x) {
    if (isFull()) {
        printf("Deque is FULL\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else if (rear == SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }
    deque[rear] = x;
}

void remove_front() {
    if (isEmpty()) {
        printf("Deque is EMPTY\n");
        return;
    }
    printf("%d removed\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    } else if (front == SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
}

void remove_rear() {
    if (isEmpty()) {
        printf("Deque is EMPTY\n");
        return;
    }
    printf("%d removed\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = SIZE - 1;
    } else {
        rear--;
    }
}

void display() {
    if (isEmpty()) {
        printf("Deque is EMPTY\n");
        return;
    }
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n1.Insert Front 2.Insert Rear \n3.Remove Front 4.Remove Rear \n5.Display 6.IsFull \n7.IsEmpty 8.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: scanf("%d", &val); insert_front(val); break;
            case 2: scanf("%d", &val); insert_rear(val); break;
            case 3: remove_front(); break;
            case 4: remove_rear(); break;
            case 5: display(); break;
            case 6: if (isFull()) printf("Deque is FULL\n"); else printf("Deque is NOT FULL\n"); break;
            case 7: if (isEmpty()) printf("Deque is EMPTY\n"); else printf("Deque is NOT EMPTY\n"); break;
            case 8: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
