class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1,-1};

        int st = 0;
        int en = nums.size()-1;
        while(st<=en){
            int mid = st + (en-st)/2;
            if(nums[mid] == target){
                ans[0] = mid;
                en = mid-1;
            }
            else if(nums[mid]<target){
                st = mid+1;
            }
            else{
                en = mid-1;
            }
        }
        st = 0;
        en = nums.size()-1;
        while(st<=en){
            int mid = st + (en-st)/2;
            if(nums[mid] == target){
                ans[1] = mid;
                st = mid+1;
            }
            else if(nums[mid]<target){
                st = mid+1;
            }
            else{
                en = mid-1;
            }
        }
        return ans;
    }
};