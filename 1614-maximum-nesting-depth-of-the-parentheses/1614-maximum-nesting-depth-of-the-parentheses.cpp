class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int depth = 0;
        for(char c:s){
            if(c=='(')ans++;
            else if(c==')') ans--;

            depth = max(depth,ans);
        }
        return depth;
    }
};