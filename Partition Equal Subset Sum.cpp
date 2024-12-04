// the total sum of the array is S, if we can find a subset whose sum
// is S/2 then the other remaining elements will make a subset of sum S/2

class Solution {
    public:
    bool SubsetWithSumK(vector<int> &nums, int k){
        // writing the space optimised code //
        vector<bool> prev(k+1,0),curr(k+1,0);
        int n = nums.size();
        prev[0] = true;
        if(nums[0]<=k)
        prev[nums[0]] = true;
        for(int index=1;index<n;index++){
            for(int target=1;target<=k;target++){
                bool notpick = prev[target];
                bool pick = false;
                if(target>=nums[index])
                pick = prev[target-nums[index]];
                curr[target] = pick | notpick;
            }
            prev = curr;
        }
        return curr[k];
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if((sum & 1)) return false;
        return SubsetWithSumK(nums,sum/2);
    }
};
