class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<vector<int>> mp;
        mp.push_back({1,1});
        int ones = 0;
        for(int i = 0;i<s.length();i++){
            if(s[i]==mp.back()[0]+'0'){
                mp.back()[1]++;
            }
            else{
                mp.push_back({s[i]-'0',1});
            }
            if(s[i]=='1')ones++;
        }
        if(mp.back()[0] == 1)mp.back()[1]++;
        else mp.push_back({1,1});
        int ans = ones;
        for(int i = 1;i+1<mp.size();i++){
            
            if(mp[i][0] ==1 && mp[i-1][0] == 0 && mp[i+1][0]==0){
                int cur = (ones - mp[i][1]) + (mp[i][1] + mp[i-1][1] + mp[i+1][1]);
                ans = max(ans , cur);
            }
        }

        return ans;


    }
};