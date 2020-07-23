#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(vector<int> a,vector<int> b){
    if(a[1]>b[1]){
        int temp=a[0];
        a[0]=b[0];
        b[0]=temp;
        return 1;
    }
    else
        return 0;
}

int main()
{
    int n;
    cout<<"Enter the number of jobs: ";
    cin>>n;
    
    int x;
    int max=0;
    vector<vector<int>> job(n);
    cout<<"Enter the deadline: ";
    for(int i=0;i<n;i++){
        cin>>x;
        job[i].push_back(x);
        if(max<x){
            max=x;
        }
    }
    cout<<"Enter the profit for the deadline: ";
    for(int i=0;i<n;i++){
        cin>>x;
        job[i].push_back(x);
    }
    
    // Sorting the job vector according to deadline
    sort(job.begin(),job.end(),compare);
    
    for(auto row:job){
        cout<<row[0]<<" "<<row[1]<<endl;
    }
    
    vector<int> pos(max);
    for(int i=0;i<n;i++){
        if(pos[job[i][0]-1]==0){
            pos[job[i][0]-1]=job[i][1];
        }
        else{
            for(int j=job[i][0]-1;j>=0;j--){
                if(pos[j]<job[i][1]){
                    pos[j]=job[i][1];
                    break;
                }
            }
        }
    }
    
    long int add=0;
    for(int i=0;i<max;i++){
        add=add+pos[i];
    }
    
    cout<<"\nOrder of gantt chart :\n";
    for(int i=0;i<max;i++){
        cout<<pos[i]<<" ";
    }
    
    cout<<"\nMaximum profit: ";
    cout<<add;
    return 0;
}
