// for memoisation  + recursion //
    int f(vector<int> &val, vector<int> &wt, int index, int W, vector<vector<int>> &dp){
        // base cases //
        if(index == 0){
            if(wt[index]<=W) return val[index];
            return 0;
        }
        if(dp[index][W]!=-1) return dp[index][W];
        int notpick = f(val,wt,index-1,W,dp);
        int pick = INT_MIN;
        if(wt[index]<=W) pick = val[index] + f(val,wt,index-1,W-wt[index],dp);
        return dp[index][W] = max(pick,notpick);
    }
  public:
    // Function to return max value that can be put in knapsack of capacity.
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<int> prev(capacity+1,0); //curr(capacity+1,0);
        // base case writing //
        for(int i=wt[0];i<=capacity;i++){
            prev[i] = val[0];
        }
        for(int index=1;index<n;index++){
            for(int W=capacity;W>0;W--){
                int notpick = prev[W];
                int pick = INT_MIN;
                if(wt[index]<=W)
                pick = val[index] + prev[W-wt[index]];
                prev[W] = max(pick,notpick);
            }
            //prev = curr;
        }
        return prev[capacity];
    }
