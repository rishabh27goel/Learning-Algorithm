#include <iostream>
#include <vector>
using namespace std;

void subset(vector<int> v){
    int n=v.size();
    cout<<endl;
    for(int mask=0;mask<(1<<n);mask++){
        
        for(int bit=0;bit<n;bit++){
            if(mask & (1<<bit)){
                cout<<v[bit]<<" ";
            }
            
        }
        cout<<endl;
    }
}

int main()
{
    vector<int> v={1,2,3,5};
    cout<<"Printing the subsets :";
    subset(v);
    
    return 0;
}
