class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> histo(m,0);
        int maxa = 0;
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')histo[j]++;
                else histo[j]=0;
            }
            maxa = max(maxa , f(histo));
        }
        return maxa;
    }

    int f(vector<int>&histo){
        int maxa = 0;
        int n = histo.size();
        stack<int> st;
        for(int i = 0;i<=n;i++){
            while(!st.empty() &&(i==n || histo[st.top()]>histo[i])){
                int height = histo[st.top()];
                st.pop();
                int width;
                if(st.empty())width=i;
                else width = i-st.top()-1;

                maxa = max(maxa,height*width);
            }
            st.push(i);
        }
        return maxa;
    }
};