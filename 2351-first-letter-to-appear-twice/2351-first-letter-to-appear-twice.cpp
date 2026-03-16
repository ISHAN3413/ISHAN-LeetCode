class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<int,int> m;
        vector<int> key(26,0);
        for(int i=0;i<s.length();i++){
            key[s[i]-'a']++;
            if(key[s[i]-'a']==2)return s[i];
        }
        return 'b';
    }
};