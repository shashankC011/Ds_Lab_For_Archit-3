#include<stdio.h>
#include <stdlib.h>
#include <ctype.h>   //provides the isalpha function(which tells if the passed parameter is an alphabet or not
#define MAX 100

typedef struct{
    int top;
    char items[MAX];
}Stack;


void initStack(Stack *s){
    s->top = -1;
}

int isEmpty(Stack *s){
    return s->top == -1;
}

int isFull(Stack *s){
    return s->top == MAX-1;
}

void push(Stack *s,char item){
    if(isFull(s)){
      printf("Stack is full/n");
    }
    else{
        s->items[++(s->top)] = item;
    }
}

char pop(Stack *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return '\0';
    }
    else{
        return s->items[(s->top)--];
    }
}

char peek(Stack *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return '/0';
    }
    else{
        return s->items[(s->top)];
    }
}

int precedence(char op){
    if(op == '+' ||  op == '-'){
        return 1;
    }
    else if(op == '*' || op == '/'){
        return 2;
    }
    else{
        return 0;
    }
}

void infixToPostfix(const char *expression, char *postfix){
    Stack s;
    initStack(&s);
    int i = 0, k = 0;
    while(expression[i] != '\0'){
        char ch = expression[i];
        if(isalpha(ch)){
            postfix[k++] = ch;
        }
        else if(ch == '('){
            push(&s,ch);
        }
        else if(ch == ')'){
            while(!isEmpty(&s) && peek(&s) != '('){
                postfix[k++]= pop(&s);
            }
            if(!isEmpty(&s)&&peek(&s)=='('){
                pop(&s);
           }
        }
        else{
            while(!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch)){
                postfix[k++] = pop(&s);//precendence of top of stack is more than ch so pop to postfix till operand with lower precendence is encountered
            }
            push(&s, ch);  //if precedence of top of stack is less than ch then push ch to the stack
        }
        i++;
    }

    // Pop all remaining operators in the stack
    while (!isEmpty(&s)) {
        postfix[k++] = pop(&s);
    }
    postfix[k] = '\0';  // Null-terminate the postfix expression
}

int main(){
    char infix[MAX];
    char postfix[MAX];

    printf("Enter the infix expression: ");
    fgets(infix,sizeof(infix),stdin);

        int len = strlen(infix);
    if (infix[len - 1] == '\n') {
        infix[len - 1] = '\0';
    }
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}

