class Solution {
public:
    int modi = 1e9 + 7;
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]>maxi)maxi=nums[i];
        }
        vector<vector<vector<int>>> dp(n +1, vector<vector<int>>(maxi+1,vector<int>(maxi+1,-1)));
        return f(nums,0,0,0,dp);
    }
    int f(vector<int>&nums , int i ,int gcd1 , int gcd2 , vector<vector<vector<int>>> &dp){
        if(i==nums.size()){
            if(gcd1==gcd2 && gcd1 != 0)return 1;
            return 0;
        }
        if(dp[i][gcd1][gcd2]!=-1)return dp[i][gcd1][gcd2];


        long long ans = 0;

        ans+=f(nums,i+1,gcd1,gcd2,dp);

        int ngcd1 = (gcd1==0)?nums[i]:gcd(gcd1,nums[i]);
        ans+=f(nums,i+1,ngcd1,gcd2,dp);

        int ngcd2 = (gcd2==0)?nums[i]:gcd(gcd2,nums[i]);
        ans+=f(nums,i+1,gcd1,ngcd2,dp);

        return dp[i][gcd1][gcd2] = ans%modi;
    }
};