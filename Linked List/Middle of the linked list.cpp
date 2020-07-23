#include <iostream>
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

Node* findMiddleElement(struct Node *head){
    struct Node *fast=head,*slow=head;
    
    if(head!=NULL && head->next!=NULL){
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        
        return slow;
        
    }
    else{
        return head;
    }
}

int main()
{
    struct Node *head=NULL;
    struct Node *new_node,*prev;
    int data=0;
    
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
    
    }
    
    cout<<"\nPrinting the linked list: ";
    printLinkedList(head);
    
    // Finding the middle element of the linked list
    
    struct Node *middle=findMiddleElement(head);
    cout<<"\nMiddle node data is : ";
  
    cout<<middle->data;
    
    
    return 0;
}
