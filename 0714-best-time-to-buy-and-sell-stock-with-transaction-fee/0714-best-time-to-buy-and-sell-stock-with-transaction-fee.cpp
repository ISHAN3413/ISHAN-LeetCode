class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int after0 = 0;
        int after1 = 0;
        int curr0 = 0;
        int curr1 = 0;
        for (int ind = n - 1; ind >= 0; ind--) {
           curr1 = max(-prices[ind] + after0,0 +after1);
            curr0 = max(prices[ind]-fee + after1,0 + after0);
            after0 = curr0;
            after1 = curr1;
        }
        return after1;
    }
};