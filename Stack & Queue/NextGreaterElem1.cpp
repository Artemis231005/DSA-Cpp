#include<iostream>
using namespace std;

void display (int arr[], int n) {
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void nextGreaterElem(int arr[], int n) {
    int nge[100];
    for (int i = 0; i < n; i++) {
        nge[i] = -1;
        for (int j = i+1; j < n; j++) {
            if (arr[j] > arr[i]) {
                nge[i] = arr[j];
                break;
            }
        }
    }
    cout << "The array of next greater elem is: ";
    display(nge, n);
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

    nextGreaterElem(arr, n);
    return 0;
}