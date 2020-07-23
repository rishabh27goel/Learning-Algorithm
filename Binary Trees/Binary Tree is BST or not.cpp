#include <iostream>
#include <limits.h>
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
        // Rootnode
        root=createNode(arr[i]);
        
        // Left Node
        root->left=createTree(root->left,arr,2*i+1,n);
        
        // Right Node
        root->right=createTree(root->right,arr,2*i+2,n);
        
    }
    
    return root;
}

bool BstIsUtil(struct Node *root,int min,int max){
    if(root==NULL){
        return true;
    }
    
    if(root->data>min && root->data<max 
               && BstIsUtil(root->left,min,root->data) && BstIsUtil(root->right,root->data,max)){
        
        return true;
    }
    else{
        return false;
    }
}


bool isBinaryBST(struct Node *root){
    
    return BstIsUtil(root,INT_MIN,INT_MAX);
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
    
    // Array of Nodes
    cout<<"\nArray of nodes data: ";
    for(int i=0;i<n;i++){
        cout<<arrNode[i]<<" ";
    }
    
    root=createTree(root,arrNode,0,n);
    
    cout<<"\nBinary Tree is created\n";
    
    // Checking if a binary tree is BST or not
    cout<<"\n\nResult : ";
    if(isBinaryBST(root)){
        cout<<"Binary Search Tree";
    }
    else{
        cout<<"Not a Binary Search Tree";
    }
    
    return 0;
}