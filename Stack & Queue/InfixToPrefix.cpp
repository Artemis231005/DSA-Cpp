#include <iostream>
#include <stack>
using namespace std;

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

string reverseExceptBrackets(string s) {
    string t = string(s.rbegin(), s.rend());

    for (int i=0; i<t.length(); i++) {
        if (t[i] == '(') {
            t[i] = ')';
        }
        else if (t[i] == ')') {
            t[i] = '(';
        }
    }
    return t;
}

string infixToPrefix(string s) {
    string reversed =  reverseExceptBrackets(s);
    int i=0;
    stack<char> st;
    string ans = "";

    while (i < reversed.length()) {
        if (reversed[i] >= 'A' && reversed[i] <= 'Z' || reversed[i] >= 'a' && reversed[i] <= 'z' || reversed[i] >= '0' && reversed[i] <= '9') {
            ans += reversed[i];
        }
        else if (reversed[i] == '(') {
            st.push(reversed[i]);
        }
        else if (reversed[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            if (!st.empty()) {
                st.pop();               // pop opening bracket as well
            }
        }

        else {                      // here conditions will be diff (take out op that have similar or greater priority?)
            if (reversed[i] == '^') {
                while (!st.empty() && priority(reversed[i]) <= priority(st.top())) {
                    ans += st.top();
                    st.pop();       // cannot store two ^ in a stack together
                }
            }
            else {
                while (!st.empty() && priority(reversed[i]) < priority(st.top())) { // similar priority or greater
                    ans += st.top();
                    st.pop();       
                }
            }
            st.push(reversed[i]);
        }
        i++;
    }
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    ans = string(ans.rbegin(), ans.rend());         // reversing again
    return ans;
}

int main() {
    string s;
    cout << "Enter an infix string: ";
    cin >> s;
    cout <<"Prefix string is: " << infixToPrefix(s) << endl;
    return 0;
}