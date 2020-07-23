#include <iostream>
#include <vector>
using namespace std;

int maxFind(int a,int b){
    if(a>=b){
        return a;
    }
    else{
        return b;
    }
}

int main()
{
    
    int n;
    cout<<"Enter the number of items: ";
    cin>>n;
    
    int x;
    vector<int> profit;
    profit.push_back(0);
    
    vector<int> weight;
    weight.push_back(0);
    cout<<"Enter the value weight and profit :";
    
    for(int i=0;i<n;i++){
        cin>>x;
        weight.push_back(x);
        cin>>x;
        profit.push_back(x);

    }
    
    int sum;
    cout<<"Enter the total weight of bag: ";
    cin>>sum;
    
    int grid[n+1][sum+1];
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0 || j==0){
                grid[i][j]=0;
            }
            else if(weight[i]<=j){
                grid[i][j]=maxFind(grid[i-1][j],profit[i]+grid[i-1][j-weight[i]]);
            }
            else{
                grid[i][j]=grid[i-1][j];
            }
        }
    }
    
    cout<<"\nOutput grid: \n";
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<"\nMaximum profit: ";
    cout<<grid[n][sum];

    return 0;
}
