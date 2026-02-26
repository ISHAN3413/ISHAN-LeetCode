class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        vector<int>h(10001 , 0);
        for(int i = 0;i<nums.size();i++){
            h[nums[i]]++;
            if(h[nums[i]]==(nums.size()/2))return nums[i];
        }
        return 0;
    }
};