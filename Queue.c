#include <stdio.h>
#include <stdlib.h>
#define MAX 3

int Queue[MAX];
int FRONT =  0;
int REAR = -1;
int temp = 0;

void enqueue (int value) {
    if (REAR == MAX-1) {
        printf("Queue overflow");
    }
    ++REAR;
    Queue[REAR] = value;
    printf("The Value: %d is added at %d th index\n" ,value,REAR);
}
void dequeue() {
    if (FRONT == MAX) {
        printf("Queue Underflow\n");
    }
    printf("Popped element: %d\n", Queue[FRONT]);
    FRONT++;
}
void display(){
    if (FRONT == MAX -1){
        printf("No element available");
    }
    for (int i = FRONT; i <= REAR; i++)
    {
        printf("%d\t" , Queue[i]);
    }
    
}
void isFull(){
    if ( REAR == MAX-1) 
        printf("The Stack is Full\n");
    else
        printf("The Stack is not Full\n");
}

void isEmpty(){
    if(FRONT == MAX -1 ) {
        printf("The stack is empty");
    }
    else {
        printf("The stack is not empty");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    isFull();
    enqueue(30);
    isFull();
    dequeue();
    dequeue();
    dequeue();
    isFull();
    display();

}