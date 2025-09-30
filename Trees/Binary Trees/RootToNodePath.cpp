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

    vector<int> PrintRootToNode (Node* root, int givenNode) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        getPath(root, givenNode, ans);
        return ans;
    }

    bool getPath (Node* root, int givenNode, vector<int> &ans) {
        if (root == NULL) {
            return false;
        }
        ans.push_back(root->data);

        if (root->data == givenNode) {
            return true;
        }

        if (getPath(root->left, givenNode, ans) || getPath(root->right, givenNode, ans)) { 
            return true;
        }

        ans.pop_back();
        return false;
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

    cout << "Enter a node value for which you want to print from root to node: ";
    cin >> val;

    vector<int> ans = tree.PrintRootToNode(tree.root, val);
    if (ans.empty()) {
        cout << "Node not found" << endl;
    } else {
        for (int i: ans) {
        cout << i << " ";
    }
    cout << endl;
    }
    return 0;
}
