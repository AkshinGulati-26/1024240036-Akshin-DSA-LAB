#include <stdio.h>
#include <string.h>

#define N 100

char stack[N];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

int main()
{
    char s[100];
    int i, ok = 1;

    scanf("%s", s);

    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            push(s[i]);
        }
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if (top == -1)
            {
                ok = 0;
                break;
            }
            char c = pop();
            if ((s[i] == ')' && c != '(') || (s[i] == '}' && c != '{') || (s[i] == ']' && c != '['))
            {
                ok = 0;
                break;
            }
        }
    }

    if (top != -1)
    {
        ok = 0;
    }

    if (ok)
    {
        printf("Balanced\n");
    }
    else
    {
        printf("Not Balanced\n");
    }

    return 0;
}
