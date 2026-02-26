class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1e7);
        dp[n-1]=0;
        for(int i=n-1 ;i>=0 ;i--){
            int maxjumps = nums[i];
            for(int j = 1; j<=maxjumps && i+j<n;j++){
                dp[i] = min(dp[i] , 1+dp[i+j]);
            }
        }
        return dp[0];
    }
};