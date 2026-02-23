#include <iostream>
using namespace std;

// TC: O(2^N)   SC: O(N)
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }

    towerOfHanoi(n - 1, source, destination, auxiliary);
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

// To move N disks from A to C, move N−1 disks from A to B using C, then move the largest disk from A to C and 
// move N−1 disks from B to C using A

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}