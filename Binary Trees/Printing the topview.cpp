#include <iostream>
#include <map>
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

void fillMap(struct Node *root,int d,int l,map<int,pair<int,int>> &m){
    if(root==NULL){
        return;
    }
    
    if(m.count(d)==0){
        m[d]=make_pair(root->data,l);
    }
    else if(m[d].second>l){
        m[d]=make_pair(root->data,l);
    }
    
    
    fillMap(root->left,d-1,l+1,m);
    
    fillMap(root->right,d+1,l+1,m);
    
}

void topView(struct Node *root){
    
    map<int,pair<int,int>> m;
    
    // fillmap( root , distance , level , map )
    fillMap(root,0,0,m);
    
    // Printing the topView
    map<int,pair<int,int>> :: iterator itr;
    for(itr=m.begin();itr!=m.end();itr++){
        cout<<itr->second.first<<" ";
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
    
    // Printing the topview
    cout<<"Printing the TopView: ";
    topView(root);
    return 0;    
}