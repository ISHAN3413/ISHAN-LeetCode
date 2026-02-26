class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {

        vector<bool> b;
        int k=0;
      for(int i=0;i<nums.size();i++){
        k=(k*2 + nums[i])%5;
        b.push_back(k==0);
      }
      return b;
    }
};