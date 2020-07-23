#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    
    int x;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    
    int num;
    cin>>num;
    // Sorting the array
    sort(v.begin(),v.end());
    
    int i=0,count=0;
    int j=n-1;
    while(j!=-1 && i!=n){
        if(v[i]+v[j]==num){
            count++;
            i++;
        }
        else if(v[i]+v[j]>num){
            j--;
        }
        else{
            i++;
        }
    }
    
    cout<<count;
    
    return 0;
}
