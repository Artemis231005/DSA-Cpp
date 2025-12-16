#include <iostream>
#include <vector>
using namespace std;

int findMissingNumber (vector<int> vec, int N) {        // TC: O(N^2)   SC: O(1)
    for (int i=1; i<=N; i++) {
        bool flag = false;
        for (int j=0; j<N-1; j++) {
            if (vec[j] == i) {
                flag = true;
                break;
            }
        }
        if (flag == false) {
            return i;
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
    cout << "Enter value of N: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n-1; i++) {
        cin >> elem;
        vec.push_back(elem);
    }

    cout << "The missing number is: " << findMissingNumber(vec, n);
    return 0;
}