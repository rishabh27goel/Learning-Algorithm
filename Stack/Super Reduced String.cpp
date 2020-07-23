#include <iostream>
#include <string.h>
using namespace std;

string superReducedString(string s) {
    char stack[200];
    int top=-1;
    int c=0;
    while(c!=s.size()+1){
        
        if(c==0){
            stack[++top]=s[c];
        }
        else{
            stack[++top]=s[c];
            if(stack[top]==stack[top-1] && top>0){
                top=top-2;
            }
        }
        c++;
    }
    if(strlen(stack)==0){
        return "Empty String";
    }
    else{
        return stack;
    }
}

int main()
{
    cout<<"Enter the string to reduce: ";
    string s;
    cin>>s;
    
    string result=superReducedString(s);
    cout<<"\nReduced string is : "<<result;

    return 0;
}
