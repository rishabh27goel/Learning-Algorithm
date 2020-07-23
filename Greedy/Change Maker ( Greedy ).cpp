#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
    cout<<"Enter the number of coins array: ";
    int n;
    cin>>n;
    
    cout<<"Enter the list of coins: ";
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    
    int amount;
    cout<<"Enter the amount: ";
    cin>>amount;
    
    // Sorting the coins list
    sort(coins.begin(),coins.end(),greater<int>());
    
    // Counting the minimum number of coins
    int count=0;
    cout<<"Minimum number of coins: \n";
    if(amount<coins[coins.size()-1]){
        count=0;
        cout<<"Not valid amount";
    }
    else{
        int i=0;
        int num,rem;
        while(amount!=0){
            
            num=amount/coins[i];
            rem=amount%coins[i];
            amount=rem;
            count += num;
            cout<<coins[i]<<" : "<<num<<endl;
            i++;
        }
        cout<<"Total coins : "<<count;
        
    }
    
    return 0;
}
