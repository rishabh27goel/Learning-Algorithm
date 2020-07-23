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
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            
            if(v[j+1]<v[j]){
    
                int temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
            }
        }
    }
    
    cout<<"Printing After swapping: ";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }

    return 0;
}
