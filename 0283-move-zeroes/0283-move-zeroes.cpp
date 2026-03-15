class Solution {
public:
    void moveZeroes(vector<int>& nums) {       
        vector<int> a;
       
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0)a.push_back(nums[i]);
        }
        int b=a.size();
        for(int i=0;i<nums.size()-b;i++){
            a.push_back(0);
        }
        nums=a;
    }
};