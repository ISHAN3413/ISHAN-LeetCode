class Solution {
public:
    string frequencySort(string s) {
      std::vector<int> freq(128 , 0);
      for(auto a:s)freq[a]++;
      auto cmp = [&](char a, char b){
        if(freq[a]==freq[b])return a<b;
        return freq[a]>freq[b];
      };
      sort(s.begin(),s.end(),cmp);
      return s;
    }
};