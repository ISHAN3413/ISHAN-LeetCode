class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
     long long sum = 0;
     long long f0 = 0;
     for(int i : nums)sum+=i;
     for(int i = 0;i <nums.size();i++){
        f0+=(i*nums[i]);
     }  

     long long maxi = f0;

     for(int  k =1;k<nums.size();k++ ){
        int mn = nums[nums.size()-k];
        f0=f0+sum-(nums.size() * mn);
        maxi = max(maxi,f0);

     }
     return maxi;

    }
};