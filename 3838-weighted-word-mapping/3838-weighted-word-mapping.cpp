class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(int i =0;i<words.size();i++){
            long long a = 0;
            for(int j =0 ;j<words[i].length();j++){
                a = a+weights[words[i][j]-'a'];
            }
            int r=a%26;
            char ch = 'z'-r;
            ans+=ch;
        }
        return ans;
        
    }
};