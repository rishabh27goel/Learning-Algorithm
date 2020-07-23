#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

void printLinkedList(struct Node *head){
    if(head==NULL){
        return;
    }
    
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }   
}

bool hasCycle(struct Node *head){
    if(head==NULL || head->next==NULL) false;
    
    struct Node *fast=head->next;
    struct Node *slow=head;
    
    while(fast!=slow){
        if(fast==NULL || fast->next==NULL) return false;
        
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int main()
{
    struct Node *head=NULL;
    struct Node *new_node,*prev;
    int data=0;
    
    vector<Node*> v;
    
    while(data!=-1){
        
        cout<<"Enter the data: ";
        cin>>data;
        
        if(data==-1){
            break;
        }
        
        new_node=(struct Node *)malloc(sizeof(struct Node));
        new_node->data=data;
        new_node->next=NULL;
        
        if(head==NULL){
            head=new_node;
            prev=new_node;
        }
        else{
            prev->next=new_node;
            prev=new_node;
        }
        
        v.push_back(new_node);
    }
    
    cout<<"\nPrinting the linked list: ";
    printLinkedList(head);
    
    cout<<"\nSize of vector: ";
    cout<<v.size();
    
    // To create a cycle in the linked list
    v[5]->next=v[2];
    
    if(hasCycle(head)){
        cout<<"\nCycle is present";
        
    }
    else{
        cout<<"\nNo cycle is present";
    }
    
    return 0;
}
