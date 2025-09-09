#include <stdio.h>
#include <ctype.h>

#define N 100

int stack[N];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char s[100];
    int i, a, b;

    scanf("%s", s);

    for (i = 0; s[i] != '\0'; i++)
    {
        if (isdigit(s[i]))
        {
            push(s[i] - '0');
        }
        else
        {
            b = pop();
            a = pop();

            if (s[i] == '+')
            {
                push(a + b);
            }
            else if (s[i] == '-')
            {
                push(a - b);
            }
            else if (s[i] == '*')
            {
                push(a * b);
            }
            else if (s[i] == '/')
            {
                push(a / b);
            }
        }
    }

    printf("%d\n", pop());

    return 0;
}
