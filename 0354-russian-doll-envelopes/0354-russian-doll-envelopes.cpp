class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        int n = e.size();
        
        sort(e.begin(), e.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        return solveoptimal(n,e);
        vector<int> curr(n+1 , 0);
        vector<int> next(n+1, 0);
        for (int i = e.size() - 1; i >= 0; i--) {
            for (int pre = i - 1; pre >= -1; pre--) {
                int skip = next[pre+1];
                if ((pre == -1) ||
                    ((e[i][0] > e[pre][0]) && (e[i][1] > e[pre][1]))) {
                    skip = max(skip ,1 +next[i+1]);
                }
                curr[pre+1] = skip;
            }
            next = curr;
        }
        return curr[0];
    }
    int solveoptimal(int n , vector<vector<int>>& e){
        if(n==0)return 0;
        vector<int> ans;
        ans.push_back(e[0][1]);
        for(int i = 1 ; i< n;i++){
            if(e[i][1] > ans.back()){
                ans.push_back(e[i][1]);
            }
            else{
                auto ind = lower_bound(ans.begin() , ans.end() , e[i][1]) ;
              *ind = e[i][1];
            }
        }
        return ans.size();
    }
    int f(int i, int pre, const vector<vector<int>>& e,
          vector<vector<int>>& dp) {
        if (i == e.size())
            return 0;
        if (dp[i][pre + 1] != -1)
            return dp[i][pre + 1];
        int skip = f(i + 1, pre, e, dp);
        int take = 0;
        if ((pre == -1) || ((e[i][0] > e[pre][0]) && (e[i][1] > e[pre][1]))) {
            take = 1 + f(i + 1, i, e, dp);
        }
        return dp[i][pre + 1] = max(take, skip);
    }
};