class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> val;
        vector<int> ind;
        vector<int> arr;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                val.push_back(nums[i]);
                ind.push_back(i);
            }
        }
        if(val.size()==0)return nums;
        k = k%(val.size());
        rotate(val.begin(),val.begin()+k,val.end());
        for(int i = 0;i<val.size();i++){
            nums[ind[i]] = val[i];
        }
        return nums;
    }
};