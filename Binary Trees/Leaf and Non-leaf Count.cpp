#include <iostream>
using namespace std;

struct Node{
    struct Node *left;
    int data;
    struct Node *right;
};

Node* createNode(int data){
    struct Node *new_node;
    new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

Node* createTree(struct Node *root,int *arr,int i,int n){
    
    if(i<n){
        
        // Root Node
        root=createNode(arr[i]);
        
        // Left of root node
        root->left=createTree(root->left,arr,2*i+1,n);
        
        // Right of root node 
        root->right=createTree(root->right,arr,2*i+2,n);
        
    }
    
    return root;
}

int nonLeafCount(struct Node *root){
    if(root==NULL){
        return 0;
    }
    
    if(root->left!=NULL || root->right!=NULL){
        return 1+nonLeafCount(root->left)+nonLeafCount(root->right);
    }
    else{
        return 0;
    }
    
}

int leafCount(struct Node *root){
    if(root==NULL){
        return 0;
    }
    
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    else{
        return leafCount(root->left)+leafCount(root->right);
    }
}

int main()
{
    struct Node *root=NULL;
    int data=0;
    int arrNode[200];
    int n=0;
    
    while(data!=-1){
        cout<<"Enter the data: ";
        cin>>data;
        
        if(data==-1){
            break;
        }
        
        arrNode[n]=data;
        n++;
    }
    
    
    root=createTree(root,arrNode,0,n);
    
    // Number of leaf nodes
    int leaf=leafCount(root);
    cout<<"\nNumber of leaf nodes: ";
    cout<<leaf;
    
    // Number of non-leaf nodes
    int non_leaf=nonLeafCount(root);
    cout<<"\nNumber of non-leaf nodes: ";
    cout<<non_leaf;
    
    return 0;
}