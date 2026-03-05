#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// TC: O(nlogn + mlogn + max(n, m))   SC: O(1)
int assignCookies(vector<int> greed, vector<int> cookieSize) {
    int n = greed.size();
    int m = cookieSize.size();
    int l = 0;      // for iterating over cookieSize
    int r = 0;      // for iterating over greed

    sort(greed.begin(), greed.end());
    sort(cookieSize.begin(), cookieSize.end());

    while (l < m && r < n) {
        if (greed[r] <= cookieSize[l]) {
            r++;    // go to next child
        }
        l++;        // go to next cookie size
    }
    return r;
}

int main() {
    int n, m, val;
    cout << "Enter number of children: ";
    cin >> n;
    cout << "Enter number of cookies: ";
    cin >> m;
    vector<int> greed, cookieSize;

    cout << "Enter greed factors of children: ";
    for (int i=0; i<n; i++) {
        cin >> val;
        greed.push_back(val);
    }
    cout << "Enter size of cookies: ";
    for (int i=0; i<m; i++) {
        cin >> val;
        cookieSize.push_back(val);
    }

    cout << "The max number of children that can be satisfied by giving cookies are: " << assignCookies(greed, cookieSize) << endl;
    return 0;
}