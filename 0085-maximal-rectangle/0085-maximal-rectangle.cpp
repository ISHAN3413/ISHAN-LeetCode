class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<int> temp(m , 0);
        for(int i = 0;i<n ; i++){
            int a = 0;
            for(int j = 0;j<m;j++){
                
                if(matrix[i][j]=='1')temp[j]++;
                else temp[j] = 0;
                a = l(temp);
            }
            ans = max(ans , a);
        }
        return ans;
    }
    int l(vector<int>&heights){
        int n = heights.size();
        stack<int> st;
        int maxa = 0;
        for(int i = 0;i<=n ; i++){
            while(!st.empty()&&(i==n || heights[st.top()]>=heights[i] ) ){
                int height = heights[st.top()];
                int width;
                st.pop();
                if(st.empty())width = i;
                else width = i - st.top() -1;
                maxa = max(maxa ,height*width);
            }
            st.push(i);
        }
        return maxa;
    }
};