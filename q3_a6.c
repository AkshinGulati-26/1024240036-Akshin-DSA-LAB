#include <stdio.h>
#include <stdlib.h>

struct DLL{int data;struct DLL*next,*prev;};
struct DLL*dhead=NULL;

struct CLL{int data;struct CLL*next;};
struct CLL*chead=NULL;

void insertDLL(int v){
    struct DLL*n=malloc(sizeof(struct DLL));
    n->data=v;n->next=n->prev=NULL;
    if(!dhead){dhead=n;return;}
    struct DLL*t=dhead;
    while(t->next)t=t->next;
    t->next=n;n->prev=t;
}
void insertCLL(int v){
    struct CLL*n=malloc(sizeof(struct CLL));
    n->data=v;n->next=NULL;
    if(!chead){chead=n;n->next=chead;return;}
    struct CLL*t=chead;
    while(t->next!=chead)t=t->next;
    t->next=n;n->next=chead;
}

int sizeDLL(){
    int c=0;struct DLL*t=dhead;
    while(t){c++;t=t->next;}
    return c;
}

int sizeCLL(){
    if(!chead)return 0;
    int c=0;struct CLL*t=chead;
    do{c++;t=t->next;}while(t!=chead);
    return c;
}

int main(){
    insertDLL(1);insertDLL(2);insertDLL(3);
    insertCLL(5);insertCLL(10);
    printf("%d\n",sizeDLL());
    printf("%d\n",sizeCLL());
}
