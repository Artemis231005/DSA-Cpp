#include<iostream>
using namespace std;

void SelectionSort(int arr[], int n) {
    for (int i=0; i<n-1; i++) {
        int minIdx = i;
        
        for (int j=0; j< n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

void printArr (int arr[], int n) {
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int n, arr[100];
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Before sorting: ";
    printArr(arr, n);
    cout << endl;
    cout << "After sorting: ";
    SelectionSort(arr, n);
    printArr(arr, n);
    return 0;
}