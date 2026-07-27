class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxa = 0;
        stack<int> st;
        int n = heights.size();
        for(int i = 0 ;i<=n;i++){
            while(!st.empty() &&(i==n || heights[st.top()]>=heights[i])){
                int height = heights[st.top()];
                st.pop();
                int weight;
                if(st.empty())weight = i;
                else weight = i-st.top()-1;

                maxa = max(maxa , height*weight);
            }
            st.push(i);
        }
        return maxa;
    }
};