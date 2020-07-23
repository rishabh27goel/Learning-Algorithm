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
    
    int curr_i;
    for(int i=0;i<n;i++){
        curr_i=i;
        for(int j=i+1;j<n;j++){
            if(v[curr_i]>v[j]){
                curr_i=j;
            }
        }   
        
        int temp=v[curr_i];
        v[curr_i]=v[i];
        v[i]=temp;
    
    }
    
    cout<<"\nPrinting after sorting: ";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }

    return 0;
}
