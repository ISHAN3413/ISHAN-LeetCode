class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int a=nums[0];
        int i;
      for( i=1;i<nums.size();i++){
        if(nums[i-1]!=nums[i]-1){
            break;
        }
        a+=nums[i];
      }
      std::sort(nums.begin() , nums.end());
      for(i=0;i<nums.size();i++){
        if(a==nums[i]){
            a++;
        }
      }
      return a;
    }
};