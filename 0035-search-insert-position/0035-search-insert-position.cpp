class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        int mid;
        while(start<=end){
            mid=(end+start)/2;
            if(nums[mid]<target){
                //  if(nums[mid]+1==target)return {mid+1};
                // else 
                start=mid+1;
            }
            else if(nums[mid]>target){
                //  if(nums[mid]-1==target)return {mid-1};
                // else
                 end=mid-1;
            }
            else{
                return mid;
            }
        }
        //start=mid+1;
        return start;
    }
};