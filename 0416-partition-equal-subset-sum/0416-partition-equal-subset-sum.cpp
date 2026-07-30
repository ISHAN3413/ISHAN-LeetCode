class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i:nums)sum+=i;
        if(sum%2 !=0)return false;
        sum=sum/2;
        vector<vector<int>> dp(sum+1,vector<int>(nums.size()+1,-1));
        return f(nums,sum,0,dp);
    }
    bool f(vector<int>&nums , int n , int i,vector<vector<int>>&dp){
        if(n==0)return true; 
        if(i>=nums.size()||n<0)return false;
        
        if(dp[n][i]!=-1)return dp[n][i];
       
        
        return dp[n][i] = (f(nums,n-nums[i],i+1,dp) || f(nums,n,i+1,dp));
    }
};