class Solution {
public:
    set<vector<int>> s;
    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
        sort(can.begin(),can.end());
        vector<int> comb;
        vector<vector<int>> ans;
        f(can,target,0,comb,ans);
        return ans;
    }
    void f(vector<int>& can, int target , int i , vector<int> &comb , vector<vector<int>>&ans){
        if(target==0){
            if(s.find(comb)==s.end()){
              ans.push_back(comb);  
              s.insert(comb);
            }
            return;
        }
        if(i>=can.size()||target<0){
            return;
        }
        comb.push_back(can[i]);
        f(can,target-can[i],i+1,comb,ans);
        comb.pop_back();
        int j = i;
        while(j+1<can.size() && can[j]==can[j+1])j++;
        f(can,target,j+1,comb,ans);
        return ;
    }
};