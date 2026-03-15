class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int odd=1;
        int even=0;
        std::vector<int> result(nums.size());
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                result[even]=nums[i];
                even+=2;
                }
                 else{
                result[odd]=nums[i];
                odd+=2;
                }

        }
        return result;
    }
};