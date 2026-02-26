class Solution {
public:
    int minOperations(vector<int>& nums) {
        if(nums.empty())return 0;
        stack<int> st;
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            while(!st.empty() && (st.top()>nums[i])){
                st.pop();
                ans++;
            }
            if(nums[i]>0 && (st.empty() ||  st.top()!=nums[i]))st.push(nums[i]);
        }
        while(!st.empty()){
            ans++;
            st.pop();
        }
        return ans;
    }
};