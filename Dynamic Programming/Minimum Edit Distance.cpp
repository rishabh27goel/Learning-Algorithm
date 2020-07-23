#include <iostream>
using namespace std;

int find_min(int a,int b,int c){
    
    return a>b ? ( c>b ? b : c ) : ( c>a ? a : c) ;
}

int edit_distance(string a,string b){
    
    int grid[200][200];
    
    for(int i=0;i<=a.size();i++){
        
        for(int j=0;j<=b.size();j++){
            
            if(i==0){
                
                grid[i][j]=j;
            }
            else if(j==0){
                
                grid[i][j]=i;
            }
            else if(a[i-1] == b[j-1]){
                
                grid[i][j] = grid[i-1][j-1];   
            }
            else{
                
                grid[i][j] = find_min( grid[i-1][j] , grid[i][j-1] , grid[i-1][j-1] ) + 1;
            }
            
        }
    }
    
    for(int i=0;i<=a.size();i++){
        
        for(int j=0;j<=b.size();j++){
        
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return grid[a.size()][b.size()];
}

int main()
{
    string str1,str2;
    cout<<"Enter the 1st string: ";
    cin>>str1;

    cout<<"Enter the 2nd string: ";
    cin>>str2;
    
    
    int result=edit_distance(str1,str2);
    cout<<"Minimum edit distance: ";
    cout<<result;
    return 0;
}
