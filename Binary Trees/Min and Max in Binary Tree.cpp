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
    new_node->right=NULL;
    new_node->left=NULL;
    return new_node;
}

int maxElement(struct Node *root){
    if(root==NULL){
        return INT_MIN;
    }
    
    int result=root->data;
    int lres=maxElement(root->left);
    int rres=maxElement(root->right);
    
    if(lres>result){
        result=lres;
    }
    if(rres>result){
        result=rres;
    }
    
    return result;
}

int minElement(struct Node *root){
    if(root==NULL){
        return INT_MAX;
    }
    
    int result=root->data;
    int lres=minElement(root->left);
    int rres=minElement(root->right);
    
    if(result>lres){
        result=lres;
    }
    if(result>rres){
        result=rres;
    }
    
    return result;
}

Node* createTree(int *arr,struct Node *root,int i,int n){
    if(i<n){
        
        // For root Node
        root=createNode(arr[i]);
        
        // leftnode
        root->left=createTree(arr,root->left,2*i+1,n);
        
        // Rightnode
        root->right=createTree(arr,root->right,2*i+2,n);
        
    }
    return root;
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
    
    root=createTree(arrNode,root,0,n);
    
    // Finding the maximum element
    
    cout<<"\nMaximum Element is: ";
    int max=maxElement(root);
    cout<<max;
    
    // Finding the minimum element
    
    cout<<"\nMinimum Element is: ";
    int min=minElement(root);
    cout<<min;
    
    return 0;
}