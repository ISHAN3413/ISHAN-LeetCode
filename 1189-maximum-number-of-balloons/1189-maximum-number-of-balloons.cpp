class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> hash(26);
        for(char c:text){
            hash[c - 'a']++;
        }
        int l = hash['l' - 'a']/2;
        int o = hash['o' - 'a']/2;
        int ans =  min({l,o,hash['b' - 'a'],hash[0],hash['n'-'a']});
        return ans;
    }
};