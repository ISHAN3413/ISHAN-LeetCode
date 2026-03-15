class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        std::unordered_map<int,std::string> m;
        vector<string> a;
        for(int i=0;i<names.size();i++){
                m[heights[i]]=names[i];
        }
        std::sort(heights.begin(),heights.end(),std::greater<int>());
       for(int i=0;i<heights.size();i++){
        a.push_back(m[heights[i]]);
       }
       return a;


    }
};