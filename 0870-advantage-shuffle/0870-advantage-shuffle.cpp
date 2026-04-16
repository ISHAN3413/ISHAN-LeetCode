class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int maxi = 0;
        for(int i = 0;i<nums1.size();i++){
            maxi = max(maxi , nums1[i]);
        }
        map<int,int>a;
        for(int i:nums1)a[i]++;
        vector<pair<int,int>> n2;

        for(int i = 0;i<nums2.size();i++){
            n2.push_back({nums2[i] , i});
        }
        sort(n2.begin(),n2.end());

        vector<int> ans(nums2.size() , -1);

        for(int i = 0;i<nums2.size();i++){
            int j = n2[i].first;
            auto it = a.upper_bound(j);
            if(it == a.end()){
                it = a.begin();
            }
            
            ans[n2[i].second] = it->first;
            it->second--;
           if(it->second == 0){
            a.erase(it);
           }
        }
        return ans;
    }
};