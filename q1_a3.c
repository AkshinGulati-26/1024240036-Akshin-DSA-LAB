#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int x){
    if(top == MAX-1){
        printf("Overflow");
    }else{
        top++;
        stack[top] = x;
    }
}

void pop(){
    if(top == -1){
        printf("Underflow\n");
    }else{
        printf("%d", stack[top]);
        top--;
    }
}

void display(){
    if(top == -1){
        printf("Empty\n");
    }else{
        for(int i=top; i>=0; i--){
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

void peek(){
    if(top == -1){
        printf("Empty\n");
    }else{
        printf("%d\n", stack[top]);
    }
}

int main(){
    int ch,x;
    while(1){
        printf("1.Push 2.Pop 3.Display 4.Peek 5.Exit\n");
        scanf("%d",&ch);
        if(ch==1){
            scanf("%d",&x);
            push(x);
        }else if(ch==2){
            pop();
        }else if(ch==3){
            display();
        }else if(ch==4){
            peek();
        }else{
            break;
        }
    }
}
