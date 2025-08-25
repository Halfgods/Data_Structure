#include <stdio.h>
#define SIZE 10

int stack1[SIZE], stack2[SIZE];
int top1 = -1, top2 = -1;

void push1(int x) { stack1[++top1] = x; }
int pop1() { return stack1[top1--]; }

void push2(int x) { stack2[++top2] = x; }
int pop2() { return stack2[top2--]; }

int isEmpty1() { return top1 == -1; }
int isEmpty2() { return top2 == -1; }

void enqueue(int x) {
    push1(x);
}

void dequeue() {
    if (isEmpty1() && isEmpty2()) {
        printf("Queue is EMPTY\n");
        return;
    }
    if (isEmpty2()) {
        while (!isEmpty1())
            push2(pop1());
    }
    printf("%d dequeued\n", pop2());
}

void display() {
    if (isEmpty1() && isEmpty2()) {
        printf("Queue is EMPTY\n");
        return;
    }
    if (isEmpty2()) {
        while (!isEmpty1())
            push2(pop1());
    }
    for (int i = top2; i >= 0; i--)
        printf("%d ", stack2[i]);
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    enqueue(40);
    enqueue(50);
    display();
    return 0;
}
