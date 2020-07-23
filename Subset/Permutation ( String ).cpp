#include <iostream>
using namespace std;
void permute(string s,int index,int size){
    if(index==size){
        cout<<s<<endl;
        return;
    }
    
    for(int i=index;i<size;i++){
        swap(s[i],s[index]);
        permute(s,index+1,size);
    }
    
}

int main()
{
    cout<<"Enter a string to find the permutation: ";
    string s;
    cin>>s;
    int index=0;
    permute(s,index,s.size());
    return 0;
}
