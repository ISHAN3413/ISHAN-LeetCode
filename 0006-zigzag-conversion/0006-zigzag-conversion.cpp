class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        if(numRows<=1 || numRows>=n)return s;
       vector<string> rows( min (int(s.length()) , numRows));
       int curr = 0;
       bool gd = false;
       for(char c:s){
            rows[curr]+=c;
            if(curr == 0 || curr == numRows-1){
                gd=!gd;
            }
            curr+= gd?1:-1;
       }
       string ans = "";
       for(string c:rows){
        ans+=c;
       }
        return ans;
    }
};