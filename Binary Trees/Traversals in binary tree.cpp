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

Node* createTree(int *arr,struct Node *root,int i,int n){
    
    if(i<n){
        
        // Root Node creation
        root=createNode(arr[i]);
        
        // Root Left Node
        root->left=createTree(arr,root->left,2*i+1,n);
        
        // Root Right Node
        root->right=createTree(arr,root->right,2*i+2,n);
        
    }
    
    return root;
}

void inorderTrav(struct Node *root){
    if(root==NULL){
        return ;
    }
    
    inorderTrav(root->left);
    cout<<root->data<<" ";
    inorderTrav(root->right);
    
}

void preorderTrav(struct Node *root){
    if(root==NULL){
        return;
    }
    
    cout<<root->data<<" ";
    preorderTrav(root->left);
    preorderTrav(root->right);
    
}

void postorderTrav(struct Node *root){
    if(root==NULL){
        return;
    }
    
    postorderTrav(root->left);
    postorderTrav(root->right);
    cout<<root->data<<" ";
    
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
    
    // Array of the node data
    
    cout<<"\nPrinting the array of the data: ";
    for(int i=0;i<n;i++){
        cout<<arrNode[i]<<" ";
    }
    
    root=createTree(arrNode,root,0,n);
    
    cout<<"\nInorder Traversal: ";
    // Inorder Traversal 
    inorderTrav(root);
    
    cout<<"\nPreorder Traversal: ";
    // Preorder Traversal
    preorderTrav(root);
    
    cout<<"\nPostorder Traversal: ";
    // Postorder Traversal
    postorderTrav(root);

    
    return 0;    
}