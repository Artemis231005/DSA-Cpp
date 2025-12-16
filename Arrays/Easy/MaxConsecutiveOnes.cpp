#include <iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &vec) {      // TC: O(N)   SC: O(1)
    int maxi = 0, counter = 0;
    for (int i=0; i<vec.size(); i++) {
        if (vec[i] == 1) {
            counter++;
            maxi = max(maxi, counter);
        } else {
            counter = 0;
        }
    }
    return maxi;
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

    cout << "Maximum number of consecutive 1's is: " << findMaxConsecutiveOnes(vec);
    return 0;
}