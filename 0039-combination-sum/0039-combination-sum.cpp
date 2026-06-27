class Solution {
public:
set<vector<int>> s;
void f(vector<int>& can, int target , int i , vector<int>&comb , vector<vector<int>>&ans){
        if(target==0){
            if(s.find(comb) == s.end()){
               ans.push_back(comb); 
               s.insert(comb);
            }
            return; 
        }
        if(target<0){
            return ;
        }
        if(i>=can.size()){
            return ;
        }
        comb.push_back(can[i]);
        f(can , target-can[i] , i+1 , comb , ans);
        f(can, target-can[i] , i ,comb ,ans);
        comb.pop_back();
        f(can,target,i+1,comb,ans);

    }
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        vector<vector<int>> ans;
        vector<int>comb;
        f(can,target,0,comb,ans);
        return ans;
    }
    
};