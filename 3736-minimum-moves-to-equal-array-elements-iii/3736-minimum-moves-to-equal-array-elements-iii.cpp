class Solution {
public:
    int minMoves(vector<int>& nums) {
        int avg = 0;
        for(int i = 0;i<nums.size();i++){
            avg  = max(avg , nums[i]);
        }
        int ans= 0;
        for(int i = 0;i<nums.size();i++){
            ans += avg - nums[i];
        }
        return ans;
    }
};