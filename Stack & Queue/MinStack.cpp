#include<iostream>
#include<stack>
using namespace std;

// TC: O(1)
// SC: O(2N)        2N because we are storing pairs

class MinStack {
    public:
    stack <pair<int, int>> st;

    void push(int val) {
        if (st.empty()) {
            st.push ({val, val});
        } else {
            st.push ({val, min(val, st.top().second)});
        }
    }
    
    void pop() {
        st.pop();
    }

    int getMin() {
        cout << st.top().second << endl;
        return st.top().second;
    }

    int top() {
        cout << st.top().first << endl;
        return st.top().first;
    }
};

int main() {
    MinStack st;
    st.push(12);
    st.push(15);
    st.push(10);
    st.getMin();
    st.pop();
    st.getMin();
    st.top();
    st.push(10);
    st.top();
    return 0;
}