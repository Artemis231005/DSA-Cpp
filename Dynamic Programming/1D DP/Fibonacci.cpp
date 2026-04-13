#include<iostream>
#include<cstring>   // for memset
using namespace std;

// Top-down DP (memoization):   TC: O(n)   SC: O(n)
int fibonacci(int n, int dp[]) {
    if (n <= 1) {
        return n;
    }
    if (dp[n] != -1) {
        return dp[n];
    }

    return dp[n] = fibonacci(n-1, dp) + fibonacci(n-2, dp);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int *dp = new int[n+1];
    memset(dp, -1, (n+1)*sizeof(int));

    cout << "The fibonacci series for " << n << " is: ";
    for (int i = 0; i < n; i++) {
        cout << fibonacci(i, dp) << " ";
    }
    delete[] dp;

    return 0;
}