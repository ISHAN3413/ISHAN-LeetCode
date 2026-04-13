class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        for(int i = n ; i>= 0 ;i--){
            int ind = findmax(arr,i);
            if(ind == i-1)continue;
            if(ind !=0){
                ans.push_back(ind+1);
                reverse(arr.begin() , arr.begin()+ind+1);
            }

            ans.push_back(i);
            reverse(arr.begin() , arr.begin()+i);
        }
        return ans;
    }
    int findmax(vector<int>&arr,int n){
        int maxi = INT_MIN;
        int m = -1;
        for(int i = 0;i<n;i++){
            if(arr[i]>maxi){
                maxi = arr[i];
                m = i;
            }
        }
        return m;
    }
};