#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100


typedef struct {  //typedef so you dont have to write "struct"Stack everytime you initialize a stack variable
    char items[MAX];
    int top;
}Stack;


//initialization
void initStack(Stack* s){
    s->top = -1;
}

int isEmpty(Stack* s){
    return s->top == -1;
}

void push(Stack* s,char item){
    if(s->top == MAX-1){
        printf("Stack overflow\n");
        return;
    }
    else{
        s->items[++(s->top)] = item;
    }
}

char pop(Stack* s){
    if(isEmpty(s)){
        printf("Stack underflow\n");
        return '\0';
    }
    return s->items[(s->top)--];
}

int isPalim(char* str){
    int i;
    Stack stack;
    initStack(&stack);
    int len = strlen(str);

    for(i = 0; i<len;i++){
        push(&stack,str[i]);  //populate the stack with the string

    }

    for(i = 0;i<len/2;i++){
        if(pop(&stack)!= str[i]){
                return 0;
        }
    }
    return 1;
}

int main(){
    char str[MAX];

    printf("Enter a string: ");
    fgets(str,MAX,stdin);
    str[strcspn(str,"\n")] = '\0'; // to remove the newline character which is caused due to fgets, using strcspn
                                   //which gives the length of the string from *str(first element) to where it encounters \n,and we make that element \0
    if(isPalim(str)){
        printf("The given string is a palindrome \n");
    }
    else{
        printf("The given string is not a palindrome \n");
    }
}

