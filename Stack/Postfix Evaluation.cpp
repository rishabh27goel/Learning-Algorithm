#include <iostream>
#include <stack>
#include <string>
using namespace std;

int eval_postfix(string ex){
    int result=0;
    stack<int> S;
    
    for(char ch:ex){
        
        if(int(ch-'0')>=0 && int(ch-'0')<=9){
            S.push(int(ch-'0'));
        }
        else{
            
            int a=S.top();
            S.pop();
            int b=S.top();
            S.pop();
            
            switch(ch){
                case '+': 
                    result=a+b;   
                    break;
                case '-': 
                    result=b-a;   
                    break;
                case '*': 
                    result=a*b;   
                    break;
                case '/': 
                    result=b/a;   
                    break;
                default: 
                    cout<<"Error!! Expression not valid"; 
                    break;
            }
            S.push(result);
        }
    }

    return result;
}
int main()
{
    cout<<"Enter the your postfix expression: ";
    string express;
    cin>>express;
    
    
    int result=eval_postfix(express);
    cout<<"\nAfter the evaluation : "<<result;
    

    return 0;
}
