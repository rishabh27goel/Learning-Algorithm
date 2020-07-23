#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    
    vector<int> v;
    int x;
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    cout<<"\nPrinting before sorting: ";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    
    int key;
    for(int i=1;i<n;i++){
        key=v[i];
        int j=i-1;
        
        while(j>=0 && key<v[j]){
            v[j+1]=v[j];
            j=j-1;
        }
        
        v[j+1]=key;
    }
    
    cout<<"\nPrinting After swapping: ";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }

    return 0;
}
