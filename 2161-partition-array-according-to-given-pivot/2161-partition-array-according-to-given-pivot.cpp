class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> prev;
        vector<int> pres;
        vector<int> fut;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                prev.push_back(nums[i]);
            }
            else if(nums[i]==pivot){
                pres.push_back(nums[i]);
            }
            else{
                fut.push_back(nums[i]);
            }
        }
        prev.insert(prev.end(),pres.begin(),pres.end());
        prev.insert(prev.end(),fut.begin(),fut.end());
        return prev;
    }
};