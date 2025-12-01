#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int x){
    Node* t=new Node;
    t->data=x;
    t->left=t->right=NULL;
    return t;
}

Node* insertNode(Node* root,int x){
    if(root==NULL) return newNode(x);
    if(x<root->data) root->left=insertNode(root->left,x);
    else root->right=insertNode(root->right,x);
    return root;
}

Node* recursiveSearch(Node* root,int x){
    if(root==NULL || root->data==x) return root;
    if(x<root->data) return recursiveSearch(root->left,x);
    return recursiveSearch(root->right,x);
}

Node* nonRecursiveSearch(Node* root,int x){
    while(root!=NULL && root->data!=x){
        if(x<root->data) root=root->left;
        else root=root->right;
    }
    return root;
}

int maxBST(Node* root){
    while(root->right!=NULL) root=root->right;
    return root->data;
}

int minBST(Node* root){
    while(root->left!=NULL) root=root->left;
    return root->data;
}

Node* successor(Node* root,int x){
    Node* suc=NULL;
    while(root!=NULL){
        if(x<root->data){
            suc=root;
            root=root->left;
        } else root=root->right;
    }
    return suc;
}

Node* predecessor(Node* root,int x){
    Node* pre=NULL;
    while(root!=NULL){
        if(x>root->data){
            pre=root;
            root=root->right;
        } else root=root->left;
    }
    return pre;
}

int main(){
    int n,x;
    cin>>n;
    Node* root=NULL;
    for(int i=0;i<n;i++){
        cin>>x;
        root=insertNode(root,x);
    }
    cin>>x;
    Node* r1=recursiveSearch(root,x);
    Node* r2=nonRecursiveSearch(root,x);
    cout<<(r1?1:-1)<<" "<<(r2?1:-1)<<endl;
    cout<<maxBST(root)<<endl;
    cout<<minBST(root)<<endl;
    Node* s=successor(root,x);
    Node* p=predecessor(root,x);
    cout<<(s?s->data:-1)<<endl;
    cout<<(p?p->data:-1)<<endl;
}
