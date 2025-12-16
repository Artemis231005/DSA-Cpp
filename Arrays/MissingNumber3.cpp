#include <iostream>
#include <vector>
using namespace std;

int findMissingNumber (vector<int> vec, int N) {            // TC: O(N)   SC: O(1)
    int nSum = (N * (N+1)) / 2;
    int tSum = 0;
    for (int i=0; i<vec.size(); i++) {
        tSum += vec[i];
    }
    return nSum - tSum;
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