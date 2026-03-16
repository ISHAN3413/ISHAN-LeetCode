class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())return "";
        string c = strs[0] ;
        string ans;
        for(int i=1;i<strs.size();i++){
            if(strs[i].length()<c.length()){
                c= strs[i];
            }
        }
        for(int j=0 ; j<c.length();j++){
            char ch = c[j];
            for(int i = 0;i<strs.size();i++){
                if(strs[i][j] != ch){
                    return ans;
                }
            }
             ans.push_back(ch);
        }
        return ans;
    }
};