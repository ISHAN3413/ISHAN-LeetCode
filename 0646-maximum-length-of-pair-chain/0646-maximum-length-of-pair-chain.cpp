class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin() , pairs.end() , [](auto &a , auto&b){
            return a[1]<b[1];
        });
        int ans = 1;
        int j =pairs[0][1] ;
        for(int i = 1;i<pairs.size();i++){
            if(pairs[i][0] > j ){
                ans++;
                j = pairs[i][1];
            }
        }
        return ans;
    }
};