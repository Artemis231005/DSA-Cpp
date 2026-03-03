#include<iostream>
#include<vector>
using namespace std;

bool isPalindrome(string s, int start, int end) {
    while(start <= end) {
        if (s[start++] != s[end--]) {
            return false;
        }
    }
    return true;
}

void partition(int idx, string s, vector<string> &path, vector<vector<string>> &ans) {
    if (idx == s.size()) {
        ans.push_back(path);
        return;
    }

    for (int i=idx; i<s.size(); i++) {
        if (isPalindrome(s, idx, i)) {
            path.push_back(s.substr(idx, i - idx + 1));
            partition(i + 1, s, path, ans);
            path.pop_back();
        }
    }
}

vector<vector<string>> generatePartitions(string s) {
    vector<vector<string>> ans;
    vector<string> path;
    partition(0, s, path, ans);
    return ans;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    vector<vector<string>> ans = generatePartitions(s);
    cout << "Palindrome partitions are: " << endl;

    for (auto vec : ans) {
        cout << "[";
        for (auto str : vec) {
            cout << str << ",";
        }
        cout << "]";
        cout << endl;
    }

    return 0;
}