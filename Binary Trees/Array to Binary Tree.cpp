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

void inorder(struct Node *root){
    if(root==NULL){
        return ;
    }
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    
}


Node* createTree(struct Node *root,int *arr,int i,int n){
    
    if(i<n){
        
        // Root Node
        root=createNode(arr[i]);
        
        // Left of Root Node
        root->left=createTree(root->left,arr,2*i+1,n);
        
        // Right of Root Node
        root->right=createTree(root->right,arr,2*i+2,n);
        
    }
    
    return root;
}

int main()
{       
    struct Node *root=NULL;
    int arrNode[200];
    int n=0,data=0;
    
    while(data!=-1){
        cout<<"Enter the data: ";
        cin>>data;
        if(data==-1){
            break;
        }
        
        arrNode[n]=data;
        n++;
    }
    
    cout<<"Array of nodes: ";
    for(int x=0;x<n;x++){
        cout<<arrNode[x]<<" ";
    }
    
    root=createTree(root,arrNode,0,n);
    
    cout<<"\nInorder Traversal: ";
    // Inorder Traversal 
    inorder(root);
    
    
    
    
    return 0;
}