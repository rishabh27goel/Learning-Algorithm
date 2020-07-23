#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

long marc_cake(vector<int> calorie) {
    long miles=0;

    sort(calorie.begin(),calorie.end(),greater<int>());

    for(int i=0;i<calorie.size();i++){
        long double num=pow(2,i);
        miles=miles+(calorie[i]*long(num));
    }

    return miles;
}

int main()
{
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    
    cout<<"Enter the calorie array: ";
    vector<int> calorie;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        calorie.push_back(x);
    }
    
    long total=marc_cake(calorie);
    cout<<"Total miles : "<<total;

    return 0;
}
