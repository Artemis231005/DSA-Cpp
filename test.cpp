#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void findSubsetSum(int idx, int sum, vector<int> &vec, vector<int> &sumofSubsets) {
    if (idx == vec.size()) {
        sumofSubsets.push_back(sum);
        return;
    }

    findSubsetSum(idx + 1, sum + vec[idx], vec, sumofSubsets);

    findSubsetSum(idx + 1, sum, vec, sumofSubsets);
}

vector<int> subsetSums(vector<int> &vec, int n) {
    vector<int> sumofSubsets;
    findSubsetSum(0, 0, vec, sumofSubsets);
    sort(sumofSubsets.begin(), sumofSubsets.end());
    return sumofSubsets;
}

int main() {
    int n, val;
    vector<int> vec;

    cout << "Enter size of vector: ";
    cin >> n;

    cout <<"Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        vec.push_back(val);
    }

    cout << "Subset sums of the array are: " << endl;
    vector<int> ans = subsetSums(vec, n);

    for (auto i: ans) {
        cout << i << " ";
    }
    return 0;
}