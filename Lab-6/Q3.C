#include<stdio.h>
#include<string.h>
#define max 100
int top=-1;
char arr[max][max];
char pre[max],stack[max];
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
void postToInfix(char* output)
{
    char operand1[max],operand2[max],operand[2],expression[max];
    int len=strlen(stack);
    int i;
    for(i=0;i<len;i++)
    {
        if ((stack[i] >= '0' && stack[i] <= '9') || (stack[i] >= 'a' && stack[i] <= 'z') || (stack[i] >= 'A' && stack[i] <= 'Z'))
          {
              operand[0]=stack[i];
              operand[1]='\0';
              push(operand);
          }
          else{
            pop(operand1);
            pop(operand2);
            snprintf(expression,sizeof(expression),"(%s%c%s)",operand2,stack[i],operand1);
            push(expression);
          }
    }
    strcpy(output,arr[top]);

}
void revpre()
{
    int i,j,k=0,a;
    a=strlen(pre);
    for(i=a-1;i>=0;i--)
    {
        stack[k]=pre[i];
        k=k+1;
    }
    char result[max];
    postToInfix(result);
    printf("Infix expression\n:- %s",result);
}
int main()
{


    printf("Enter the prefix expression:-\n");
    scanf("%s",pre);
    revpre();


}