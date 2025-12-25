#include <iostream>
#include <vector>
#include <map>
using namespace std;

int longestSubarrayWithSumK (vector<int> vec, int k) {      // TC: approx O(N^2)   SC: O(1)
    int n = vec.size();
    int left = 0, right = 0;
    int sum = vec[0];
    int llength = 0;

    for (int i=0; i<n; i++) {
        if (left <= right && sum > k) {
            sum -= vec[left];
            left ++;
        }

        if (sum == k) {
            llength = max (llength, right - left + 1);
        }

        right++;
        if (right < n) {
            sum += vec[right];
        }
    }

    return llength;
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