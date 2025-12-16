#include <iostream>
#include <vector>
using namespace std;

int findNoAppearingOnce (vector<int> vec) {         // TC: O(3N)   SC: O(maxElem)  
    // hash arr cant be used for huge inputs (like 10^9), so use map with bigger datatype (ex: map<long long, int>)
    int hsize = findMaxElem(vec) + 1;
    vector<int> hash (hsize, 0);

    for (int i=0; i<vec.size(); i++) {
        hash[vec[i]] ++;
    }

    for (int i=0; i<vec.size(); i++) {
        if (hash[vec[i]] == 1) {
            return vec[i];
        }
    }
    return -1;
}

int findMaxElem (vector<int> vec) {
    int maxElem = vec[0];
    for (int i=0; i<vec.size(); i++) {
        if (vec[i] > maxElem) {
            maxElem = vec[i];
        }
    }
    return maxElem;
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