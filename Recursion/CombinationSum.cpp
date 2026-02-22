#include<iostream>
#include<vector>
using namespace std;

void findCombination(int idx, int target, vector<int> & arr, vector<vector<int>> &ans, vector<int> &store) {
    if (idx == arr.size()) {
        if (target == 0) {
            ans.push_back(store);
        }
        return;
    }

    // picking up elem
    if (arr[idx] <= target) {
        store.push_back(arr[idx]);
        findCombination(idx, target - arr[idx], arr, ans, store);
        store.pop_back();
    }

    findCombination(idx + 1, target, arr, ans, store);
}

// TC: O(2^t*k)   SC: O(k*x)
// t = target, k = avg length of comb, x = no of comb
vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
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
    vector<vector<int>> ans = combinationSum(vec, target);

    for (vector<int> it: ans) {
        cout << "[";
        for (auto i: it) {
            cout << i << " ";
        }
        cout << "]";
        cout << " ";
    }
    return 0;
}