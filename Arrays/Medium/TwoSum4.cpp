#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> twoSum (vector<int> &vec, int k) {// Sorting: O(NlogN) Two-pointer loop: O(N), Total TC: O(NlogN)   Auxi SC: O(1)
    // Optimal sol if value is asked, but if indices asked, need to store elem with its idx and then sort => SC increases and not optimal
    // Still SLOWER than hashing
    
    vector<pair<int, int>> ans;
    int left = 0, right = vec.size()-1;
    sort(vec.begin(), vec.end());

    while (left < right) {
        int sum = vec[left] + vec[right];

        if (sum == k) {
            ans.push_back({vec[left], vec[right]});
            left++;
            right--;
        } 
        else if (sum < k) {
            left++;
        } 
        else {
            right--;
        }
    }
    return ans;
}

int main() {
    int n, elem, k;
    vector<int> vec;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> elem;
        vec.push_back(elem);
    }

    cout << "Enter target sum: ";
    cin >> k;

    vector<pair<int,int>> ans = twoSum(vec, k);
    cout << "The pairs that add up to " << k << " are: ";

    for (auto it: ans) {
        cout << "(" << it.first << "," << it.second << ")" << ", ";
    }
    return 0;
}