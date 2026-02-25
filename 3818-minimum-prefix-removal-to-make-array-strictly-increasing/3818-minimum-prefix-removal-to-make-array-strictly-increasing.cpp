class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int ans = 0;
        for(int i =1;i<nums.size();i++){
            if(nums[i-1]>=nums[i])ans=i;
        }
        return ans ;
    }
};