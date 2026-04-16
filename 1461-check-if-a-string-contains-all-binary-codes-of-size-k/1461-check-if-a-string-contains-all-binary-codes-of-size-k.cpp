class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        int t = 1<<k;
        if(s.length()<=k)return false;
        unordered_map<string , int> mp;
        for(int i = 0;i<n-k+1 ;i++){
            string a = s.substr(i , k);
            mp[a]++;
        }
        return mp.size() == t;
    }
};