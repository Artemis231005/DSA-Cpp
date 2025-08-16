#include<iostream>
#include<climits>
#include<stack>
using namespace std;

class MinStack {
    public:
    stack<int> st;
    int min = INT_MAX;

    void push(int val) {
        if (st.empty()) {
            min = val;
            st.push(val);
        } else {
            if (val > min) {
                st.push(val);
            } else {
                st.push (2*val - min);
                min = val;
            }
        }
    }

    void pop() {
        if (st.empty()) {
            return;
        }
        int x = st.top();
        st.pop();

        if (x < min) {      // means modified value hai
            min = 2*min - x;
        }
        if (st.empty()) {  // reset minVal if stack is empty
            min = INT_MAX;
        }
    }

    int top() {
        if (st.empty()) {
            cout << "No element";
            return -1;
        }

        int x = st.top();
        if (x >= min) {
            return x;
        } else {
            return min;
        }
    }

    int getMin() {
        if (min == INT_MAX) {
            cout << "No min yet";
            return -1;
        }
        return min;
    }
};

int main() {
    int a;
    MinStack st;
    st.push(12);
    st.push(15);
    st.push(10);
    a = st.getMin();
    cout << a << endl;
    st.pop();
    a = st.getMin();
    cout << a << endl;
    a = st.top();
    cout << a << endl;
    st.push(10);
    a = st.top();
    cout << a << endl;
    return 0;
}