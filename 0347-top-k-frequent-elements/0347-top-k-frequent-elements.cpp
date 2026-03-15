class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int,int> m;
        vector<int> a;
         vector<int> b;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for (auto it : m) { 
        a.push_back(it.second); 
    } 
        for(int i=0;i<a.size();i++){
            for(int j=i+1;j<a.size();j++){
                if(a[i]<a[j]){
                    swap(a[i],a[j]);
                }
            }
        }
        for (int i = 0; i < k; i++) {
        for (const auto& pair : m) {
        if (pair.second == a[i]) {
            b.push_back(pair.first);
            m[pair.first]=-1;
            break; 
        }
    }
}
        return b;
    }
};