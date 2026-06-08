class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // int ans = INT_MIN;
        // int n = nums.size();
        // vector<int> dp(n+1 , -1);
        // for(int i = 0;i<nums.size();i++){
        //     ans=max(ans , f(nums , dp,i));
        // }
        // return ans;
        int curr = nums[0];
        int ans = nums[0];
        for(int i = 1 ; i<nums.size() ; i++){
            curr = max(nums[i] ,curr+nums[i]);
            ans = max(ans , curr);
        }
        return ans;
    }
    int f(vector<int>& nums , vector<int>&dp ,int i){
        if(i ==0) return nums[0];
        if(dp[i]!=-1)return dp[i];
        return dp[i] = max(nums[i] , nums[i] + f(nums ,dp , i-1));
    }
};