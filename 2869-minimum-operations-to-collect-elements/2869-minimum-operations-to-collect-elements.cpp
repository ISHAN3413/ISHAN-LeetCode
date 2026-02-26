class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        vector<int> hash(k+1 , 0);
        int a = 0;
        for(int i = nums.size() -1;i>=0;i-- ){
            if(a==k)break;
            if(nums[i]<=k){
            if(hash[nums[i]]==0)a++;
             hash[nums[i]]++;   
            }
            ans++;
        }
        return ans;
    }
};