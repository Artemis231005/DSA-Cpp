#include <iostream>
#include <list>
using namespace std;

// TC: O(max(N1, N2))     SC: O(max(N1, N2))       N!: length of l1

list<int> add2No (list<int> &l1, list<int> &l2) {
    auto t1 = l1.begin();
    auto t2 = l2.begin();
    list<int> result;
    int carry = 0;
    int sum = 0;

    while (t1 != l1.end() || t2 != l2.end() || carry) {    // (We also include carry so the last carry is not lost.)
        sum = carry;
        if (t1 != l1.end()) {
            sum += *t1;
            t1++;
        }
        if (t2 != l2.end()) {
            sum += *t2;
            t2++;
        }
        result.push_back(sum % 10);
        carry = sum / 10;
    }
    return result;
}

void display(list<int>& l) {
    for (int data: l) {
        cout << data << " -> ";
    }
    cout << "NULL" << endl;
}

int main() {
    list<int> l1;
    l1.push_back(3);
    l1.push_back(5);

    list<int> l2;
    l2.push_back(4);
    l2.push_back(5);
    l2.push_back(9);
    l2.push_back(9);

    list<int> result = add2No (l1, l2);

    cout << "Result (in reverse order): ";
    display(result);
    return 0;
}

// Here, you’re not using the returned value of t1++ or ++t1.
// You only care that t1 is incremented for the next loop iteration.

// Pre-increment (++it):
// Increment happens first.
// The updated iterator is returned.

// Post-increment (it++):
// A copy of the current iterator is made.
// The original iterator is incremented.
// The copy (the old value) is returned.

// When would it differ?
// cout << *t1++ << endl;  // uses the old value, then increments
// cout << *++t1 << endl;  // increments first, then uses new value

// Here, results will be different because the returned value matters.