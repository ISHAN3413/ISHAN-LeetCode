class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> a = {nums[0]};
        vector<int> b = {nums[1]};
        for(int i=2;i<nums.size();i++){
            int m = a.size()-1 , n =b.size()-1;
            if(a[m]>b[n]){
                a.push_back(nums[i]);
            }
            else{
                b.push_back(nums[i]); 
            } 
        }
        for(int i=0;i<b.size();i++){
            a.push_back(b[i]);
        }
        return a;
    }
};