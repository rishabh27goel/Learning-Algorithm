#include <iostream>
using namespace std;
struct Node{
    int data;
    struct Node *next;
};
int main()
{
    int data=0;
    struct Node *list1=NULL;
    struct Node *list2=NULL;
    struct Node *new_node;
    
    // First Linked List
    cout<<"Enter the elements of the first list :";
    while(data!=-1){
        cin>>data;
        if(data==-1){
            break;
        }
        new_node=(struct Node *)malloc(sizeof(struct Node));
        new_node->data=data;
        if(list1==NULL){
            new_node->next=NULL;
            list1=new_node;
        }
        else{
            new_node->next=list1;
            list1=new_node;
        }
    }
    cout<<"Printing the linked list : ";
    struct Node *ptr=list1;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    
    // Second Linked List
    cout<<"\nEnter the elements of the second list :";
    data=0;
    while(data!=-1){
        cin>>data;
        if(data==-1){
            break;
        }
        new_node=(struct Node *)malloc(sizeof(struct Node));
        new_node->data=data;
        if(list2==NULL){
            new_node->next=NULL;
            list2=new_node;
        }
        else{
            new_node->next=list2;
            list2=new_node;
        }
    }
    cout<<"Printing the linked list : ";
    ptr=list2;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    
    long long int n1=0,n2=0;
    ptr=list1;
    while(ptr!=NULL){
        n1=(n1*10)+(ptr->data);
        ptr=ptr->next;
    }
    ptr=list2;
    while(ptr!=NULL){
        n2=(n2*10)+(ptr->data);
        ptr=ptr->next;
    }
    int sum=n1+n2;
    struct Node *list3=NULL;
    
    cout<<"\nSum of list : "<<sum; 
    while(sum>0){
        new_node=(struct Node *)malloc(sizeof(struct Node));
        new_node->data=sum%10;
        if(list3==NULL){
            new_node->next=NULL;
            list3=new_node;
        }
        else{
            new_node->next=list3;
            list3=new_node;
        }
        sum=sum/10;
    }
    
    cout<<"\nPrinting the linked list : ";
    ptr=list3;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    return 0;
}
