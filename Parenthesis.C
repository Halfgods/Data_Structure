#include <stdio.h>
#include <stdbool.h>
#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char c) {
    if (top == SIZE - 1) {
        printf("Stack Overflow\n");
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        return '\0'; // return null if empty
    }
    return stack[top--];
}

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isBalanced(char exp[]) {
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) return false; // no matching open
            char popped = pop();
            if (!isMatchingPair(popped, ch)) return false;
        }
    }
    return (top == -1); // true if stack empty
}

int main() {
    char exp[SIZE];

    printf("Enter an expression: ");
    scanf("%s", exp);  // takes input until space/newline

    if (isBalanced(exp))
        printf("Expression is Balanced\n");
    else
        printf("Expression is NOT Balanced\n");

    return 0;
}
