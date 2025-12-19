#include <iostream>
#include <vector>
#include <map>
using namespace std;

int longestSubarrayWithSumK (vector<int> vec, int k) {      // O(nlogn) (logn because of find and mp orperator:[]) SC: O(n)
    // This is the most optimal code for array with positive, negative and zeros
    int n = vec.size();     
    map <int, int> preSumMap;
    int maxLength = 0;
    int sum = 0;

    for (int i=0; i<n; i++)  {
        sum += vec[i];
        if (sum == k) {                                  
            maxLength = max(maxLength, i+1);             
        }
        
        int rem = sum - k;
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];  
            maxLength = max(maxLength, len);
        }

        if (preSumMap.find(sum) == preSumMap.end()) {   
            preSumMap[sum] = i;
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