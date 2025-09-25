#include <iostream>
#include <vector>
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

    void searchNode(Node* node, int val) {          // TC: O(log2(N))
        while (node != NULL && node->data != val) {
            if (val < node->data) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        
        if (node != NULL) {
            cout << "Found node with value: " << val << endl;
        } else {
            cout << val << " Not found" << endl;
        }
    }
};

int main() {
    BST tree;
    tree.insertNode(6);
    tree.insertNode(3);
    tree.insertNode(8);
    tree.insertNode(2);
    tree.insertNode(4);
    tree.insertNode(7);

    tree.searchNode(tree.root, 2);
    tree.searchNode(tree.root, 10);
    return 0;
}
