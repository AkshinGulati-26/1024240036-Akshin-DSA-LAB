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
    else if(x>root->data) root->right=insertNode(root->right,x);
    return root;
}

Node* maxNode(Node* root){
    while(root->right!=NULL) root=root->right;
    return root;
}

Node* deleteNode(Node* root,int x){
    if(root==NULL) return root;
    if(x<root->data) root->left=deleteNode(root->left,x);
    else if(x>root->data) root->right=deleteNode(root->right,x);
    else{
        if(root->left==NULL) return root->right;
        else if(root->right==NULL) return root->left;
        Node* t=maxNode(root->left);
        root->data=t->data;
        root->left=deleteNode(root->left,t->data);
    }
    return root;
}

int maxDepth(Node* root){
    if(root==NULL) return 0;
    int l=maxDepth(root->left);
    int r=maxDepth(root->right);
    return 1+(l>r?l:r);
}

int minDepth(Node* root){
    if(root==NULL) return 0;
    int l=minDepth(root->left);
    int r=minDepth(root->right);
    if(l==0 || r==0) return 1+l+r;
    return 1+(l<r?l:r);
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
    root=deleteNode(root,x);
    cout<<maxDepth(root)<<endl;
    cout<<minDepth(root)<<endl;
}
