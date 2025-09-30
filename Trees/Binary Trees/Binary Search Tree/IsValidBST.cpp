#include <iostream>
#include <climits>
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

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    void insertNode(int val) {    
        Node* newNode = new Node(val);
        if (root == NULL) {
            root = newNode;
            return;
        }

        Node* temp = root;
        while (temp != NULL) {
            if (temp->data < val) {
                if (temp->right != NULL) {
                    temp = temp->right;
                } else {
                    temp->right = newNode;
                    return;
                }
            } else {
                if (temp->left != NULL) {
                    temp = temp->left;
                } else {
                    temp->left = newNode;
                    return;
                }
            }
        }
    }

    bool isValidBST (Node* root) {      // TC: O(N)   SC: O(H)
        return isValidBSTHelper(root, INT_MIN, INT_MAX);
    }

    bool isValidBSTHelper (Node* root, long minVal, long maxVal) {
        if (root == NULL) {
            return true;
        }
        if (root->data >= maxVal || root->data <= minVal) {
            return false;
        }

        return isValidBSTHelper(root->left, minVal, root->data) && isValidBSTHelper(root->right, root->data, maxVal);
    }

    void inorderTraversal(Node* node) {
        if (node == NULL) {
            return;
        }
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }
};

int main() {
    BST tree;
    int n, val;
    cout << "Enter number of elments: ";
    cin >> n;
    cout << "Enter values: ";
    for (int i=0; i<n; i++) {
        cin >> val;
        tree.insertNode(val);
    }

    tree.inorderTraversal(tree.root);
    cout << endl;

    if (tree.isValidBST(tree.root)) {
        cout << "This is a valid BST tree" << endl;
    } else {
        cout << "This is not a valid BST tree" << endl;
    }
    return 0;
}
