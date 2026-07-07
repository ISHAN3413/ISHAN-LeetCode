class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        if(s.length()>t.length())return false;
        if(s.length()==t.length()){
            int j=0;
            bool cnt = false;
            while(j<t.length()){
                if(s[j]==t[j])j++;
                else {
                    if(!cnt){
                        cnt = true;
                        j++;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        //vector<vector<vector<int>>>dp(s.length(),vector<vector<int>>(t.length(),vector<int>(3 , -1)));
        return f(s,t,0,0,0);
    }

    bool f(string &s , string &t , int i , int j , int cnt){
        if(i>=s.length()){
            return true;
        }
        if(j>=t.length()){
            return false;
        }
        // if(dp[i][j][cnt]!=-1)return dp[i][j][cnt];
        if(s[i]!=t[j] && cnt == 1){
        return false;
    }
        bool ans = false;
        if(s[i]==t[j]){
            ans=f(s,t,i+1,j+1,cnt);
        }
        else{
            if(cnt == 1){
                ans=f(s,t,i,j+1,cnt);
            }
            else{
                ans=(f(s,t,i+1,j+1,cnt+1) || f(s,t,i,j+1,cnt));
            } 
        }
        return ans;
    }
};