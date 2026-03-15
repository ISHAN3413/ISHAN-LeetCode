class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2)return nums.size();
        int u=2;
        for(int i=2;i<nums.size();i++){
            if(nums[i]!=nums[u-2]){
                nums[u]=nums[i];
                u++;
            }
           
        }
    return u;
    }
};