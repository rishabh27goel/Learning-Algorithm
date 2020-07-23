#include <iostream>
#include <vector>
using namespace std;

int minimumSwaps(vector<int> arr) {
    int count=0;
    for(int i=0;i<arr.size();i++){
        while(arr[arr[i]-1]!=arr[i]){
            swap(arr[arr[i]-1],arr[i]);
            count++;
        }
    }
    return count;
}

int main()
{
    vector<int> v;
    cout<<"Enter the number of elements: ";
    int n;
    cin>>n;
    
    cout<<"Enter the elements: ";
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    
    int swap=minimumSwaps(v);
    cout<<"\nMinimum number of swaps: "<<swap;
    

    return 0;
}
