class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> gr(n);
        for(const auto &a:edges){
            int u = a[0],v=a[1];
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        vector<bool>visi(n);
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(!visi[i]){
                vector<int>compo;
                queue<int> q;
                q.push(i);
                visi[i] = true;
                while(!q.empty()){
                    int curr = q.front();
                    q.pop();
                    compo.push_back(curr);
                    for(int nei:gr[curr]){
                        if(!visi[nei]){
                            visi[nei] = true;
                            q.push(nei);
                        }
                    }
                }

                bool iscomp = true;

                for(int node:compo){
                    if(gr[node].size()!=compo.size()-1){
                        iscomp = false;
                        break;
                    }
                }
                if(iscomp)ans++;

            }
        }
        return ans;
    }
};