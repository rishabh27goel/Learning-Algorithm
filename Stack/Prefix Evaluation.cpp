#include <iostream>
#include <stack>
using namespace std;

int prefix_eval(string ex){
    
    stack<int> S;
    int result;
    
    for(int i=ex.size()-1;i>=0;i--){
        
        if(int(ex[i]-'0')>=0 && int(ex[i]-'0')<=9){
            
            S.push(int(ex[i]-'0'));
        }
        else{
            int a=S.top();
            S.pop();
            int b=S.top();
            S.pop();
            
            switch(ex[i]){
                
                case '+':
                    result=a+b;
                    break;
                    
                case '-':
                    result=a-b;
                    break;
                    
                case '*':
                    result=a*b;
                    break;
    
                case '/':
                    result=a/b;
                    break;
                    
                default:
                    cout<<"Error!! Check your expression";
                    break;
            }
            
            S.push(result);
            
        }
        
    }
    
    
    return S.top();
}

int main()
{
    string express;
    
    cout<<"Enter the prefix expression: ";
    cin>>express;
    
    int result=prefix_eval(express);
    cout<<"Evaluation is: ";
    cout<<result;
    

    return 0;
}
