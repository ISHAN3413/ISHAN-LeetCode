class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int k=0;
        while(nums1.size()!=m){
            nums1.pop_back();
        }
         while(nums2.size()!=n){
            nums2.pop_back();
        }
        for(int i=0;i<n;i++){
            nums1.push_back(nums2[i]);
        }
         for(int i=0;i<nums1.size();i++){
            for(int j=i+1;j<nums1.size();j++){
                if(nums1[j]<nums1[i])std::swap(nums1[i],nums1[j]);
            }
        }
        
    }
};