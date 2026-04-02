class Solution {
public:
    int numRabbits(vector<int>& a) {
        unordered_map<int,int> mp;
        int ans = 0;
        for(int i = 0;i<a.size();i++){
            mp[a[i]]++;
        }
        for(auto &m:mp){
            if(m.second > m.first+1){
                ans+=(m.second/(m.first+1))*(m.first +1);
                if(m.second%(m.first+1)!=0){
                    
                    ans+=(m.first +1);
                }
            }
            else{
                ans+=m.first+1;
            }
        }
        return ans;
    }
};