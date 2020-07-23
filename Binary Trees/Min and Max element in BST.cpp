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

Node* createTree(struct Node *root,int data){
    
    if(root==NULL){
        root=createNode(data);
    }
    else if(root->data>=data){
        root->left=createTree(root->left,data);
    }
    else{
        root->right=createTree(root->right,data);
    }
    
    return root;
}

int maxElement(struct Node *root){
    if(root==NULL){
        cout<<"Tree is Empty !!";
        return 0;
    }
    
    while(root->right!=NULL){
        root=root->right;
    }
    
    return root->data;
}

int minElement(struct Node *root){
    if(root==NULL){
        cout<<"Tree is Empty !!";
        return 0;
    }
    
    if(root->left==NULL){
        return root->data;
    }
    return minElement(root->left);
}

int main()
{
    struct Node *root=NULL;
    int data=0;
    
    while(data!=-1){
        cout<<"Enter the data: ";
        cin>>data;
        
        if(data==-1){
            break;
        }
        
        root=createTree(root,data);
    }
    
    // Maximum Element of the Tree
    int max=maxElement(root);
    cout<<"\nMaximum Element is : ";
    cout<<max;

    // Mininmum Element of the Tree
    int min=minElement(root);
    cout<<"\nMinimum Element is : ";
    cout<<min;
    
    
    return 0;
}