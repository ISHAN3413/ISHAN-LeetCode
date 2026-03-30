class Solution {
public:
    string removeKdigits(string num, int k) {
     if(num.length()==k)return "0";
     stack<char> st;
     st.push(num[0]);
     for(int i = 1;i<num.length();i++){
        while((!st.empty()) && (k>0)&&(num[i]<st.top())){
            st.pop();
            k--;
        }
        st.push(num[i]);
     }
     while(k>0 && !st.empty()){
        st.pop();
        k--;
     }
      string ans = "";
     while(!st.empty()){
        ans+=(st.top());
        st.pop();
     }
    
    reverse(ans.begin() , ans.end());
     
     string s = "";
     bool flag = true;
    for(int i = 0 ; i<ans.length();i++){
        if(ans[i]!='0')flag = false;
        if(!flag){
            s+=ans[i];
        }
    }
    if(s == "")return "0";
    return s;

    }
};