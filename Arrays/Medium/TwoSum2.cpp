#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> twoSum (vector<int> vec, int k) {    // TC: O(N^2)   SC: O(N)
    // Better than prev sol but tc still near O(N^2)
    vector<pair<int, int>> ans;
    int n = vec.size();

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (vec[i] + vec[j] == k) {
                ans.push_back({vec[i], vec[j]});
            }
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