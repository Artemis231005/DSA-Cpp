#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[100];
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // Precompute
    int hash[20] = {0};
    for (int i=0; i<n; i++) {
        hash[arr[i]] += 1;
    }

    int no;
    cout << "Enter number whose frequency you want: ";
    cin >> no;
    cout << "Frequency is: " << hash[no];
    return 0;
}