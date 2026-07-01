class Solution {
public:
    int offset;
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int s:nums)sum+=s;
        offset = sum;
        vector<vector<int>> dp(n,vector<int>(2*sum +1 , -1));
        return f(nums,0,target,0 ,dp);
    }
    int f(vector<int>& nums , int i,int target,int curr,vector<vector<int>>&dp){
        if( i>=nums.size()){
            if(target==curr)return 1;
            else return 0;
        }
        if(dp[i][curr+offset]!=-1)return dp[i][curr+offset];
        int ans = 0;
        ans+=f(nums,i+1,target,curr-nums[i],dp);
        ans+=+f(nums,i+1,target,curr+nums[i],dp);
        return dp[i][curr+offset] = ans;
    }
};