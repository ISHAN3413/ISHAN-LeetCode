class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        vector<int> hash(101 , 0);
        hash[nums[0]]++;
        for(int i = 1 ; i<nums.size() ; i++){
            if(nums[i-1] != nums[i]){
            hash[nums[i]]++;
            }
        }
        int ans = 0;
        for(int i = 1 ;i<101;i++){
            if(hash[i]==1)ans++;
        }
        return ans;
    }
};