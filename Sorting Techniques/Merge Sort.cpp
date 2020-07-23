#include <iostream>
using namespace std;

void merging(int *left,int *right,int *arr,int a,int b){
    int i=0,j=0,k=0;
    
    while(i<a && j<b){
        if(left[i]<right[j]){
            arr[k]=left[i];
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
        }
        
        k++;
    }
    
    while(i<a){
        arr[k]=left[i];
        k++;
        i++;
    }
    while(j<b){
        arr[k]=right[j];
        k++;
        j++;
    }

}


void merge_sort(int *arr,int n){
    
    if(n<2){
        return;
    }
    
    int mid=n/2;
    int left[mid];
    int right[n-mid];
    
    for(int i=0;i<mid;i++){
        left[i]=arr[i];   
    }
    for(int j=0;j<n-mid;j++){
        right[j]=arr[mid+j];
    }
    
    merge_sort(left,mid);
    merge_sort(right,n-mid);
    merging(left,right,arr,mid,n-mid);
    
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
    
    merge_sort(arr,n);
    
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    

    return 0;
}
