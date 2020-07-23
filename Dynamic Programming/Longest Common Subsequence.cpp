#include <iostream>
using namespace std;

int find_max(int a,int b){
    if(a>=b){
        return a;
    }
    else{
        return b;
    }
}

int long_subseq(string x,string y){
    
    int grid[200][200];
    for(int i=0;i<=x.size();i++){
        
        for(int j=0;j<=y.size();j++){
            
            if(i==0 || j==0){
                grid[i][j]=0;
            }
            else if(x[i-1]==y[j-1]){
                grid[i][j]=grid[i-1][j-1]+1;
            }
            else{
                grid[i][j]=find_max(grid[i-1][j],grid[i][j-1]);
            }
            
        }
    }
    
    for(int i=0;i<=x.size();i++){
        for(int j=0;j<=y.size();j++){
            
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    
    int len=grid[x.size()][y.size()];
    int row=x.size();
    int col=y.size();
    char seq[len+1];
    seq[len]='\0';
    
    while(row>0 && col>0){
            
        if(x[row-1]==y[col-1]){
            len--;
            seq[len]=x[row-1];
            row--;
            col--;
            
        }
        else if(grid[row][col-1]<grid[row-1][col]){
            row--;
        }
        else{
            col--;
        }
    }
    
    cout<<"\nSubsequence is :"<<seq;
    return grid[x.size()][y.size()];
}

int main()
{
    string str1,str2;
    cout<<"Enter the 1st String: ";
    cin>>str1;
    
    cout<<"Enter the 2nd String: ";
    cin>>str2;
    
    // Longest Common Subsequence
    int result=long_subseq(str1,str2);
    cout<<"\nLongest Common Subsequence is: ";
    cout<<result;

    return 0;
}
