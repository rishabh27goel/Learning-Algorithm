#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};
struct Node *top=NULL;

Node* createNode(int data){
    struct Node *new_node;
    new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}

void push(int data){
    cout<<"Pushing a node with data "<<data<<" in the stack: \n";
    struct Node *new_node;
    new_node=createNode(data);
    
    if(top==NULL){
        top=new_node;
    }
    else{
        new_node->next=top;
        top=new_node;
    }
}

void pop(){
    if(top==NULL){
        cout<<"Empty list of stack Implementation\node";
        return ;
    }
    cout<<"Poping a node with data "<<top->data<<" out of the stack: \n";
    struct Node *temp;
    temp=top;
    top=top->next;
    free(temp);
}

int top_stack(){
    return top->data;
}

void print(){
    struct Node *ptr=top;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

int main(){
    
    cout<<"Implementing the stack: \n";
    push(5);print();
    push(10);print();
    push(15);print();
    pop();print();
    pop();print();
    
    int val=top_stack();
    cout<<"\nTop of the stack: "<<val;
    
    
    return 0;
}