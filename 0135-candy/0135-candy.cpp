class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<pair<int , int>> m;
        int ans=0;
        for(int i =0;i<ratings.size();i++){
           m.push_back({ratings[i],1});
        }
        for(int i =0;i<m.size()-1;i++){
            if(m[i+1].first >m[i].first)m[i+1].second=m[i].second+1;
        }
        for(int i =m.size()-1;i>=1;i--){
            if((m[i-1].first >m[i].first) && (m[i-1].second <=m[i].second))m[i-1].second=m[i].second+1;
        }
        for(int i = 0;i<m.size();i++){
            ans+=m[i].second;
        }
        return ans;
    }
};