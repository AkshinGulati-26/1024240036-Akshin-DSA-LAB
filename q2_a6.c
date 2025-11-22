#include <stdio.h>
#include <stdlib.h>

struct CLL{int data;struct CLL*next;};
struct CLL*head=NULL;

void insert(int v){
    struct CLL*n=malloc(sizeof(struct CLL));
    n->data=v;n->next=NULL;
    if(!head){head=n;n->next=head;return;}
    struct CLL*t=head;
    while(t->next!=head)t=t->next;
    t->next=n;n->next=head;
}

int main(){
    insert(20);insert(100);insert(40);insert(80);insert(60);
    struct CLL*t=head;
    do{printf("%d ",t->data);t=t->next;}while(t!=head);
    printf("%d ",head->data);
}
