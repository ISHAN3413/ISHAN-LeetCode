class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        return f(nums,0,nums.size()-1)>=0;
    }
    long f(vector<int>&nums , int i , int j){
        if(i==j)return nums[i];
        long a = nums[i]-f(nums,i+1,j);
        long b = nums[j]-f(nums,i,j-1);
        return max(a,b);
    }
};