#include <iostream>
#include <vector>
using namespace std;

int findNoAppearingOnce (vector<int> vec) {     // TC: O(N^2)   SC: O(1)
    int n = vec.size();

    for (int i=0; i<n; i++) {
        int num = vec[i];
        int counter = 0;
        for (int j=0; j<n; j++) {
            if (vec[j] == num) {
                counter++;
            }
        }
        if (counter == 1) {
            return num;
        }
    }
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