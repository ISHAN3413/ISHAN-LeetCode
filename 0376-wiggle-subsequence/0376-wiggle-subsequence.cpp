class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2)return nums.size();
        int l =1 , r=1;
        for(int i = 1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                l = r+1;
            }
            else if(nums[i-1]<nums[i]){
                r=l+1;
            }
        }
        return max(l,r);
    }
};