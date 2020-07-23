#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

void deleteNode(struct Node **head){
    if(*head=NULL){
        return;
    }
    
    struct Node *current=*head,*temp;
    while(current!=NULL){
        temp=current->next;
        delete current;
        current=temp;
    }
    
}

int main()
{
    struct Node *new_node,*prev;
    struct Node *head=NULL;
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
    
    struct Node *ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    
    deleteNode(&head);
    
    cout<<"\nPrinting after deleting linked list: ";
    if(head==NULL){
        cout<<"List is empty";   
    }
    
    
    return 0;
}
