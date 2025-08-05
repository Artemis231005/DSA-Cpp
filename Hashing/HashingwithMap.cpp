#include<iostream>
#include<map>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[100];
    map <int, int> mpp;

    cout << "Enter elements inside array: ";
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        mpp[arr[i]] ++;
    }

    // map stores values in sorted order
    for (auto it: mpp) {
        cout << it.first << " : " << it.second << "\t";
    }

    int no;
    cout << "Enter number whose frequency you want: ";
    cin >> no;
    cout << "Frequency is: " << mpp[no] << endl;
    return 0;
}