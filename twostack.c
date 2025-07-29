#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct TwoStacks {
    int arr[MAX];
    int top1;
    int top2;
} TwoStacks;

void init(TwoStacks *ts) {
    ts->top1 = -1;
    ts->top2 = MAX;
}

void push(TwoStacks *ts, int x, int stack_number) {
    if (ts->top1 + 1 == ts->top2) {
        printf("stack overflow!\n");
        return;
    }

    if (stack_number == 1) {
        ts->arr[++ts->top1] = x;
    } else if (stack_number == 2) {
        ts->arr[--ts->top2] = x;
    } else {
        printf("Invalid stack number!\n");
    }
}


int pop(TwoStacks *ts, int stack_number) {
    if (stack_number == 1) {
        if (ts->top1 == -1) {
            printf("Stack-1 Underflow!\n");
            return -1;
        }
        return ts->arr[ts->top1--];
    } else if (stack_number == 2) {
        if (ts->top2 == MAX) {
            printf("Stack-2 Underflow!\n");
            return -1;
        }
        return ts->arr[ts->top2++];
    }
}

int main() {
    TwoStacks ts;
    init(&ts);

    int choice, stack_num, value;

    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stack number (1 or 2): ");
                scanf("%d", &stack_num);
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&ts, value, stack_num);
                break;

            case 2:
                printf("Enter stack number (1 or 2): ");
                scanf("%d", &stack_num);
                value = pop(&ts, stack_num);
                if (value != -1)
                    printf("Popped value: %d\n", value);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid Try again.\n");
        }
    }

    return 0;
}
