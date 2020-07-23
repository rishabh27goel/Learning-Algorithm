#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    cout<<"Enter the number of trains: ";
    int n;
    cin>>n;
    
    cout<<"Enter the Arrival and Departure: \n";
    int x;
    // Arrival time
    vector<int> arrival;
    
    // Departure time
    vector<int> depart;
    
    for(int i=0;i<n;i++){
        cin>>x;
        arrival.push_back(x);
        cin>>x;
        depart.push_back(x);
    }
    
    sort(arrival.begin(),arrival.end());
    sort(depart.begin(),depart.end());

    int maxPlat=0,req=0;
    int i=0,j=0;
    while(i<n && j<n){
        
        if(arrival[i]<depart[j]){
            req++;
            i++;
            if(maxPlat<req){
                maxPlat=req;
            }
        }
        else{
            req--;
            j++;
        }
    }
    
    cout<<"\nMaximum platform required: "<<maxPlat;
    
    return 0;
}
