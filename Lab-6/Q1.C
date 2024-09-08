#include<stdio.h>
#include<string.h>
#define max 50

char inf[max];
char pre[max];
char s[max];
char postfix[max];
int top = -1;

void push(char ele)
{
    if (top == max - 1)
        printf("Stack overflow\n");
    else
        s[++top] = ele;
}

char pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return '\0';
    }
    else
        return s[top--];
}

int isEmpty()
{
    return top == -1;
}

int precedence(char symbol)
{
    switch (symbol)
    {
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}
void finalans()
{
    int a = strlen(postfix);
    int i, k = 0;
    for (i = a - 1; i >= 0; i--)
        pre[k++] = postfix[i];
    pre[k] = '\0';
    printf("%s\n", pre);
}
void inToPost()
{
    int i, j = 0;
    char symbol, next;

    for (i = 0; i < strlen(inf); i++)
    {
        symbol = inf[i];
        switch (symbol)
        {
        case '(':
            push(symbol);
            break;
        case ')':
            while ((next = pop()) != '(')
                postfix[j++] = next;
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while (!isEmpty() && precedence(s[top]) >= precedence(symbol))
                postfix[j++] = pop();
            push(symbol);
            break;
        default:
            postfix[j++] = symbol;
        }
    }

    while (!isEmpty())
        postfix[j++] = pop();
    postfix[j] = '\0';
    finalans();
}

void revin()
{
    int a = strlen(inf);
    char revinf[max];
    int i, k = 0;

    for (i = a - 1; i >= 0; i--)
    {
        if (inf[i] == '(')
            revinf[k++] = ')';
        else if (inf[i] == ')')
            revinf[k++] = '(';
        else
            revinf[k++] = inf[i];
    }
    revinf[k] = '\0';
    strcpy(inf, revinf);
    inToPost();
}

int main()
{
    printf("Enter infix expression: ");
    fgets(inf, max, stdin);
    inf[strcspn(inf, "\n")] = 0;
    revin();
}