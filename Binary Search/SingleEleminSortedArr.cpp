#include <iostream>
#include <vector>
using namespace std;

// TC: O(log N)
int findSingleElem(vector<int>& vec) {
        int left = 0;
        int right = vec.size() - 1;

        while(left < right){
            int mid = left + (right - left)/2;

            // checks pattern of even-odd
            if((mid % 2 == 0 && vec[mid] == vec[mid + 1]) || 
            (mid % 2 == 1 && vec[mid] == vec[mid - 1])) {
                left = mid + 1;                  // if even-odd, means left half => move right
            }
            else {
                right = mid;                     // odd-even => right half => move towards left
            }
            // right = mid instead of mid + 1, since mid could be the single elem
        }
    
        return vec[left];
    }
    // No indexing out of bounds since left < right, instead of <=, meaning mid is always strictly less than right and loop stops when left == right

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

    cout << "Single element is: " << findSingleElem(vec);
    return 0;
}