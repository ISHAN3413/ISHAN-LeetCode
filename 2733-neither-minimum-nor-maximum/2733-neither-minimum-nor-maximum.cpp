class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if(nums.size()<3)return -1;
        std::sort(nums.begin(),nums.end(),std::greater<int>());
        nums.pop_back();
        std::reverse(nums.begin(),nums.end());
        nums.pop_back();
        return nums[0];
    }
};