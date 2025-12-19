#include <iostream>
#include <vector>
#include <map>
using namespace std;

int longestSubarrayWithSumK (vector<int> vec, int k) {      // TC: O(2N)   SC: O(1)
    // This approach relies on assumption that as we increase right, sum increases 
    // This is valid for positive and zero numbered array but fails for array which includes negative numbers
    int n = vec.size();     
    int left = 0, right = 0;
    int sum = vec[0];
    int maxLength = 0;
   
    while (right < n) {
        while (left <= right && sum > k) {
            sum -= vec[left];
            left++;
        }

        if (sum == k) {
            maxLength = max(maxLength, right - left + 1);
        }

        right++;
        if (right < n) {
            sum += vec[right];
        }
    }

    return maxLength;
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