class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 1;
        int a=1;
        for(int i= 1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                 a++;  
                ans = max(ans , a);
             
            }
            
            else {
                
                a=1;
            }
        }
        return ans;

    }
};