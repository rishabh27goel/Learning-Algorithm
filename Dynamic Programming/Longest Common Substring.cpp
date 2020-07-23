#include <iostream>
#include <string.h>
using namespace std;

int long_substring(string x,string y){
    int max=0;
    int grid[200][200];
    int start,end;
    
    for(int i=0;i<=x.size();i++){
        
        for(int j=0;j<=y.size();j++){
            
            if(i==0 || j==0){
                
                grid[i][j]==0;
            }
            else if(x[i-1]==y[j-1]){
                
                grid[i][j]=grid[i-1][j-1]+1;   
            }
            else{
                grid[i][j]=0;
            }
            
            if(grid[i][j]>max){
                start=i;
                end=j;
                max=grid[i][j];
                
            }
        }
        
        for(int j=0;j<=y.size();j++){
            
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    
    for(int i=0;i<=y.size();i++){
        if(grid[start-i][end-i]==1){
            start=start-i;
            end=end-i;
            break;
        }
    }
    
    cout<<"\nLongest String is: ";
    cout<<x.substr(start-1,max);
    
    
    return max;
}

int main()
{
    string str1,str2;
    cout<<"Enter the 1st string: ";
    cin>>str1;
    
    cout<<"Enter the 2nd string: ";
    cin>>str2;
    
    // Longest Common Substring
   
    int result=long_substring(str1,str2);
    cout<<"\nLength of longest common substring: ";
    cout<<result;
    

    return 0;
}
