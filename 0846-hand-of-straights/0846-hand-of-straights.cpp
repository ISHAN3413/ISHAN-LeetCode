class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int g) {
        int n = hand.size();
        if(n%g !=0 )return false;
        sort(hand.begin(),hand.end());
        unordered_map<int,int> mp;
        for(int i:hand)mp[i]++;
        for(int i :hand){
            if(mp[i]==0)continue;
            for(int j = 0;j<g;j++){
                if(mp[i+j]>0){
                    mp[i+j]--;
                }
                else return false;
            }
        }
        return true;
    }
};