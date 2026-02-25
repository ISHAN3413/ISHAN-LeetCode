class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i=i+2){
            int n=nums[i];
            while(n!=0){
                ans.push_back(nums[i+1]);
                n--;
            }
        }
        return ans;
    }
};