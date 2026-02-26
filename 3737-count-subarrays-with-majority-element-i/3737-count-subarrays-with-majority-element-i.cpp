class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans = 0;
        int j;
        for(int i = 0; i<nums.size();i++){
            int tar = 0;
            int a=0;
            for( j=i;j<nums.size();j++){
                a++;
              if(nums[j]==target)tar++;
              if(tar>(a/2))ans++;   
            }  
        }
        return ans;
    }
};

