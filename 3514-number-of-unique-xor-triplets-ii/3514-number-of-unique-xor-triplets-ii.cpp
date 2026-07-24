class Solution {
public:
    unordered_set<int> s;
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_map<int,int> mp;
        
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int>arr;
        for(auto a:mp){
            arr.push_back(a.first);
        }
        vector<vector<vector<bool>>> vis(arr.size()+1 , vector<vector<bool>>(4 , vector<bool>(2048 , false)));

        f(arr , 0 , 0 , 0 ,vis );
        return s.size();
    }
     void f(vector<int>&nums , int i , int n , int xr,vector<vector<vector<bool>>>& vis){
       
        if(n==3){
            s.insert(xr);
            return ;
        }
        if(i==nums.size()){
            return;
        }

         if(vis[i][n][xr])return;
        vis[i][n][xr] = true;
        f(nums , i , n+1 , xr^nums[i],vis);
        f(nums , i+1 , n , xr,vis);
    }
};