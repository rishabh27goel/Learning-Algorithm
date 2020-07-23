#include <iostream>
using namespace std;

int partition(int *arr,int start,int end){
    int pivot=arr[end];
    int pIndex=start;
    int temp;
    
    for(int i=start;i<end;i++){
        if(arr[i]<pivot){
            
            temp=arr[i];
            arr[i]=arr[pIndex];
            arr[pIndex]=temp;
            
            pIndex=pIndex+1;
        }
    }
    
    temp=arr[pIndex];
    arr[pIndex]=arr[end];
    arr[end]=temp;
    
    return pIndex;
}

void quick_sort(int *arr,int start,int end){
    int pIndex;
    
    if(start<end){
        pIndex=partition(arr,start,end);
        quick_sort(arr,start,pIndex-1);
        quick_sort(arr,pIndex+1,end);
    }
}

int main()
{
    int n;
    cout<<"Enter the number of elemnets: ";
    cin>>n;
    
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    quick_sort(arr,0,n-1);
    
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    

    return 0;
}
