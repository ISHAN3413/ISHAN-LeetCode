class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxi(n,nums[0]);
        vector<int> mini(n , nums.back());
        for(int  i = 1;i<n ;i++){
            if(nums[i]>maxi[i-1])maxi[i] = nums[i];
            else maxi[i] = maxi[i-1];

            if(nums[n-i-1]<mini[n-i])mini[n-i-1] = nums[n-i-1];
            else mini[n-i-1] = mini[n-i];
        }
        for(int i= 0 ; i < n;i++){
            if(maxi[i]-mini[i] <=k)return i;
        }
        return -1;
    }
};