class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int a[200] = {0};
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            a[nums[i]+k]++;
        }
        for(int i=0;i<nums.size();i++){
            ans+=a[nums[i]];
        }
        return ans;
    }
};