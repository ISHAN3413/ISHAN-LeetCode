class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int a = 0;
        int b =0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==1){
                if(a<k && b!=0)return false;
                a=0;
                b = 1;
                
            }
            else a++;
        }
        return true;
    }
};