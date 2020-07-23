#include <iostream>
#include <stack>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *head=NULL;

Node* createNode(int data){
    struct Node *new_node;
    new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->data=data;
    new_node->next=NULL;
}


int main()
{
    // Creating a linklist 
    struct Node *new_node,*prev;
    int data=0;
    while(data!=-1){
        cout<<"Enter the data for the node: ";
        cin>>data;
        if(data==-1){
            break;
        }
        
        new_node=createNode(data);
        if(head==NULL){
            head=new_node;
            prev=new_node;
        }
        else{
            prev->next=new_node;
            prev=new_node;
        }
    }

    cout<<"Printing the linked list: ";
    struct Node *ptr;
    ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    
    // Reversing Logic using a stack
    stack<struct Node*> s;
    ptr=head;
    while(ptr!=NULL){
        s.push(ptr);
        ptr=ptr->next;
    }
    
    head=s.top();
    ptr=head;
    s.pop();
    while(!s.empty()){
        ptr->next=s.top();
        s.pop();
        ptr=ptr->next;
    }
    ptr->next=NULL;
    
    cout<<"\nPrinting in reverse order: ";
    ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    return 0;
}
