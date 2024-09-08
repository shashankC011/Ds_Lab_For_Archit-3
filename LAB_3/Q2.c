#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct{
    char items[MAX];
    int top;
}Stack;

void initStack(Stack* s){
    s->top = -1;
}

int isEmpty(Stack* s){
    return s->top == -1;
}

void push(Stack* s,char item){
    if(s->top == MAX-1){
        printf("Stack overflow \n");
        return;
    }
    s->items[++(s->top)] = item;
}

char pop(Stack *s){
    if(isEmpty(s)){
        printf("Stack underflow");
        return '\0';
    }
    return s->items[(s->top)--];
}

void decimalToBase(int decimal,int base){
    Stack stack;
    initStack(&stack);

    if(base < 2 || base >36){
        printf("Base should be between 2 and 36");
        return;
    }


    if(decimal == 0){
        printf("0\n");
        return;
    }

    while(decimal > 0){
        int remainder = decimal % base;
        char digit;
        if(remainder<10){
            digit = '0' + remainder; //ascii value of '0' is 48 and '1' is 49, so this works as '0' + remainder(for ex: 2) gives '3'
        }
        else{
            digit = 'A' + (remainder - 10);
        }
        push(&stack,digit);
        decimal /= base;
    }


    //pop and print:
    while(!isEmpty(&stack)){
        printf("%c",pop(&stack));
    }
    printf("\n");
}

int main(){
    int decimal,base;
    printf("Enter decimal and base(2 to 36): ");
    scanf("%d %d",&decimal,&base);
    printf("The number in the base %d is: ",base);
    decimalToBase(decimal,base);
    return 0;
}
