#include <iostream>
#include <algorithm>
#include <vector>
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

void levelOrder(struct Node *root){
    if(root==NULL){
        cout<<"Tree is Empty !!";
        return;
    }
    
    vector<Node*> v;
    v.push_back(root);
    int point=0;
    struct Node *current;
    
    while(!v.empty() && point<v.size()){
        
        current=v[point];
        cout<<current->data<<" ";
        
        if(current->left!=NULL){
            v.push_back(current->left);
        }
        if(current->right!=NULL){
            v.push_back(current->right);
        }
        
        point++;
    }
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
    
    root=createTree(root,arrNode,0,n);
    
    // Level order Traversal
    cout<<"Level order traversal: ";
    levelOrder(root);
    
    return 0;
}
