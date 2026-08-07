class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lefti(n);
        vector<int> righti(n);
        lefti[0] = height[0];
        righti[n-1] = height[n-1];
        for(int i = 1 ; i<n ;i++){
            lefti[i] = max(lefti[i-1],height[i]);
        }
        for(int i=n-2 ; i>=0 ;i--){
            righti[i] = max(righti[i+1] , height[i]);
        }

        int ans = 0;
        for(int i = 0;i<n ; i++){
            ans+=(min(lefti[i] , righti[i])-height[i]);
        }
        return ans;
    }
};