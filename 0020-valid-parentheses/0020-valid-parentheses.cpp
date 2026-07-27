class Solution {
public:
    bool isValid(string s) {
        int o = 0;
        int c = 0;
        stack<char> st;
        for(char c:s){
            if(c=='(' || c=='{'||c=='[')st.push(c);
            else{
                if(!st.empty()){
                if(c==')'){
                    if(st.top()=='(')st.pop();
                    else return false;
                }
                else if(c=='}'){
                    if(st.top()=='{')st.pop();
                    else return false;
                }
                else if(c==']'){
                    if(st.top()=='[')st.pop();
                    else return false;
                }
                }
                else{
                    return false;
                }
                
            }
        }
        return st.empty();
    }
};