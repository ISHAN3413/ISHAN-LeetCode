class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n  = nums.size();
        vector<int> dp(n+1 , -1);
        int ans = 0;
        for(int i = 0;i<n-3+1 ; i++){
            ans+=f(nums , i ,dp);
        }
        return ans;
    }
    int f(vector<int>& nums , int i ,vector<int>&dp){
        if(i+2 >= nums.size()){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        if((nums[i+1] - nums[i]) != (nums[i+2] - nums[i+1]))return 0;

        else return dp[i] = (1 + f(nums , i+1,dp));
    }
};