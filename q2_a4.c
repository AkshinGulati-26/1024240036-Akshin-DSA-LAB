#include <stdio.h>
#include <stdlib.h>

struct Node{int data;struct Node*next;};
struct Node*head=NULL;

void insert(int v){
    struct Node*n=malloc(sizeof(struct Node));
    n->data=v;n->next=head;head=n;
}
int count(int k){
    int c=0;struct Node*t=head;
    while(t){if(t->data==k)c++;t=t->next;}
    return c;
}
void delAll(int k){
    while(head && head->data==k){
        struct Node*t=head;head=head->next;free(t);
    }
    struct Node*t=head;
    while(t && t->next){
        if(t->next->data==k){
            struct Node*x=t->next;t->next=x->next;free(x);
        } else t=t->next;
    }
}

int main(){
    insert(10);insert(20);insert(10);insert(30);insert(10);
    int k=10;
    printf("%d\n",count(k));
    delAll(k);
}
