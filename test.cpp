#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class BT {
public:
    Node* root;

    BT() {
        root = NULL;
    }

    void insertNode(vector<string>& vec) {
        if (vec.empty() || vec[0] == "null") {
            return;
        }

        root = new Node(stoi(vec[0]));
        queue<Node*> q;
        q.push(root);
        int i = 1;

        while (!q.empty() && i < vec.size()) {
            Node* curr = q.front();
            q.pop();

            if (i < vec.size() && vec[i] != "null") {
                curr->left = new Node(stoi(vec[i]));
                q.push(curr->left);
            }
            i++;

            if (i < vec.size() && vec[i] != "null") {
                curr->right = new Node(stoi(vec[i]));
                q.push(curr->right);
            }
            i++;
        }
    }
};

int main() {
    BT tree;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<string> arr(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    tree.insertNode(arr);

    return 0;
}
