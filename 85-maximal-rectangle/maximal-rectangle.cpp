class Solution {
    private:
    int maxArea(vector<int> &heights){
        int n = heights.size();
        stack<int> st;
        int maxA = 0;
        for(int i=0; i<=n; i++){
            while(!st.empty() && (i == n || heights[st.top()] >= heights[i])){
                int height = heights[st.top()]; 
                st.pop();
                int width;
                if(st.empty()) {
                    width = i;
                }else {
                    width = i - st.top() - 1;
                }
                maxA = max(maxA, height * width);
            }
            st.push(i);
        }
        return maxA;
    }
    public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> row(m, 0);
        int maxRec = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == '0'){
                    row[j] = 0;
                }
                else{
                    row[j] += 1;
                }
            }
            maxRec = max(maxRec, maxArea(row));
        }
        return maxRec;
    }
};