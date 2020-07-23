#include <iostream>
#include <algorithm>
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
        
        // For root Node
        root=createNode(arr[i]);
        
        // For left Node
        root->left=createTree(root->left,arr,2*i+1,n);
        
        // For left Node
        root->right=createTree(root->right,arr,2*i+2,n);
    }
    return root;
}

int findHeight(struct Node *root){
    
    if(root==NULL){
        return -1;
    }
    
    return max(findHeight(root->left),findHeight(root->right))+1;
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
    
    cout<<"\nArray of Node data: ";
    for(int i=0;i<n;i++){
        cout<<arrNode[i]<<" ";
    }
    
    root=createTree(root,arrNode,0,n);
    
    // Finding the height of the binary tree
    int result=findHeight(root);
    cout<<"\nHeight of the binary tree is : ";
    cout<<result;
    
    return 0;
}
