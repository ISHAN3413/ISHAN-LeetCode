class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        long long a= num/3 ; 
        long long rem = num%3;
        vector<long long> ans;
        ans.push_back(a-1);
        ans.push_back(a);
        ans.push_back(a+1);
        if(rem == 0)return ans;
        if(rem%3 !=0)return {};
        a = rem/3;
        ans[0]+=a;
        ans[1]+=a;
        ans[2]+=a;
        return ans;
    }
};