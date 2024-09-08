#include<stdio.h>
#include<string.h>
#define max 50
char stack[max],s[max];
char infix[max],prefix[max];
int top=-1;
void push(char c)
{
    if(top==max-1)
    {
        printf("Stack overflow\n");
    }
    else
        s[++top]=c;
}
char pop()
{
    if(top==-1)
    {
        printf("Stack underflow\n");
        return '\0';
    }
    else
        return s[top--];
}
int evalpos()
{
    int i,j,op1,op2,a;
    char c;
    for(i=0;i<strlen(stack);i++)
    {
      if (stack[i] >= '0' && stack[i] <= '9')
        push(stack[i]-'0');
        else
      {
          op2=pop();
          op1=pop();
          switch(stack[i])
          {
              case '+':push(op1+op2);
              break;
              case '-':push(op1-op2);
              break;
              case'*':push(op1*op2);
              break;
              case'/':push(op1/op2);
              break;
              case'%':push(op1%op2);
              break;
          }
      }

    }
    a=pop();
    printf("%d",a);
}

void revpre()
{
    int i,j,k=0,a;
    a=strlen(prefix);
    for(i=a-1;i>=0;i--)
    {
        stack[k]=prefix[i];
        k=k+1;
    }
    evalpos();
}
int main()
{
    printf("Enter infix expression: ");
    fgets(prefix, max, stdin);
    prefix[strcspn(prefix, "\n")] = 0;
    revpre();
}