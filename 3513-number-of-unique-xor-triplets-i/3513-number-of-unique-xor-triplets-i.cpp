class Solution {
public:
    unordered_set<int> s;
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n<=2)return n;
        int ans = 1;
        while(ans<=n){
            ans <<= 1;
        }
        return ans;
    }
    void f(vector<int>&nums , int i , int n , int xr){
        if(n==3){
            s.insert(xr);
            return ;
        }
        if(i==nums.size()){
            return;
        }
        f(nums , i , n+1 , xr^nums[i]);
        f(nums , i+1 , n , xr);
    }
    };