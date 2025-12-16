#include <iostream>
#include <vector>
#include <map>
using namespace std;

int findNoAppearingOnce (vector<int> vec) {     // TC: O(NlogM) N: length of arr, M: size of map    
    map <int, int> mp;
    for (int i=0; i<vec.size(); i++) {
        mp[vec[i]]++;
    }
    for (auto it : mp) {
        if (it.second == 1) {
            return it.first;
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