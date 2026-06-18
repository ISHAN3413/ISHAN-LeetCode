class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n , vector<int>(target,-1));
        return f(nums,target,0,0,dp);
    }
    int f(vector<int>& nums, int target , int i , int sum , vector<vector<int>>&dp){
        if(sum==target)return 1;
        if(sum>target)return 0;
        if(i>=nums.size())return 0;
        if(dp[i][sum]!=-1)return dp[i][sum];
        int a = 0;
        for(int j=0;j<nums.size();j++){
            a+=f(nums,target,j,sum+nums[j],dp);
        }
        return dp[i][sum] = a;
    }
};