class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return f(nums,0,0);
    }
    int f(vector<int>&nums , int i , int xr){
        if(i==nums.size()){
            return xr;
        }
        return f(nums,i+1,xr^nums[i])+f(nums,i+1,xr);
    }
};