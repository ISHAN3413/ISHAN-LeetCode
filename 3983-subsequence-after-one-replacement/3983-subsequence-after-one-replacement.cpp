class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        if(t.length()<s.length())return false;

        if(t.length()==s.length()){
            int cnt = 0;
            for(int i=0;i<s.length();i++){
                if(s[i]!=t[i])cnt++;
                if(cnt>1)return false;
            }
        }
        return f(s,t,0,0,0);
    }
    bool f(string &s , string &t , int i , int j , int cnt){
        if(i>=s.length() || j>=t.length()){
            if(j==t.length() && i<s.length()){
                return false;
            }
            return true;
        }
if(s[i]!=t[j] && cnt == 1){
        return false;
    }

    bool temp;

    if(s[i]==t[j]){
        temp = f(s,t,i+1,j+1,cnt);
    }
    else{
        temp = (f(s,t,i+1,j+1,1)||f(s,t,i,j+1,cnt));
    }

    return temp;


    }

    
};