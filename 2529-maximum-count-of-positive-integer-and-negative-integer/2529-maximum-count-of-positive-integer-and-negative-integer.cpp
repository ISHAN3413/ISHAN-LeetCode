class Solution {
public:
    int maximumCount(vector<int>& nums) {
        long long int p=0;
        long long int n=0;
        for(long long int i=0;i<nums.size();i++){
            if(nums[i]<0)n++;
            if(nums[i]>0)p++;
        }
        return max(p,n);
    }
};