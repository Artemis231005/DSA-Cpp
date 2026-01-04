#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxSubarraySum (vector<int> vec) {      // TC: O(N^3)   SC: O(1)
    int maxSum = INT_MIN;

    for (int i=0; i<vec.size(); i++) {
        for (int j=i; j<vec.size(); j++) {
            int sum =0;
            for (int k=i; k<=j; k++) {
                sum += vec[k];
            }
            maxSum = max(sum, maxSum);
        }
    }
    return maxSum;
}

void display(vector<int> &vec) {
    for (int i: vec) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter size of the array: ";
    cin >> n;

    vector<int> vec(n);                     
    cout << "Enter the values: ";
    for (int i=0; i<n; i++) {
        cin >> vec[i];
    }

    cout << "The maximum subarray sum is: " << maxSubarraySum(vec);
    return 0;
}