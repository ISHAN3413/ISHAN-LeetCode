class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int i = 0;
        for(int j = 1 ; j<=target.back() ; j++){
             ans.push_back("Push");
             if(j==target[i]){
                i++;
             }else{
                ans.push_back("Pop");
             }
        }
        return ans;
    }
};