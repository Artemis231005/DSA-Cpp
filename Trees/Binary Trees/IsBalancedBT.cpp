#include <iostream>
#include <queue>
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

    void insertNode(int value) {
        Node* newNode = new Node(value);
        if (root == NULL) {
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (temp->left == NULL) {
                temp->left = newNode;
                return;
            } else {
                q.push(temp->left);
            }

            if (temp->right == NULL) {
                temp->right = newNode;
                return;
            } else {
                q.push(temp->right);
            }
        }
    }

    int height(Node* root) {  
        if (root == NULL) {
            return 0;
        }

        int lh = height(root->left);
        int rh = height(root->right);

        return 1 + max(lh, rh);
    }

    bool isBalanced(Node* root) {   // TC: O(N^2) (traversing N nodes and O(N) for height of left & right)   
                                    // SC: O(h) (recursion stack space) (O(h) = logN if balanced, N is skewed)
        if (root ==NULL) {
            return true;
        }

        int lh = height(root->left);
        int rh = height(root->right);

        if (abs(rh-lh) > 1) {
            return false;
        }

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        if (!left || !right) {
            return false;
        }
        return true;
    }

    int check(Node* root) {     // Better approach, TC: O(N) O(N) (recursion stack space)
        if (root == NULL) {
            return 0;
        }

        int lh = check(root->left);
        if (lh == -1) {         // left is unbalanced => whole tree is unbalanced
            return -1;
        }
        int rh = check(root->right);
        if (rh == -1) {
            return -1;
        }

        if (abs(lh-rh) > 1) {
            return -1;
        }
        return 1 + max(lh, rh);
    }
};

int main() {
    BT tree;
    int n, val;
    cout << "Enter no of nodes that you want to enter: ";
    cin >> n;

    cout << "Enter the values in the node: ";
    for (int i=0; i<n; i++) {
        cin >> val;
        tree.insertNode(val);
    }

    if (tree.isBalanced(tree.root)) {
        cout << "This tree IS balanced" << endl;
    } else {
        cout << "This tree IS NOT balanced" << endl;
    }

    if (tree.check(tree.root) == -1) {
        cout << "This tree IS NOT balanced" << endl;
    } else {
        cout << "This tree IS balanced" << endl;
    }
    return 0;
}
