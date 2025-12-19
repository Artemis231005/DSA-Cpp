#include <iostream>
#include <vector>
#include <map>
using namespace std;

int longestSubarrayWithSumK (vector<int> vec, int k) {      // TC: approx O(N^2)   SC: O(1)
    int n = vec.size();
    int longestLength = 0;

    for (int i=0; i<n; i++) {
        int sum = 0;
        for (int j=i; j<n; j++) {
            sum += vec[j];

            if (sum == k) {
                longestLength = max(longestLength, j-i+1);      // j-i+1 is distance or length between i and j
            }
            
        }
    }
    return longestLength;
}

void display(vector<int> vec) {
    for (int i: vec) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n, elem;
    vector<int> vec;
    cout << "Enter the size: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> elem;
        vec.push_back(elem);
    }

    int k;
    cout << "Enter target sum: ";
    cin >> k;
    cout << "Longest subarray with sum " << k << " is: " << longestSubarrayWithSumK(vec, k);
    return 0;
}