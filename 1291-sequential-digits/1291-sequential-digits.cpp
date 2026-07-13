class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
       vector<int> nums = {12,23,34,45,56,67,78,89};
       int i = 0;
       while(i<36){
        int n = nums[i]%10;
        if(n==9){
            i++;
            continue;
        }
        int num = nums[i]*10 + n +1;
        if(num>high)break;
        nums.push_back(num);
        i++;
       }
       vector<int> ans;
       for(int a:nums){
        if(a>=low && a<=high)ans.push_back(a);
       }
       return ans;
    }
};