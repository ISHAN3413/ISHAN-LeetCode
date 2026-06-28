class Solution {
public:
    bool ispalin(string s){
        int l = 0;
        int r = s.length()-1;
        while(l<=r){
            if(s[l]!=s[r])return false;
            l++;
            r--;
        }
        return true;
    }
    void gap(string s , vector<string>&part , vector<vector<string>>&ans){
        if(s.size()==0){
            ans.push_back(part);
            return;
        }

        for(int i = 0;i<s.size();i++){
            string p = s.substr(0 , i+1);
            if(ispalin(p)){
                part.push_back(p);
                gap(s.substr(i+1) , part,ans);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> part;
        vector<vector<string>> ans;
        gap(s,part,ans);
        return ans;
    }
};