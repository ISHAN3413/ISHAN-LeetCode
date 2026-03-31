class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> n = nums;
        sort(n.begin() , n.end());
        int start = INT_MAX;
        int end = INT_MAX;
        bool flag = true;
        for(int i = 0;i<n.size();i++){
            if(n[i]!=nums[i]){
                if(flag)start = i;
                flag = false;
                end = i;
            }
        }
        if(start == INT_MAX)return 0;
        return end-start+1;

    }
};