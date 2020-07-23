#include <iostream>
using namespace std;
#define max 100

int stack[max];
int top=-1;

void push(int n){
    cout<<"Pushing "<<n<<" into the stack: \n";
    top=top+1;
    stack[top]=n;
}

void pop(){
    cout<<"Poping "<<stack[top]<<" out of the stack: \n";
    top=top-1;
}

int top_stack(){
    return stack[top];
}

void print(){
    for(int i=top;i>=0;i--){
        cout<<stack[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    cout<<"Implementing stack : \n";
    push(5);print();
    push(10);print();
    push(15);print();
    pop();print();
    int val=top_stack();
    cout<<"Value of top: "<<val;
    

    return 0;
}
