class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        int ans = 0;
        while(nums[i]<0 && k>0){
            nums[i]=-nums[i];
            k--;
            i++;
            if(i>=nums.size())break;
        }
        sort(nums.begin(),nums.end());
        if(nums[0]>=0 && k>0){
            if(k%2!=0)nums[0]=-nums[0];
            k=0;
        }
        for(int i =0;i<nums.size();i++){
            ans+=nums[i];
        }
        return ans;
    }
};