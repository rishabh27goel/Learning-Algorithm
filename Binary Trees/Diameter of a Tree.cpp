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

int findHeight(struct Node *root,int *dia){
    if(root==NULL){
        return 0;
    }
    
    int lHeight=findHeight(root->left,dia);
    int rHeight=findHeight(root->right,dia);
    int max=1+lHeight+rHeight;
    
    if(*dia<max){
        *dia=max;
    }
    
    if(rHeight>lHeight){
        max=rHeight+1;
    }
    else{
        max=lHeight+1;
    }
    
    return max;
}

int findDiameter(struct Node *root){
    if(root==NULL){
        return 0;
    }
    
    int dia=INT_MIN;
    int height=findHeight(root,&dia);
    
    return dia;
}

int main()
{
    int data;
    struct Node *root=NULL;
    
    while(data!=-1){
        cout<<"Enter the data: ";
        cin>>data;
        
        if(data==-1){
            break;
        }
        
        root=createTree(root,data);
    }
    
    // Diameter of the Tree
    cout<<"Diameter of the tree: ";
    int result=findDiameter(root);
    cout<<result;
    
    
    return 0;
}