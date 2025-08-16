#include<iostream>
#include<stack>
using namespace std;

// TC: O(N) = O(N) + O(N) + O(N) 
// SC: O(N) + O(N)  stack and ans will store max of N elem
int priority (char op) {
    int priorityOp = -1;
    if (op == '^') {
        priorityOp = 3;
    }
    else if (op == '*' || op == '/') {
        priorityOp = 2;
    }
    else if (op == '+' || op == '-') {
        priorityOp = 1;
    }
    return priorityOp;
}

string infixToPostfix(string s) {
    int i = 0;
    stack<char> st;
    string ans = "";

    while (i < s.length()) {
        if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9') {
            ans += s[i];
        }
        else if (s[i] == '(') {
            st.push(s[i]);
        }
        else if (s[i] == ')') {
            while (st.top() != '(') {      // This inner while loop will run at most for N elem across ALL iterations, so O(N)
                ans += st.top();
                st.pop();
            }
            if (!st.empty()) {
                st.pop();
            }
        }
        else {
            while (!st.empty() && (priority(s[i]) < priority(st.top()) || (priority(s[i]) == priority(st.top()) && s[i] != '^'))) {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
            // If s[i] is ^ with equal precedence -> don’t pop, because ^ is right-associative.
        }
        i++;
    }

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main() {
    string s;
    cout << "Enter an infix string: ";
    cin >> s;
    cout <<"Postfix string is: " << infixToPostfix(s) << endl;
    return 0;
}

// the inner while loop collectively pops each operator at most one time.
// Even though the inner loop can run multiple times per iteration, the total number of pops across all iterations is bounded by N.