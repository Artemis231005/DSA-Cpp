#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<pair<int, int>> twoSum (vector<int> &vec, int k) {   // Avg TC: O(N), Worst TC:O(N^2)   SC: O(N)
    vector<pair<int, int>> ans;
    int n = vec.size();
    unordered_map<int, int> mp;

    for (int i=0; i<n; i++) {
        int elem1 = vec[i];
        int elem2 = k - elem1;

        if (mp.find(elem2) != mp.end()) {
            ans.push_back({elem1, elem2});
        }
        mp[elem1] = i;
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