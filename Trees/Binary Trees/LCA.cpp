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

    Node* lowestCommonAncestor (Node* root, int x, int y) {   // TC: O(N)   SC: O(H)
        if (root == NULL) {
            return NULL;
        }

        if (root->data == x || root->data == y) {
            return root;
        }
        Node* left = lowestCommonAncestor(root->left, x, y);
        Node* right = lowestCommonAncestor(root->right, x, y);

        if (left == NULL) {
            return right;
        } else if (right == NULL) {
            return left;
        } else {
            return root;
        }
    }
};

int main() {
    BT tree;
    int n, val;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<string> arr(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    tree.insertNode(arr);

    int x, y;
    cout << "Enter the values of the nodes for which you want to find lowest common ancestor: ";
    cin >> x >> y;

    Node* ans = tree.lowestCommonAncestor(tree.root, x, y);

    if (ans) {
        cout << "Lowest common ancestor for " << x << " and " << y << " is: " << ans->data;
    } else {
        cout << "Invalid";
    }
    return 0;
}
