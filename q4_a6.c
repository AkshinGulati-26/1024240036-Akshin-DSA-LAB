#include <stdio.h>
#include <stdlib.h>

struct Node{char data;struct Node*next,*prev;};
struct Node*head=NULL;

void insert(char v){
    struct Node*n=malloc(sizeof(struct Node));
    n->data=v;n->next=n->prev=NULL;
    if(!head){head=n;return;}
    struct Node*t=head;
    while(t->next)t=t->next;
    t->next=n;n->prev=t;
}

int main(){
    char s[]="LEVEL";
    for(int i=0;s[i];i++)insert(s[i]);
    struct Node*l=head,*r=head;
    while(r->next)r=r->next;
    while(l!=r && r->next!=l){
        if(l->data!=r->data){printf("False");return 0;}
        l=l->next;r=r->prev;
    }
    printf("True");
}
