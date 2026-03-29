class Solution {
public:
    void wiggleSort(vector<int>& nums) {
       vector<int> ans = nums;
       sort(ans.begin(),ans.end(),[](int &a , int &b){
        return a>b;
       });
       int j=0;
        for(int i =1;i<nums.size();i=i+2){
            nums[i] = ans[j++];
        }
        for(int i =0;i<nums.size();i=i+2){
            nums[i] = ans[j++];
        }
    }
};