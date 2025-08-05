#include<iostream>
using namespace std;

bool isPallindrome(string s, int i) {
    if (i >= s.size() / 2) {
        return true;
    }
    if (s[i] != s[s.size()-i-1]) {
        return false;
    }
    return isPallindrome(s, i+1);
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    if(isPallindrome(s, 0)) {
        cout << "Is pallindrome";
    }
    else {
        cout << "Not a pallindrome";
    }
    return 0;
}