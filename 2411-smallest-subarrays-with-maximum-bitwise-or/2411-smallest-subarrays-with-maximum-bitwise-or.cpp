class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n , 1);

        for(int i = 0;i<n;i++){
            ans[i] = 1;
            int j = i-1;
            while(j>=0 && (nums[j]|nums[i])!=nums[j]){
                ans[j]=i-j+1;
                nums[j]|=nums[i];
                j--;

            }
        }
        return ans;
    }
};