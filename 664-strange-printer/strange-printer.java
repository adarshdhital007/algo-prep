class Solution {
    public int strangePrinter(String s) {
        int n = s.length();
        int[][] dp = new int[n][n];

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        // fill dp table now
        for(int length=2;length<=n;length++){
            for(int i=0;i<=n-length;i++){
                int j = i + length - 1;


                //case s[i]==s[j]
                if(s.charAt(i)==s.charAt(j)){
                    dp[i][j]=dp[i][j-1];
                }else{
                    dp[i][j]=Integer.MAX_VALUE;
                }

                for(int k=i;k<j;k++){
                    dp[i][j] = Math.min(dp[i][j],dp[i][k]+dp[k+1][j]);
                }
            }
        }
        return dp[0][n-1];
    }
}