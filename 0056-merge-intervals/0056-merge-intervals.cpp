class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        vector<pair<int,int>> h;
        for(int i = 0;i<inter.size();i++){
            h.push_back({inter[i][0] , i+1});
            h.push_back({inter[i][1] , -i-1});
        }
        sort(h.begin() , h.end() , [](auto &a , auto&b){
            if(a.first==b.first){
                return a.second>b.second;
            }
            return a.first<b.first;
        });
        vector<vector<int>> ans;
        int ai = 0;
        int si = h[0].first;
        for(int i = 0;i<h.size();i++){
            if(h[i].second>0){
                if(ai == 0){
                    si=h[i].first;
                }
                ai++;
            }
            else{
                ai--;
            }

            if(ai == 0){
                ans.push_back({si , h[i].first});
            }
        }
        return ans;
    }
};