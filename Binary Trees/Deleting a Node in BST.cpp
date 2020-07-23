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

Node* insertTree(struct Node *root,int data){
    
    if(root==NULL){
        root=createNode(data);
    }
    else if(data<=root->data){
        root->left=insertTree(root->left,data);
    }
    else{
        root->right=insertTree(root->right,data);
    }

    return root;
}

Node* minElement(struct Node *root){
    if(root==NULL){
        return root;
    }
    
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

void inorder(struct Node *root){
    if(root==NULL){
        return;
    }
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node *deleteNode(struct Node *root,int data){
    if(root==NULL){
        return root;
    }
    else if(root->data>data){
        root->left=deleteNode(root->left,data);
    }
    else if(root->data<data){
        root->right=deleteNode(root->right,data);
    }
    else{
        
        // Case: 1 ( No Child )
        if(root->left==NULL && root->right==NULL){
            delete root;
            root=NULL;
            return root;
        }
        
        // Case: 2 ( One Child )
        else if(root->left==NULL){
            struct Node *temp=root;
            root=root->right;
            delete temp;
            return root;
        }
        else if(root->right==NULL){
            struct Node *temp=root;
            root=root->left;
            delete temp;
            return root; 
        }
        
        // Case: 3 ( Two Child )
        else{
            struct Node *tempNode=minElement(root->right);
            root->data=tempNode->data;
            root->right=deleteNode(root->right,tempNode->data);
        }
        
    }
    
    return root;
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
        
        root=insertTree(root,data);
    }
    
    // Printing the Binary Search Tree 
    cout<<"\nPrinting the inorder traversal: ";
    inorder(root);
    
    // Deleting a node from Binary Search Tree
    cout<<"\nEnter the data to delete: ";
    int value;
    cin>>value;
    
    root=deleteNode(root,value);
    cout<<"\nNode Deleted !!\n";
    
    cout<<"\nPrinting the inorder traversal: ";
    inorder(root);
    
    return 0;
    
}