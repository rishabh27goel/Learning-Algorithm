#include <iostream>
using namespace std;

long mainStack[100000];
long maxStack[100000];
int topMain=-1;
int topMax=-1;

void push(int val){
    mainStack[++topMain]=val;
    
    if(topMax==-1 || val>=maxStack[topMax]){
        maxStack[++topMax]=val;
    }
}

void pop(){
    if(mainStack[topMain]==maxStack[topMax]){
        topMain--;
        topMax--;
    }
    else{
        topMain--;
    }
}

int top(){
    return maxStack[topMax];
}

int main() {
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        int q;
        cin>>q;
        
        if(q==1){
            long val;
            cin>>val;
            
            push(val);
            
        }
        else if(q==2){
            pop();
        }
        else{
            int result=top();
            cout<<result<<endl;
        }
    }
    
    return 0;
}
