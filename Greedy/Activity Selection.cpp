#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(vector<int> a,vector<int> b){
    if(a[1]>b[1]){
        
        int temp;
        temp=a[0];
        a[0]=b[0];
        b[0]=temp;
        
        return 0;
    }
    else{
        return 1;
    }
}

int main()
{
    int n;
    cout<<"Number of jobs: ";
    cin>>n;
    
    vector<vector<int>> job(n);
    
    int a,b;
    cout<<"Enter the arrival and departure time: ";
    for(int i=0;i<n;i++){
        
        cin>>a>>b;
        job[i].push_back(a);
        job[i].push_back(b);
    }
    
    // Sorting the vector 
    sort(job.begin(),job.end(),compare);
    
    for(auto row : job){
        for(auto col : row){
            cout<<col<<" ";
        }
        cout<<endl;
    }
    
    int count=1,j=0;
    for(int i=0;i<n;i++){
        if(job[i][0]>=job[j][1]){
            count++;
            j=i;
        }
    }
    
    cout<<"\nMaximum number of jobs: "<<count;
    return 0;
}
