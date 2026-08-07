#include<iostream>
#include<stack>
using namespace std;

// TC: O(N) (+ O(N) if adding str(lang-specific))   SC: O(n)
string postfixToInfix(string s) {
    int i = 0;
    stack<string> st;

    while (i < s.length()) {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            st.push(string(1, s[i]));     // string(1, s[i]) means, create a string of length 1. and use s[i] as the character.
        } else {
            string elem1 = st.top();
            st.pop();

            string elem2 = st.top();
            st.pop();

            string term = "(" + elem2 + s[i] + elem1 + ")";
            st.push(term);
        }
        i++;
    }

    return st.top();        // top elem will be the infix expr
}

int main() {
    string s;
    cout << "Enter a postfix string: ";
    cin >> s;
    cout <<"Infix string is: " << postfixToInfix(s) << endl;
    return 0;
}