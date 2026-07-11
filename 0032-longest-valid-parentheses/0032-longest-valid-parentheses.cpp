class Solution {
public:
    int longestValidParentheses(string s) {
        int l = 0, r = 0, m = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                l++;
            if (s[i] == ')')
                r++;
            if (l == r) {
                m = max(m, l + r);
            }
            if (r > l) {
                l = 0;
                r = 0;
            }
        }
        l = 0;
        r = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '(')
                l++;
            else
                r++;
            if (l == r)
                m = max(m, l + r);
            else if (l > r) {
                l = 0;
                r = 0;
            }
        }
        return m;
    }
    // int longestValidParentheses(string s) {
    //    int ans = 0;
    //    int a = 0;
    //    stack<char> st;
    //    for(int i = 0;i<s.length();i++){
    //     if(s[i]=='('){

    //         if( !st.empty() && st.top() == ')'){
    //             st.pop();
    //             a=0;
    //         }
    //         st.push('(');
    //     }
    //     else{
    //         if( !st.empty() && st.top() == '('){
    //             st.pop();
    //             a+=2;
    //             ans=max(ans,a);
    //         }
    //         else{
    //             st.push(')');
    //         }
    //     }
    //    }
    //    return ans;
    // }
};