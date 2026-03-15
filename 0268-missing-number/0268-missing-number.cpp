class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int k=0;
        int c=0;
        int a=0;
        for(int i=0;i<nums.size();i++){
            k=k+1;
            c=c+k;
        }
        for(int i=0;i<nums.size();i++){
            a=a+nums[i];
        }
        return {c-a};
    }
};