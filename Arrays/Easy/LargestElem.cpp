#include<iostream>
using namespace std;

int main() {
    int n, arr[100];
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int max = arr[0];
    for (int i=0; i<n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    cout << "Max element in array is: " << max;
    return 0;
}