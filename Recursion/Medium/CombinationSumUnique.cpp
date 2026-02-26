#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

void findCombination(int idx, int target, vector<int> & arr, set<vector<int>> &ans, vector<int> &store) {
    if (idx == arr.size()) {
        if (target == 0) {
            ans.insert(store);
        }
        return;
    }

    if (arr[idx] <= target) {
        store.push_back(arr[idx]);
        findCombination(idx + 1, target - arr[idx], arr, ans, store);
        store.pop_back();
    }

    findCombination(idx + 1, target, arr, ans, store);
}

set<vector<int>> combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end()); 

    set<vector<int>> ans;
    vector<int> store;
    findCombination(0, target, candidates, ans, store);
    return ans;
}

int main() {
    int n, val, target;
    vector<int> vec;

    cout << "Enter size of vector: ";
    cin >> n;

    cout <<"Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        vec.push_back(val);
    }

    cout << "Enter target: ";
    cin >> target;

    cout << "Combinations of the array that sum up to " << target << " are: " << endl;
    set<vector<int>> ans = combinationSum(vec, target);

    for (auto it: ans) {
        cout << "[";
        for (auto i: it) {
            cout << i << " ";
        }
        cout << "]";
        cout << " ";
    }
    return 0;
}