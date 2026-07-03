class Solution {
public:
    int f(vector<int>&nums , int i,vector<int>&dp){
    if(i<0)return 0; 
    if(i==0)return nums[i];
    if(dp[i]!=-1)return dp[i];
    
    int pick = nums[i]+ f(nums,i-2,dp);
    int notpick = f(nums,i-1,dp);
    return dp[i] = max(pick,notpick);
}
    int deleteAndEarn(vector<int>& nums) {
        int maxi = *max_element(nums.begin() , nums.end());
        vector<int>dp(maxi+1 , -1);
        vector<int> hash(maxi+1 , 0);
        for(int i:nums){
            hash[i]+=i;
        }
        return f(hash,hash.size()-1,dp);
    } 
};
