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

    bool isSymmetricTree (Node* root) {
        return root == NULL || isSymmetricHelper(root->left, root->right);
    }

    bool isSymmetricHelper(Node* left, Node* right) {
        if (left == NULL || right == NULL) {
            return left == right;
        }
        if (left->data != right->data) {
            return false;
        }

        return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
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

    if (tree.isSymmetricTree(tree.root)) {
        cout << "Is Symmetric" << endl;
    } else {
        cout << "Not symmetric" << endl;
    }
    return 0;
}
