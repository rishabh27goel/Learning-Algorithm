#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter value of n: ";
    cin>>n;
    
    int arr[n+1];
    arr[0]=1;
    arr[1]=1;
    for(int i=2;i<=n;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    
    cout<<"No. of possible ways to run up: "<<arr[n];
    return 0;
}
