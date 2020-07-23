#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head=NULL;
    struct Node *new_node,*last;
    int data=-1;
    cout<<"Enter the data for nodes: ";
    while(data!=0){
        cin>>data;
        if(data==0){
            break;
        }
        
        new_node=(struct Node *)malloc(sizeof(struct Node));
        new_node->data=data;
        if(head==NULL){
            new_node->next=NULL;
            head=new_node;
            last=head;
        }
        else{
            new_node->next=NULL;
            last->next=new_node;
            
            last=new_node;
        }
    
    }
    
    int num;
    cout<<"\nEnter the value of n: ";
    cin>>num;
    
    struct Node *ptr=head;
    struct Node *list=NULL,*track;
    ptr=head;
    while(num!=0){
        
        track=ptr->next;
        
        if(list==NULL){
            list=ptr;
            list->next=NULL;
        }
        else{
            ptr->next=list;
            list=ptr;
        }
        
        ptr=track;
        num--;
    }
    
    ptr=list;
    struct Node *prev;
    while(ptr!=NULL){
        prev=ptr;
        ptr=ptr->next;
    }

    cout<<"Final linked list: ";
    prev->next=track;
    ptr=list;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    
    return 0;
}
