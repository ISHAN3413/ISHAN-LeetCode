class Solution {
public:
    bool h(int n, int k, vector<int>& arr) {
        vector<bool> prev(k + 1, false), curr(k + 1, false);
        prev[0] = true;
        if (arr[0] <= k) prev[arr[0]] = true;

        for (int i = 1; i < n; i++) {
            curr[0] = true;
            for (int target = 1; target <= k; target++) {
                bool notTake = prev[target];
                bool take = false;
                if (arr[i] <= target) take = prev[target - arr[i]];
                curr[target] = take || notTake;
            }
            prev = curr;
        }
        return prev[k];
    }

    bool canPartition(vector<int>& nums) {
        int tos = 0;
        for (int num : nums) tos += num;
        if (tos % 2 != 0) return false;
        return h(nums.size(), tos / 2, nums);
    }
};
