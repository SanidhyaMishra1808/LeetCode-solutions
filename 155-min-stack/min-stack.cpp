class MinStack {
  stack < pair < int, int >> st;
  public:
    void push(int x) {
      if (st.empty()){
        st.push({x,x});
      }else{
        st.push({x,min(x,st.top().second)});
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