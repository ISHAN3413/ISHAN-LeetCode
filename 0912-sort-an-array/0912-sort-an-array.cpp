class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        mergesort(nums , l , r);
        return nums;
    }
    void merge(vector<int>&nums , int left , int mid , int right){
        if(left>=right)return;
        vector<int>temp;
        int l = left;
        int r = mid+1;
        while(l<=mid && r<=right){
            if(nums[l]<=nums[r]){
                temp.push_back(nums[l]);
                l++;
            }
            if(nums[l]>nums[r]){
                temp.push_back(nums[r]);
                r++;
            }
        }
        while(l<=mid){
            temp.push_back(nums[l]);
            l++;
        }
        while(r<=right){
            temp.push_back(nums[r]);
            r++;
        }

        for(int i = left;i<=right;i++){
            nums[i] = temp[i-left];
        }
        return ;
    }
    void mergesort(vector<int>&nums , int l , int r){
        if(l>=r)return;
        int mid = l - (l-r)/2;
        mergesort(nums ,l , mid);
        mergesort(nums,mid+1,r);
        merge(nums,l,mid,r);
        return;
    }
};