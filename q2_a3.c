#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c){
    top++;
    stack[top] = c;
}

char pop(){
    char c = stack[top];
    top--;
    return c;
}

int main(){
    char str[MAX];
    scanf("%s", str);
    for(int i=0; i<strlen(str); i++){
        push(str[i]);
    }
    for(int i=0; i<strlen(str); i++){
        printf("%c", pop());
    }
}
