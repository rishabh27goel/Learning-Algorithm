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

bool findInBst(struct Node *root,int search){
    if(root==NULL){
        return false;
    }
    if(root->data==search){
        return true;
    }
    else if(root->data>search){
        return findInBst(root->left,search);
    }
    else{
        return findInBst(root->right,search);
    }
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
    
    // Seaching in BST
    int search;
    cout<<"Enter the number to search in BST: ";
    cin>>search;
    
    if(findInBst(root,search)){
        cout<<"\nFound in BST !!";
    }
    else{
        cout<<"\nNot Found in BST !!";
    }
    
    return 0;    
}