class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return f(nums,0,target,0);
    }
    int f(vector<int>& nums , int i,int target,int curr){
        if( i>=nums.size()){
            if(target==curr)return 1;
            else return 0;
        }
        int ans = 0;
        ans+=f(nums,i+1,target,curr-nums[i]);
        ans+=+f(nums,i+1,target,curr+nums[i]);
        return ans;
    }
};