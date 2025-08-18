#include <stdio.h>
#define SIZE 5

typedef struct {
    int arr[SIZE];
    int front;
    int rear;
} DQueue;

void init(DQueue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(DQueue *q) {
    return ((q->front == 0 && q->rear == SIZE - 1) || (q->front == q->rear + 1));
}

int isEmpty(DQueue *q) {
    return (q->front == -1);
}

void insertFront(DQueue *q, int ele) {
    if (isFull(q)) {
        printf("Overflow\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else if (q->front == 0)
        q->front = SIZE - 1;
    else
        q->front--;
    q->arr[q->front] = ele;
}

void insertRear(DQueue *q, int ele) {
    if (isFull(q)) {
        printf("Overflow\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else if (q->rear == SIZE - 1)
        q->rear = 0;
    else
        q->rear++;
    q->arr[q->rear] = ele;
}

void deleteFront(DQueue *q) {
    if (isEmpty(q)) {
        printf("Underflow\n");
        return;
    }
    int val = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else if (q->front == SIZE - 1)
        q->front = 0;
    else
        q->front++;
    printf("Deleted %d\n", val);
}

void deleteRear(DQueue *q) {
    if (isEmpty(q)) {
        printf("Underflow\n");
        return;
    }
    int val = q->arr[q->rear];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else if (q->rear == 0)
        q->rear = SIZE - 1;
    else
        q->rear--;
    printf("Deleted %d\n", val);
}

void display(DQueue *q) {
    if (isEmpty(q)) {
        printf("Empty\n");
        return;
    }
    int i = q->front;
    while (1) {
        printf("%d ", q->arr[i]);
        if (i == q->rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    DQueue q;
    init(&q);
    insertRear(&q, 10);
    insertRear(&q, 20);
    insertFront(&q, 5);
    display(&q);
    deleteFront(&q);
    display(&q);
    deleteRear(&q);
    display(&q);
    return 0;
}
