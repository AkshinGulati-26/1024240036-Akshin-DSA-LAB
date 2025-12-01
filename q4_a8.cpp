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

bool check(Node* root,int min,int max){
    if(root==NULL) return true;
    if(root->data<=min || root->data>=max) return false;
    return check(root->left,min,root->data) && check(root->right,root->data,max);
}

int main(){
    int n,x;
    cin>>n;
    Node* root=NULL;
    for(int i=0;i<n;i++){
        cin>>x;
        root=insertNode(root,x);
    }
    cout<<(check(root,-1000000,1000000)?1:0);
}
