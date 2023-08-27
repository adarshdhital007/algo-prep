#include<bits/stdc++.h>
using namespace std;

int lcs2(string str1,string str2,int m, int n){
    vector<vector<int>>dp(m+1,vector<int>(n+1));
    int i, j;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(str1[i-1]==str2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}
int main(){
    int m,n;
    string str1="",str2="";
    cin>>m;
    int temp;
    for(size_t i=0;i<m;i++){
        cin>>temp;
        str1+=temp;
    }
    cin>>n;
    for(size_t i=0;i<n;i++){
        cin>>temp;
        str2+=temp;
    }
    cout<<lcs2(str1,str2,m,n)<<'\n';
    return 0;
}
