#include <stdio.h>
#define SIZE 5   

int queue[SIZE];
int front = -1, rear = -1;


int isEmpty() {
    return (front == -1);
}


int isFull() {
    return ((rear + 1) % SIZE == front);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is FULL! Cannot enqueue %d\n", value);
        return;
    }
    if (front == -1) 
        front = 0;
    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    printf("%d enqueued\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is EMPTY! Cannot dequeue\n");
        return;
    }
    printf("%d dequeued\n", queue[front]);
    if (front == rear) { 
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is EMPTY!\n");
        return;
    }
    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50); 
    display();

    dequeue();
    dequeue();
    display();

    enqueue(60);
    enqueue(70);
    display();

    return 0;
}
