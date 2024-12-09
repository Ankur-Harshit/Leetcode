class Solution {
    int findLCS(string s, string t){
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }

    /* here in this question, only delete operation we can perform,
    so find the LCS part that would be the equal part in both the
    strings and delete the other remainig char from both the strings
    */
    
public:
    int minDistance(string word1, string word2) {
        int lcs = findLCS(word1,word2);
        int m = word1.size();
        int n = word2.size();
        int s1del = m-lcs;
        int s2del = n-lcs;
        return s1del + s2del;
    }
};
