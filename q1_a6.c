#include <stdio.h>
#include <stdlib.h>

struct DLL { int data; struct DLL *prev,*next; };
struct DLL *dhead=NULL;

struct CLL { int data; struct CLL *next; };
struct CLL *chead=NULL;

void dllInsert(int v){
    struct DLL *n=malloc(sizeof(struct DLL));
    n->data=v;n->prev=n->next=NULL;
    if(!dhead){dhead=n;return;}
    struct DLL *t=dhead;
    while(t->next)t=t->next;
    t->next=n;n->prev=t;
}
void dllDelete(int k){
    struct DLL *t=dhead;
    while(t && t->data!=k)t=t->next;
    if(!t)return;
    if(t->prev)t->prev->next=t->next; else dhead=t->next;
    if(t->next)t->next->prev=t->prev;
    free(t);
}
void dllSearch(int k){
    struct DLL *t=dhead;int p=1;
    while(t){
        if(t->data==k){printf("Found in DLL at %d\n",p);return;}
        t=t->next;p++;
    }
    printf("Not Found in DLL\n");
}
void dllDisplay(){
    struct DLL*t=dhead;
    while(t){printf("%d ",t->data);t=t->next;}
    printf("\n");
}

void cllInsert(int v){
    struct CLL*n=malloc(sizeof(struct CLL));
    n->data=v;n->next=NULL;
    if(!chead){chead=n;n->next=chead;return;}
    struct CLL*t=chead;
    while(t->next!=chead)t=t->next;
    t->next=n;n->next=chead;
}
void cllDelete(int k){
    if(!chead)return;
    struct CLL*t=chead,*p=NULL;
    if(chead->data==k){
        while(t->next!=chead)t=t->next;
        if(t==chead){free(chead);chead=NULL;return;}
        t->next=chead->next;free(chead);chead=t->next;return;
    }
    p=chead;t=chead->next;
    while(t!=chead && t->data!=k){p=t;t=t->next;}
    if(t!=chead){p->next=t->next;free(t);}
}
void cllSearch(int k){
    if(!chead)return;
    struct CLL*t=chead;int p=1;
    do{ if(t->data==k){printf("Found in CLL at %d\n",p);return;}
        t=t->next;p++;
    }while(t!=chead);
    printf("Not Found in CLL\n");
}
void cllDisplay(){
    if(!chead)return;
    struct CLL*t=chead;
    do{printf("%d ",t->data);t=t->next;}while(t!=chead);
    printf("\n");
}

int main(){
    int ch,v;
    while(1){
        printf("\n1.Insert DLL 2.Delete DLL 3.Search DLL 4.Display DLL 5.Insert CLL 6.Delete CLL 7.Search CLL 8.Display CLL 9.Exit\n");
        scanf("%d",&ch);
        if(ch==1){scanf("%d",&v);dllInsert(v);}
        else if(ch==2){scanf("%d",&v);dllDelete(v);}
        else if(ch==3){scanf("%d",&v);dllSearch(v);}
        else if(ch==4){dllDisplay();}
        else if(ch==5){scanf("%d",&v);cllInsert(v);}
        else if(ch==6){scanf("%d",&v);cllDelete(v);}
        else if(ch==7){scanf("%d",&v);cllSearch(v);}
        else if(ch==8){cllDisplay();}
        else if(ch==9)break;
    }
}
