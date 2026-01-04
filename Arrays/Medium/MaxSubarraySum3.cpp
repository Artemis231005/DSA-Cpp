#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxSubarraySum (vector<int> vec) {      // TC: O(N)   SC: O(1)     
    int maxSum = INT_MIN;
    int sum = 0;
    
    for (int i=0; i<vec.size(); i++) {
        sum += vec[i];

        if (sum > maxSum) {
            maxSum = sum;
        }
        if (sum < 0) {
            sum = 0;
        }
    }

    if (maxSum < 0) {
        maxSum = 0;
    }
    return maxSum;
}

void printMaxSubarraySum (vector<int> vec) {        
    int maxSum = INT_MIN;
    int sum = 0, ansStart = -1, ansEnd = -1, start = -1;
    
    for (int i=0; i<vec.size(); i++) {
        if (sum == 0) {
            start = i;
        }
        sum += vec[i];

        if (sum > maxSum) {
            maxSum = sum;
            ansStart = start;
            ansEnd = i;
        }
        if (sum < 0) {
            sum = 0;
        }
    }

    if (maxSum < 0) {
        maxSum = 0;
        cout << "Positive sum not found";
        return;
    }
    
    cout << "Max subarray values: ";
    for (int i=ansStart; i<=ansEnd; i++) {
        cout << vec[i] << " ";
    }
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

    cout << "The maximum subarray sum is: " << maxSubarraySum(vec) << endl;
    printMaxSubarraySum(vec);
    return 0;
}