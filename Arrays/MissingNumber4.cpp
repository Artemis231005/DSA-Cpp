#include <iostream>
#include <vector>
using namespace std;

int findMissingNumber (vector<int> vec, int N) {// TC: O(N)  SC: O(1)  (better for high N values as sum will be too big but xor won't be)
    int xor1 = 0, xor2 = 0;
    for (int i=0; i<N-1; i++) {
        xor2 = xor2 ^ vec[i];
        xor1 = xor1 ^ (i+1);
    }
    xor1 = xor1 ^ N;
    return xor1 ^ xor2;
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