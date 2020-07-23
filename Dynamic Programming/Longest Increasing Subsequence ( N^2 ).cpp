#include <iostream>
using namespace std;

int incr_subseq(int arr[],int n){
    
    int list[n];
    
    list[0]=1;
    cout<<"\nFinal List Values (After Dynamic): ";
    cout<<list[0]<<" ";
    
    for(int i=1;i<n;i++){
        
        list[i]=1;
        
        for(int j=0;j<i;j++){
            
            if(arr[j]<arr[i] && list[i]<list[j]+1){
                
                list[i] = list[j] + 1 ;
            } 
        }
        
        cout<<list[i]<<" ";
        
    }
    cout<<endl;
    
    int max=0;
    for(int i=0;i<n;i++){
        if(list[i]>max){
            max=list[i];
        }
    }
    
    return max;
}

int main()
{
    int n;
    
    cout<<"Enter the size of the array: ";
    cin>>n;
    
    int arr[n];
    cout<<"Enter the array elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int result=incr_subseq(arr,n);
    cout<<"Longest Increasing Subsequence is:";
    cout<<result;
    
    
    
    return 0;
}