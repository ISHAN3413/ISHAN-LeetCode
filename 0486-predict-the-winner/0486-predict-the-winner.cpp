class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(nums,0,nums.size()-1,dp)>=0;
    }
    long f(vector<int>&nums , int i , int j , vector<vector<int>>&dp){
        if(i==j)return nums[i];
        if(dp[i][j]!=-1)return dp[i][j];
        long a = nums[i]-f(nums,i+1,j,dp);
        long b = nums[j]-f(nums,i,j-1,dp);
        return dp[i][j] = max(a,b);
    }
};