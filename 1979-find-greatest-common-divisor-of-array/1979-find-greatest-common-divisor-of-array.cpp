class Solution {
public:
    int findGCD(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        return gcd(nums[0],nums[nums.size()-1]);        
    }
};