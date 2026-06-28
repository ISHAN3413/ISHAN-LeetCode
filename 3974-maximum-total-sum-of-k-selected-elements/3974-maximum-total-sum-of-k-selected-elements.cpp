class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end(),[](int &a , int &b){
            return a>b;
        });
        long long ans = 0;
        for(int i = 0;i<nums.size();i++){
            if(k==0)break;
            if(mul>0){
                long long b = (1LL*mul*nums[i]);
                ans+=b;
                mul--;
            }
            else{
                ans+=nums[i];
            }
            k--;
        }
        return ans;
    }
};