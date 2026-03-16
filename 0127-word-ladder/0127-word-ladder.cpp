class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& wl) {
        queue<pair<string , int>> q;
        q.push({bw , 1});
        unordered_set<string> st(wl.begin(),wl.end());
        st.erase(bw);
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == ew)return steps;
            for(int i = 0;i<word.size();i++){
                char original = word[i];
                for(char ch = 'a'; ch<='z' ; ch++){
                    word[i] = ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word , steps+1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};