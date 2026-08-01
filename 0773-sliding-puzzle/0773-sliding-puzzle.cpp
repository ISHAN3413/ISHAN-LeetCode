class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string end = "123450";
        string begin = "";
        for(int i = 0;i<board.size();i++){
            for(int j= 0;j<board[0].size();j++){
                begin+=to_string(board[i][j]);
            }
        }
        if(begin==end)return 0;
        vector<vector<int>> moves = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        queue<pair<string,int>> q;
        unordered_set<string> vis;
        vis.insert(begin);
        q.push({begin,0});
        while(!q.empty()){
            auto a = q.front();q.pop();
            string curr = a.first;
            int dist = a.second;
            int idx = curr.find("0");
            for(int i:moves[idx]){
                string next = curr;
                swap(next[idx],next[i]);
                if(next==end){
                    return dist+1;
                }
                if(!vis.count(next)){
                    vis.insert(next);
                    q.push({next , dist+1});
                }
            }
        }
        return -1;

    }
};