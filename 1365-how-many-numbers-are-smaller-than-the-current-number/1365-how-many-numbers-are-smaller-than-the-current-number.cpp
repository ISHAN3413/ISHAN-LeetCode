class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int maxi=*std::max_element(nums.begin(),nums.end());
        vector<int> hash(maxi+1,0);
        vector<int> ans(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        for (int j = 1; j <= maxi; j++) {
            hash[j] += hash[j - 1];
        }
        for(int i=0;i<nums.size();i++){
           ans[i] = nums[i] > 0 ? hash[nums[i] - 1] : 0;
        }
        return ans;
    }
};