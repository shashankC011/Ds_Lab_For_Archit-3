#include<stdio.h>
#include<string.h>
#define max 100
int top=-1;
char arr[max][max];
void push(char* elem)
{
    if(top==max-1)
    {
        printf("Stack overflow\n");
    }
    else
        strcpy(arr[++top],elem);
}
void pop(char* result)
{
    if(top>=0){
        strcpy(result,arr[top]);
        top--;
    }
    else{
        printf("Underflow\n");
        result[0]='\0';
    }
}
void postToInfix(char* post,char* output)
{
    char operand1[max],operand2[max],operand[2],expression[max];
    int len=strlen(post);
    int i;
    for(i=0;i<len;i++)
    {
        if ((post[i] >= '0' && post[i] <= '9') || (post[i] >= 'a' && post[i] <= 'z') || (post[i] >= 'A' && post[i] <= 'Z'))
          {
              operand[0]=post[i];
              operand[1]='\0';
              push(operand);
          }
          else{
            pop(operand1);
            pop(operand2);
            snprintf(expression,sizeof(expression),"(%s%c%s)",operand2,post[i],operand1);
            push(expression);
          }
    }
    strcpy(output,arr[top]);
}
int main()
{
    char inp[max];
    char result[max];
    printf("Enter the postfix expression:-\n");
    scanf("%s",inp);
    postToInfix(inp,result);
    printf("Infix expression: %s\n",result);
}