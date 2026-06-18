class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
         vector<int>dp(target+1,-1);
        return f(nums,target,dp);
    }
    int f(vector<int>& nums, int target , vector<int>&dp){
        if(target==0)return 1;
        if(dp[target]!=-1)return dp[target];
        int a = 0;
        for(int j=0;j<nums.size();j++){
            if(target>=nums[j]){
                a+=f(nums,target-nums[j],dp);
            }
        }
        return dp[target] = a;
    }
};