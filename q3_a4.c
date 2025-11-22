#include <stdio.h>
#include <stdlib.h>

struct Node{int data;struct Node*next;};
struct Node*head=NULL;

void insertEnd(int v){
    struct Node*n=malloc(sizeof(struct Node));
    n->data=v;n->next=NULL;
    if(!head){head=n;return;}
    struct Node*t=head;
    while(t->next)t=t->next;
    t->next=n;
}

int main(){
    insertEnd(10);insertEnd(20);insertEnd(30);insertEnd(40);insertEnd(50);
    struct Node*slow=head,*fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    printf("%d",slow->data);
}
