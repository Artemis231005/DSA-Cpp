#include<iostream>
using namespace std;

void reverseArr1 (int arr[], int i, int n) {

    if (i >= n / 2) {
        return;
    }
    swap(arr[i], arr[n - i - 1]);
    reverseArr1(arr, i + 1, n);
}

void print (int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    int arr[100];
    cout << "Enter size of arr: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    print(arr, n);
    
    reverseArr1(arr, 0, n);
    print(arr, n);
    return 0;
}