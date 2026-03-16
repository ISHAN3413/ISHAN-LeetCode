class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num2 == "0")return num1;
        if(num1 == "0")return num2;
        string ans = "";
        int carry = 0;
        int sum = 0;
        int i=num1.length()-1;
        int j=num2.length()-1;
        while(i>=0 || j>=0 || carry>0){
            sum = carry;
            if(i>=0)sum+=num1[i--]-'0';
            if(j>=0)sum+=num2[j--]-'0';
            ans+=sum%10+'0';
            carry = sum/10;
        }
       reverse(ans.begin(),ans.end());
        return ans;
    }
};