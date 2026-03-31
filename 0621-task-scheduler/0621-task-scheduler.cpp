class Solution {
public:
   int leastInterval(vector<char>& tasks, int n) {
    vector<vector<int>> h(26, vector<int>(2, 0)); 
    for(char c : tasks) h[c - 'A'][0]++;

    int time = 0;
    while (true) {
        int ind = -1;
        bool flag = false;

        for (int i = 0; i < 26; i++) {
              if(h[i][0] > 0) {
            flag = true;
                if (h[i][1] == 0) {
                    if (ind == -1 || h[i][0] > h[ind][0]) {
                        ind = i;
                    }}
            }
        }
if (!flag) break;

        time++;

        if (ind != -1) {
            h[ind][0]--;       
            h[ind][1] = n + 1; 
        }

        for (int i = 0; i < 26; i++) {
            if (h[i][1]> 0)h[i][1]--;
        }
    }
    return time;
}
};