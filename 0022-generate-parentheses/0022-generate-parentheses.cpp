class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
         f(ans,"" , 0 , 0,n);
         return ans;
    }
    void f( vector<string>&ans, string curr ,int o , int c,int  n){
        if(curr.length() == 2*n){
            ans.push_back(curr);
        }
        if(o<n){
            f(ans,curr + "(", o+1 , c, n);
        }
        if(c<o){
            f(ans , curr + ")" , o ,c+1 ,n);
        }
        return ;
    }
};