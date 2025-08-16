#include<iostream>
using namespace std;

// TC: O(N^2)       SC: O(N)

void display (int arr[], int n) {
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void prevSmallerElem (int arr[], int n) {
    int nse[100];
    for (int i = 0; i < n; i++) {       // have to manually set all elem to -1 in array
        nse[i] = -1;
    }

    for (int i=0; i<n; i++) {
        for (int j= i-1; j>=0; j--) {
            if (arr[j] < arr[i]) {
                nse[i] = arr[j];
                break;
            }
        }
    }
    cout << "Array of next smaller elem are: ";
    display(nse, n);
}

int main() {
    int n;
    cout << "Enter no of elem: ";
    cin >> n;
    int arr[100];

    cout << "Enter the value of the elem: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    display(arr, n);

    prevSmallerElem(arr, n);
    return 0;
}