#include<bits/stdc++.h>
using namespace std;

int lcs3(vector<int>n1,vector<int>n2,vector<int>n3,int p, int q, int r){

    vector<vector<vector<int>>>dp(p+1,vector<vector<int>>(q+1,vector<int>(r+1)));

    for(int i=0;i<=p;i++){
        for(int j=0;j<=q;j++){
            for(int k=0;k<=r;k++){

                if(i==0 || j==0 || k==0){
                    dp[i][j][k]=0;
                    continue;
                }
                else if(n1[i-1]==n2[j-1] && n1[i-1]==n3[k-1]){
                    dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                    continue;
                }
                else{
                    dp[i][j][k]=max(max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);
                 }
            }
         }
    }
    return dp[p][q][r];
}
int main() {

	int p, q, r;
	cin >> p;
	vector<int> n1(p);
	for (int i = 0; i < p; i++)
		cin >> n1[i];

	cin >> q;
	vector<int> n2(q);
	for (int i = 0; i < q; i++) 
		cin >> n2[i];

	cin >> r;
	vector<int> n3(r);
	for (int i = 0; i < r; i++)
		cin >> n3[i];

	cout << lcs3(n1,n2,n3, p, q, r) << endl;
} 
