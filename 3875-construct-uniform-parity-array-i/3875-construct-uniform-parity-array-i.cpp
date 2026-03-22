class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd=0;
        int even = 0;
        for(int i = 0;i<nums1.size();i++){
            if(nums1[i]%2==0)even++;
            else odd++;
        }
        bool iseven = ((odd==0) || (odd>=2));
        bool isodd = (odd>=1);
        return iseven||isodd;
    }
};