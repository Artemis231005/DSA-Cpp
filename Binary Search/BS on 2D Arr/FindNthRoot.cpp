#include <iostream>
#include <vector>
using namespace std;

// TC: O(log2M) (binary search) * O(log2 N (binary exponentiation)
int getMid(int mid, int n, int m) {
    long long ans = 1;

    for (int i=1; i<=n; i++) {
        ans = ans * mid;

        if (ans > m) {
            return 2;
        }
    }
    if (ans == m) {
        return 1;
    }
    return 0;
}
// prevent overflow by not computing mid ^ n (mid * mid * mid...) and instead stopping as soon as it crosses m
// return 1 if == m
// return 0 if < m
// return 2 if > m

int findNthRoot (int n, int m) {
    int low = 1, high = m;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int midN = getMid(mid, n, m);

        if (midN == 1) {
            return mid;
        } else if (midN == 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

void display(vector<int> vec) {
    for (int i: vec) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n, m;
    cout << "Enter the number whose root you want to find: ";
    cin >> m;

    cout << "Enter the the value of root: ";
    cin >> n;

    int ans = findNthRoot(n, m);
    if (ans != -1) {
        cout << "Nth root is: " << ans;
    } else {
        cout << "Value of Nth root not found";
    }
    return 0;
}