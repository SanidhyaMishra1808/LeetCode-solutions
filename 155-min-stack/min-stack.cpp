class MinStack {
  stack < pair < int, int >> st;
  public:
    void push(int x) {
        int min;
        if (st.empty()){
            st.push({x,x});
        }else{
            st.push({x, (x < st.top().second) ? x : st.top().second});
        }
    }
    void pop() {
        st.pop();
    }
    int top() {
        return st.top().first;
    }
    int getMin() {
        return st.top().second;
    }
};