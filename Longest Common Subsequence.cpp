class Solution {
    // Recursion + Memoisation //
    public:

    /* Here i used the shifting of Index logic, instead of that -ve
    index base case, i used 0 as the base case index, but while
    comparing the strings i used ind1-1 and ind2-1 so the real indexes
    are being compared and similarly used dp[m+1][n+1] for the
    memoisation,this will help us for the tabulation point of view*/

    int f(string text1, string text2, int ind1, int ind2, 
    vector<vector<int>> &dp){
        // base case //
        if(ind1==0 || ind2==0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(text1[ind1-1]==text2[ind2-1])
        return dp[ind1][ind2] = 1 + f(text1,text2,ind1-1,ind2-1,dp);
        
        // if the chars does not match //
        return dp[ind1][ind2] = max(f(text1,text2,ind1-1,ind2,dp),f(text1,text2,ind1,ind2-1,dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        //vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        //return f(text1,text2,m,n,dp);

        // tabulation (with shifting Indexes) //
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<=n;i++){
            dp[0][i] = 0;
        }
        for(int i=0;i<=m;i++){
            dp[i][0] = 0;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};
