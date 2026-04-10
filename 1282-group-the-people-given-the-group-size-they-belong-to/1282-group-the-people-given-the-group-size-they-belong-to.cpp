class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        unordered_map<int,vector<int>> mp;
        for(int i =0;i<g.size();i++){
            mp[g[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto &a:mp){
            int b = a.first;
                vector<int> temp;
            for(int i = 0;i<a.second.size();i++){
                temp.push_back(a.second[i]);
                if((i+1) % b == 0){
                    ans.push_back(temp);
                    temp = {};
                }
                
            }
        }
        return ans;
    }
};