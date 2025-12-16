#include <iostream>
#include <vector>
#include <map>
using namespace std;

int findNoAppearingOnce (vector<int> vec) {     // TC: O(N)   SC: O(1)       
    int xorVal = 0;
    for (int i=0; i<vec.size(); i++) {
        xorVal = xorVal ^ vec[i];
    }
    return xorVal;
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

    cout << "The number that appears once is: " << findNoAppearingOnce(vec);
    return 0;
}