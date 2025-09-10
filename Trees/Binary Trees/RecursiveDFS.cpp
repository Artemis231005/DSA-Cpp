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

    void preOrder(Node* root) {     // TC: O(N), N nodes are visited& SC: O(N) (worst case is skewed tree)
        if (root == NULL) {
            return;
        }

        cout << (root->data) << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void inOrder (Node* root) {
        if (root == NULL) {
            return;
        }

        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }

    void postOrder (Node* root) {
        if (root == NULL) {
            return;
        }

        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
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
};

int main() {
    BT tree;
    tree.insertNode(1);
    tree.insertNode(2);
    tree.insertNode(3);
    tree.insertNode(4);
    tree.insertNode(5);
    tree.insertNode(6);
    tree.insertNode(7);
    tree.insertNode(8);
    tree.insertNode(9);
    tree.insertNode(10);
    cout << "Pre-order traversal: ";
    tree.preOrder(tree.root);
    cout << "\nIn-order traversal: ";
    tree.inOrder(tree.root);
    cout << "\nPost-order traversal: ";
    tree.postOrder(tree.root);
    return 0;
}
