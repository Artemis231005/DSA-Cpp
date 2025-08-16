#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void display(vector<int> &vec) {
    for (int i=0; i<vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void NextGreaterElem(vector<int> vec) {
    int n = vec.size();
    stack<int> st;
    vector<int> nge(n, -1);

    for(int i = vec.size() - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= vec[i]) {
            st.pop();
        }
        if (!st.empty()) {
            nge[i] = st.top();
        }
        st.push(vec[i]);
    }

    cout << "Next Greater Elements: ";
    display(nge);
}

int main() {
    vector<int> vec;
    int n;
    cout <<"Enter no of elem: ";
    cin >> n;

    cout << "Enter value of elem: ";
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        vec.push_back(x);
    }
    display(vec);

    NextGreaterElem(vec);
    return 0;
}