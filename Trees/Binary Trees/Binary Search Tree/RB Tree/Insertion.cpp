#include <iostream>
using namespace std;

enum Color 
{ RED, BLACK };

class Node {
public:
    int data;
    Color color;
    Node* left;
    Node* right;
    Node* parent;

    Node(int val) {
        data = val;
        color = RED;                                         // New nodes are initially red
        left = right = parent = NULL;
    }
};

class RBTree {
public:
    Node* root;

    RBTree() {
        root = NULL;
    }

    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;

        if (y->left != NULL) {
            y->left->parent = x;
        }

        y->parent = x->parent;
        if (x->parent == NULL) {
            root = y;
        }
        else if (x == x->parent->left) {
            x->parent->left = y;
        }
        else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node* y) {
        Node* x = y->left;
        y->left = x->right;

        if (x->right != NULL) {
            x->right->parent = y;
        }

        x->parent = y->parent;
        if (y->parent == NULL) {
            root = x;
        }
        else if (y == y->parent->left) {
            y->parent->left = x;
        }
        else {
            y->parent->right = x;
        }
        x->right = y;
        y->parent = x;
    }

    void fixInsert(Node* z) {
        while (z->parent != NULL && z->parent->color == RED) {
            if (z->parent == z->parent->parent->left) {

                Node* y = z->parent->parent->right;                 // Uncle node

                if (y != NULL && y->color == RED) {                 // Case 1: Uncle is red
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else {
                    if (z == z->parent->right) {                    // Case 2: Uncle is black & z is right child
                        z = z->parent;
                        leftRotate(z);
                    }

                    z->parent->color = BLACK;                       // Case 3: Uncle is black & z is left child
                    z->parent->parent->color = RED;
                    rightRotate(z->parent->parent);
                }
            }
            else {
                Node* y = z->parent->parent->left;                  // Uncle node

                if (y != NULL && y->color == RED) {                 // Case 1: Uncle is red
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }

                else {
                    if (z == z->parent->left) {                     // Case 2 (mirror): Uncle is black & z is left child
                        z = z->parent;
                        rightRotate(z);
                    }
                    z->parent->color = BLACK;                       // Case 3 (mirror): Uncle is black & z is right child
                    z->parent->parent->color = RED;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color = BLACK;  // Root is always black
    }

    void insert(int val) {
        Node* z = new Node(val);
        Node* y = NULL;
        Node* x = root;

        while (x != NULL) {
            y = x;
            if (z->data < x->data) {
                x = x->left;
            }
            else if (z->data > x->data) {
                x = x->right;
            }
            else {
                delete z; 
                return;
            }
        }

        z->parent = y;
        if (y == NULL) {
            root = z;
        }
        else if (z->data < y->data) {
            y->left = z;
        }
        else {
            y->right = z;
        }

        // Fix violations
        fixInsert(z);
    }

    void inorder(Node* node) {
        if (node == NULL) {
            return;
        }
        inorder(node->left);
        if (node->color == RED) {
            cout << node->data << "(" << "R) ";
        } else {
            cout << node->data << "(" << "B) ";
        }
        inorder(node->right);
    }
};

int main() {
    RBTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(15);
    tree.insert(25);
    tree.insert(5);

    cout << "Inorder traversal: ";
    tree.inorder(tree.root);

    return 0;
}
