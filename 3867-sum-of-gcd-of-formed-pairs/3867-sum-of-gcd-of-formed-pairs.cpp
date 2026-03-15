class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int>pregcd(nums.size());
        int mx = nums[0];
        for(int i = 0;i<nums.size();i++){
            mx = max(mx , nums[i]);
            pregcd[i] = gcd(mx,nums[i]);
        }
        sort(pregcd.begin(),pregcd.end());
        int left = 0;
        int right = nums.size()-1;
        long long ans = 0;
        while(left<right){
            ans = ans+gcd(pregcd[left],pregcd[right]);
            left++;
            right--;
        }
        return ans;
    }
};