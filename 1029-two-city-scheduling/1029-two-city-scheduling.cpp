class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),[](auto &a , auto &b){
            return (a[0]-a[1])<(b[0]-b[1]);
        });

        int ans = 0;
        int n = costs.size();
        n=n/2;
        for(int i = 0;i<n ;i++){
            ans+=costs[i][0];
            ans+=costs[i+n][1];
        }
        return ans;
    }
};