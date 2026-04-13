#include<iostream>
#include<vector>
#include<cstring>   // for memset
using namespace std;

// Top-down DP (memoization):   TC: O(n)   SC: O(2n) (extra recursion stack space)
int fibonacciMemoization(int n, int dp[]) {
    if (n <= 1) {
        return n;
    }
    if (dp[n] != -1) {
        return dp[n];
    }

    return dp[n] = fibonacciMemoization(n-1, dp) + fibonacciMemoization(n-2, dp);
}

// Bottom-up DP (tabulation):   TC: O(n)   SC: O(n)
void fibonacciTabulation(int n, vector<int>& dp) {
    if (n == 0) {
        dp[0] = 0;
        return;
    }

    dp[0] = 0;
    dp[1] = 1;

    for (int i=2; i<n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
}

// TC: O(N)   SC: O(1)
void fibbonacciOptimized(int n) {
    if (n == 0) {
        cout << 0;
        return;
    }
    if (n == 1) {
        cout << 0;
        return;
    }

    int prev2 = 0;
    int prev = 1;
    cout << prev2 << " " << prev << " ";

    for (int i=2; i<n; i++) {
        int curr = prev + prev2;
        cout << curr << " ";
        prev2 = prev;
        prev = curr;
    }
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int *dp = new int[n+1];
    memset(dp, -1, (n+1)*sizeof(int));

    cout << "The fibonacci series for " << n << " using memoization is: ";
    for (int i = 0; i < n; i++) {
        cout << fibonacciMemoization(i, dp) << " ";
    }
    cout << endl;
    delete[] dp;

    vector<int> dpTab (n+1, -1);
    cout << "The fibonacci series for " << n << " using tabulation is: ";
    fibonacciTabulation(n, dpTab);
    for (int i = 0; i < n; i++) {
        cout << dpTab[i] << " ";
    }
    cout << endl;

    cout << "The optimized fibonacci series for " << n << " is: ";
    fibbonacciOptimized(n);
    cout << endl;
    return 0;
}