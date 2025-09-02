#include <stdio.h>
#include <ctype.h>
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

int prec(char c){
    if(c=='+' || c=='-') return 1;
    if(c=='*' || c=='/') return 2;
    if(c=='^') return 3;
    return 0;
}

int main(){
    char exp[MAX], res[MAX];
    int k=0;
    scanf("%s", exp);

    for(int i=0; exp[i]!='\0'; i++){
        if(isalnum(exp[i])){
            res[k++] = exp[i];
        }else if(exp[i]=='('){
            push(exp[i]);
        }else if(exp[i]==')'){
            while(top!=-1 && stack[top]!='('){
                res[k++] = pop();
            }
            pop();
        }else{
            while(top!=-1 && prec(stack[top]) >= prec(exp[i])){
                res[k++] = pop();
            }
            push(exp[i]);
        }
    }
    while(top!=-1){
        res[k++] = pop();
    }
    res[k] = '\0';
    printf("%s\n", res);
}
