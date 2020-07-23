#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

Node* removeCycle(struct Node *head){
    if(head==NULL || head->next==NULL) return head;
    
    struct Node *fast=head->next,*prev_fast;
    struct Node *slow=head;
    
    while(slow!=fast){
        if(fast==NULL || fast->next==NULL) return head;

        fast=fast->next->next;
        slow=slow->next;
        
    }
    prev_fast=prev_fast->next;
    int size=1;
    fast=fast->next;
    
    while(fast!=slow){
        size++;
        fast=fast->next;
    }
    
    cout<<"\nSize of the cycle is: ";
    cout<<size;
    
    fast=head;
    slow=head;
    
    for(int i=0;i<size-1;i++){
        fast=fast->next;
    }
    
    while(fast->next!=slow){
        slow=slow->next;
        fast=fast->next;
    }
    
    fast->next=NULL;
    
    return head;
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
    
    cout<<"\nSize of vector: ";
    cout<<v.size();
    
    // To create a cycle in the linked list
    v[5]->next=v[2];

    head=removeCycle(head);
    
    
    // Printing the linked list after removing the cycle
    struct Node *ptr=head;
    cout<<"\nPrinting the linked list: ";
    while(ptr->next!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<ptr->data;
    return 0;
}
