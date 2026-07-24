#include <iostream>
#include <vector>
using namespace std;

// TC: O(log2 N)
int findPeakElem(vector<int> &vec) {
    int n = vec.size();

    if (n == 1) {
        return 0;
    }
    if (vec[0] > vec[1]) {
        return 0;
    }
    if (vec[n - 1] > vec[n - 2]) {
        return n - 1;
    }

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (vec[mid] > vec[mid - 1] && vec[mid] > vec[mid + 1]) {
            return mid;
        } 

        if (vec[mid] < vec[mid + 1]) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

void display(vector<int> vec) {
    for (int i: vec) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n, elem, target;
    vector<int> vec;
    cout << "Enter number of elements of array: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> elem;
        vec.push_back(elem);
    }

    cout << "Peak element is: " << findPeakElem(vec);
    return 0;
}