class Solution {
    public:
    // recursion + memoisation //
    int f(int i, int j, string &word1, string &word2, 
    vector<vector<int>> &dp){
        // base cases //
        if(i==0) return j;
        if(j==0) return i;
        if(dp[i][j]!=-1) return dp[i][j];

        if(word1[i-1]==word2[j-1]){
            return dp[i][j] = 0 + f(i-1,j-1,word1,word2,dp);
        }
        return dp[i][j] = 1 + min(f(i,j-1,word1,word2,dp),
        min(f(i-1,j,word1,word2,dp),f(i-1,j-1,word1,word2,dp)));
    }
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        // vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        // return f(m,n,word1,word2,dp);
        vector<vector<int>> dp(m+1,vector<int>(n+1,1e8)); // with initialising 0 it will also work
        // base case conditions //
        for(int j=0;j<=n;j++){
            dp[0][j] = j;
        }
        for(int i=0;i<=m;i++){
            dp[i][0] = i;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = 0 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
                }
            }
        }
        return dp[m][n];
    }
};
