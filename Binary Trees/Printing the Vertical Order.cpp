#include <iostream>
#include <vector>
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
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
    
}

Node* createTree(int *arr,struct Node *root,int i,int n){
    
    if(i<n){
        
        // Root Node 
        root=createNode(arr[i]);
        
        // Left Node
        root->left=createTree(arr,root->left,2*i+1,n);
        
        // Right Node
        root->right=createTree(arr,root->right,2*i+2,n);
        
    }
    
    return root;
}
void getVerticalOrder(struct Node *root,int hd,map<int,vector<int>> &m){
    if(root==NULL){
        return;
    }
    
    // Storing the data 
    m[hd].push_back(root->data);
    
    // Left Child Call
    getVerticalOrder(root->left,hd-1,m);
    
    // Right Child Call
    getVerticalOrder(root->right,hd+1,m);
}

void printVerticalOrder(struct Node *root){
    map<int,vector<int>> mymap;
    int hd=0;
    getVerticalOrder(root,hd,mymap);
    
    map<int,vector<int>> :: iterator itr;
    for(itr=mymap.begin();itr!=mymap.end();itr++){
        
        for(auto ele : itr->second){
            cout<<ele<<" ";
        }
        cout<<endl;
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
    
    root=createTree(arrNode,root,0,n);
    
    // Printing the vertical order
    cout<<"\nPrinting the vertical order: \n";
    printVerticalOrder(root);
    
    return 0;
}