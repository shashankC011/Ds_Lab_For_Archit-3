#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct {
    int top;
    int items[MAX];
} Stack;

// Initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Push an item onto the stack
void push(Stack *s, int item) {
    if (isFull(s)) {
        printf("Stack is full\n");
    } else {
        s->items[++(s->top)] = item;
    }
}

// Pop an item from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1; // Return -1 to indicate an error
    } else {
        return s->items[(s->top)--];
    }
}

// Peek at the top item of the stack
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1; // Return -1 to indicate an error
    } else {
        return s->items[s->top];
    }
}

// Check if a character is a digit
int isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

// Evaluate a postfix expression
int evaluatePostfix(char *expression) {
    Stack s;
    initStack(&s);
    int i = 0;

    while (expression[i] != '\0') {
        char ch = expression[i];

        if (isDigit(ch)) {
            int num = 0;
            // Parse the entire number
            while (isDigit(ch)) {
                num = num * 10 + (ch - '0');
                i++;
                ch = expression[i];
            }
            push(&s, num);
        } else if (ch == ' ') {
            // Skip spaces
            i++;
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if (isEmpty(&s)) {
                printf("Invalid postfix expression\n");
                return -1;
            }
            int operand2 = pop(&s);
            if (isEmpty(&s)) {
                printf("Invalid postfix expression\n");
                return -1;
            }
            int operand1 = pop(&s);
            int result;

            switch (ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Cannot divide by 0\n");
                        return -1;
                    }
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Unknown operator: %c\n", ch);
                    return -1;
            }

            push(&s, result);
            i++;
        } else {
            printf("Invalid character in expression: %c\n", ch);
            return -1;
        }
    }

    if (!isEmpty(&s)) {
        return pop(&s);
    } else {
        printf("Invalid postfix expression\n");
        return -1;
    }
}

int main() {
    char postfix[MAX];

    printf("Enter the postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);

    // Remove the newline character if present
    int len = strlen(postfix);
    if (postfix[len - 1] == '\n') {
        postfix[len - 1] = '\0';
    }

    int result = evaluatePostfix(postfix);
    if (result != -1) {
        printf("Result of postfix expression: %d\n", result);
    }

    return 0;
}
