#include <iostream>
#include <stack>
using namespace std;

int main()
{
    cout<<"Enter the string :";
    string str;
    cin>>str;
    
    // Pushing into a stack
    stack<int> S;
    for(int i=0;i<str.size();i++){
        S.push(str[i]);
    }
    
    // Reversing the string
    for(int i=0;i<str.size();i++){
        str[i]=S.top();
        S.pop();
    }
    
    cout<<"Reversed string is : "<<str;
    
    return 0;
}
