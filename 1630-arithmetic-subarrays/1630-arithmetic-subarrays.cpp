class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        int n = nums.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1));
        for(int i = 0 ; i<l.size();i++){
            ans.push_back(f(nums , l[i] , r[i] , dp));
        }
        return ans;
    }
    bool f(vector<int>&nums , int l , int r , vector<vector<int>> &dp){
        if(l==r)return false;
        if(dp[l][r]!=-1)return dp[l][r];
        vector<int> a;
        for(int i = l ;i<=r ;i++){
            a.push_back(nums[i]);
        }
        sort(a.begin(), a.end());
        int b = a[1] - a[0];
        for(int i = 2;i<a.size();i++){
            if(a[i]-a[i-1] != b)return dp[l][r] = false;
        }
        return dp[l][r]= true;
    }
};