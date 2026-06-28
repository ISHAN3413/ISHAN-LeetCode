class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& os, int fs, int fe) {
        vector<vector<int>> ans;
        sort(os.begin(),os.end(),[](auto &a, auto &b){
            if(a[0]==b[0]){
                return a[1]<b[1];
            }
            return a[0]<b[0];
        });
        vector<int> t(2);
        t[0] = os[0][0];
        t[1] = os[0][1];
        for(int i= 1 ;i<os.size();i++){
            if(os[i][0]<=(t[1]+1) ){
                t[1] = max(os[i][1],t[1]);
            }
            else{
                ans.push_back(t);
                t[0] = os[i][0];
                t[1] = os[i][1];
            }
        }
        ans.push_back(t);
        vector<vector<int>> result;
        for(int i = 0;i<ans.size();i++){
            int l = ans[i][0];
            int r = ans[i][1];
            if(r<fs || l>fe ){
                result.push_back(ans[i]);
            }
            else if(l>=fs && r<=fe){
                continue;
            }
            else if(r<=fe && l<fs){
                result.push_back({l , fs-1});
            }
            else if(l>=fs && r>fe){
                result.push_back({fe+1 , r});
            }
            else{
                result.push_back({l , fs-1});
                result.push_back({fe+1 , r});
            }
            
        }
        return result;
    }
};