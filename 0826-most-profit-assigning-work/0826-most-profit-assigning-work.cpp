class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        int ans = 0;
        vector<pair<int,int>> f;
        for(int i = 0;i<d.size();i++){
            f.push_back({d[i],p[i]});
        }
        sort(f.begin(),f.end());
        sort(w.begin(),w.end());
        int j =0;
        int i =0;
        int maxpro =0;
        while(i<w.size()){
            while(j<f.size() && f[j].first<=w[i]){
                maxpro = max(maxpro,f[j].second);
                j++;
            }
            ans+=maxpro;
            i++;
        }
        return ans;
    }
};