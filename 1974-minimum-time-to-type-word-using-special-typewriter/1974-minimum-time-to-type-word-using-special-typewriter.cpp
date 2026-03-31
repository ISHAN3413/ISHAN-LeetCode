class Solution {
public:
    int minTimeToType(string word) {
        int curr = 'a';
        int ans=0;
        for(char ch : word){
            int diff = abs(ch - curr);
            int mini = min(diff , 26-diff);
            ans+=mini;
            ans+=1;
            curr = ch;
        }
        return ans;
    }
};