#include <iostream>
#include <stack>
using namespace std;

int main()
{
    cout<<"Enter the string: ";
    string str;
    cin>>str;
    
    stack<int> S;
    for(int i=0;i<str.size();i++){
        if(str[i]=='('){
            S.push(i);
        }
        else{
            S.pop();
        }
        
    }

    int takeBool[str.size()]={0};
    cout<<"\nElements index to be deleted: ";
    while(!S.empty()){
        cout<<S.top()<<" ";
        takeBool[S.top()]=1;
        S.pop();
    }
    
    cout<<"\nElement with value { 1:(Not include) || 0:(Include) } : ";
    for(int i=0;i<str.size();i++){
        cout<<takeBool[i]<<" ";
    }
    
    string final="";
    for(int i=0;i<str.size();i++){
        if(takeBool[i]==0){
            final=final+str[i];
        }
    }
    cout<<"\nFinal string is: ";
    cout<<final;
    return 0;
}

