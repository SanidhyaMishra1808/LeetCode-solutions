class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int open = 0;
        for(char ch: s){
            if(ch == '('){
                st.push(ch);
            } else if( st.empty()){
                open++;
            }else{
                st.pop();
            }
        }
        return open + st.size();
    }
};