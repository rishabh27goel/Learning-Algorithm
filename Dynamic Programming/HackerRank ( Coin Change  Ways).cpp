#include <iostream>
#include <vector>
using namespace std;

long getWays(int n,vector<long> c){
    
    int grid[100][100];
    
    for(int i=0;i<=c.size();i++){
        for(int j=0;j<=n;j++){
            if(j==0){
                grid[i][j]=1;
            }
            else if(i==0){
                grid[i][j]=0;
            }
            else if(j>=c[i-1]){
                grid[i][j]=grid[i-1][j]+grid[i][j-c[i-1]];
            }
            else{
                grid[i][j]=grid[i-1][j];
            }
        }   
    }
    
    for(int i=0;i<=c.size();i++){
        for(int j=0;j<=n;j++){
            cout<<grid[i][j]<<" ";
        }   
        cout<<endl;
    }
    
    
    return grid[c.size()][n];
}


int main()
{
    vector<long> coins;
    int amt;
    cout<<"Enter the total amount: ";
    cin>>amt;
    
    int n;
    cout<<"\nEnter the number of coins: ";
    cin>>n;
    
    int x;
    cout<<"\nEnter the coins array: ";
    for(int i=0;i<n;i++){
        cin>>x;
        coins.push_back(x);
    }

    long result=getWays(amt,coins);
    cout<<"\nTotal number of ways are : "<<result;
    return 0;
}
