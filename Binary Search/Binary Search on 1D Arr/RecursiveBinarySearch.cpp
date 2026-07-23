#include <iostream>
#include <vector>
using namespace std;

// TC: O(log N)   SC: O(log N)
int recursiveBinarySearch(vector<int> &vec, int low, int high, int target) {
    if (low > high) return -1; 
        int mid = (low + high) / 2;

        if (vec[mid] == target) {
            return mid;
        }
        else if (target > vec[mid]) {
            return recursiveBinarySearch(vec, mid + 1, high, target);
        }
        return recursiveBinarySearch(vec, low, mid - 1, target);
}

int search(vector<int>& nums, int target) {
        return recursiveBinarySearch(nums, 0, nums.size() - 1, target);
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

    cout << "Enter target element: ";
    cin >> target;

    int low = vec[0];
    int high = vec[vec.size()-1];
    cout << "Target found at: " << search(vec, target);
    return 0;
}