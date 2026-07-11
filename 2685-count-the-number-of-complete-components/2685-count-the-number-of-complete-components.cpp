class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vector<vector<int>>hash(n);
        unordered_map<string ,int> mp;
        for(int i = 0;i<n;i++){
            hash[i].push_back(i);
        }

        for(const auto &a:edges){
            hash[a[0]].push_back(a[1]);
            hash[a[1]].push_back(a[0]);
        }

        for(int i = 0;i<n;i++){
            vector<int> nei = hash[i];
            sort(nei.begin(),nei.end());

            string key = "";

            for(int j = 0;j<nei.size();j++){
                key = key + to_string(nei[j]) + ",";
            }
            mp[key]++;
        }
        
        for(const auto &a:mp){
            int size = count(a.first.begin() , a.first.end() , ',');
            if(size == a.second)ans++;
        }
        return ans;
    }
};