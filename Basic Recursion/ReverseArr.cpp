#include<iostream>
using namespace std;

void reverseArr (int arr[], int start, int end) {
    if (start == end) {
        return;
    }
    swap(arr[start], arr[end]);
    reverseArr(arr, start + 1, end - 1);
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

    cout << "Enter values:";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    print(arr, n);
    
    reverseArr(arr, 0, n - 1);
    print(arr, n);
    return 0;
}