class Solution {
public:
    int findKthLargest(vector<int>& a, int k) {
       std::sort(a.begin(), a.end(), std::greater<int>());
        return a[k-1];

    }
};