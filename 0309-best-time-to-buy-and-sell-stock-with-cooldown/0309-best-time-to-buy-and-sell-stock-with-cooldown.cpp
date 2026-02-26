class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> after(2,0), curr(2,0), after2(2,0);
        for (int ind = n - 1; ind >= 0; ind--) {
            curr[1] = max(-prices[ind] + after[0],0 +after[1]);
            curr[0] = max(prices[ind] + after2[1],0 + after[0]);
            after2 = after;
            after = curr;
        }
        return after[1];
    }
};