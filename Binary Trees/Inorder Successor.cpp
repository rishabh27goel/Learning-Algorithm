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
    new_node->left=NULL;
    new_node->right=NULL;
    new_node->data=data;
    
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

Node* findElement(struct Node *root,int data){
    if(root==NULL){
        return root;
    }
    else if(root->data>data){
        return findElement(root->left,data);
    }
    else if(root->data<data){
        return findElement(root->right,data);
    }
    else{
        return root;
    }
}

Node* minElement(struct Node *root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

Node* inorderSuccessor(struct Node *root,int data){
    struct Node *current=findElement(root,data);
    
    // Case: 1  ( When right tree is present )
    if(current->right!=NULL){
        struct Node *getNode=minElement(root->right);
        return getNode;
    }
    
    // Case: 2 ( When no right tree is present )
    else{
        struct Node *ancestor=root;
        struct Node *successor=NULL;
        
        while(ancestor!=current){
            if(current->data<ancestor->data){
                successor=ancestor;
                ancestor=ancestor->left;
            }
            else{
                ancestor=ancestor->right;
            }
        }
        return successor;
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
    
    int num;
    cout<<"Enter the node data to check successor: ";
    cin>>num;
    
    // Inorder Successor
    struct Node *output=inorderSuccessor(root,num);
    
    cout<<"Successor Node data is : ";
    cout<<output->data;
    
    return 0;
}
