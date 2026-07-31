class Solution {
public:
    int minimumPushes(string word) {
        vector<int> hash(27,0);
        for(int i = 0;i<word.length();i++ ){
            hash[word[i]-'a']++;
        }
        sort(hash.begin(),hash.end(),[](int a , int b){
            return a>b;
        });

        int ans = 0;
        int j = 2;
        int t = 1;
        for(int i:hash){
            if(j==10){
                j=2;
                t++;
            }
            ans+=(i*t);
            j++;
        }
        return ans;
    }
};