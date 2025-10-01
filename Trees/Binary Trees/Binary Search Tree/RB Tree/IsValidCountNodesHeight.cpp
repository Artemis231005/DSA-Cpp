#include <iostream>
using namespace std;

enum Color { RED, BLACK };

class Node {
public:
    int data;
    Color color;
    Node* left;
    Node* right;
    Node* parent;

    Node(int val) {
        data = val;
        color = RED;
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
                Node* y = z->parent->parent->right;

                if (y != NULL && y->color == RED) { 
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else {
                    if (z == z->parent->right) { 
                        z = z->parent;
                        leftRotate(z);
                    }
                    z->parent->color = BLACK;     
                    z->parent->parent->color = RED;
                    rightRotate(z->parent->parent);
                }
            }
            else {
                Node* y = z->parent->parent->left;

                if (y != NULL && y->color == RED) { 
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else {
                    if (z == z->parent->left) { 
                        z = z->parent;
                        rightRotate(z);
                    }
                    z->parent->color = BLACK;   
                    z->parent->parent->color = RED;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color = BLACK;
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

        fixInsert(z);
    }

    bool isRootBlack() {
        if (root == NULL) {
            return true;
        } 
        return root->color == BLACK;
    }

    bool noRedRed(Node* node) {
        if (node == NULL) {
            return true;
        }

        if (node->color == RED) {
            if ((node->left != NULL && node->left->color == RED) || (node->right != NULL && node->right->color == RED)) {
                return false;
            }
        }
        return noRedRed(node->left) && noRedRed(node->right);
    }

    int blackHeight(Node* node) {
        if (node == NULL) {                                 // NULL counts as black
            return 1;
        }         
        int leftHeight = blackHeight(node->left);
        int rightHeight = blackHeight(node->right);

        if (leftHeight == 0 || rightHeight == 0 || leftHeight != rightHeight) {
            return 0; 
        }

        if (node->color == BLACK) {
            return leftHeight + 1;
        }
        return leftHeight + 0;
    }

    bool isValidRBTree() {
        if (!isRootBlack()) {
            return false;
        }
        if (!noRedRed(root)) {
            return false;
        }
        if (blackHeight(root) == 0) {
            return false;
        }
        return true;
    }

    int countBlackNodes(Node* node) {
        if (node == NULL) {                               
            return 1; 
        } 
        int left = countBlackNodes(node->left);
        int right = countBlackNodes(node->right);

        if (left == 0 || right == 0 || left != right) {
            return 0;
        }
        if (node->color == BLACK) {
            return left + 1;
        }
        return left + 0;
    }

    void inorder(Node* node) {
        if (node == NULL) return;
        inorder(node->left);
        if (node->color == RED) {
            cout << node->data << "(" << "R) ";
        } else {
            cout << node->data << "(" << "B) ";
        }
        inorder(node->right);
    }

    int countNodes(Node* node) {
        if (node == NULL) {
            return 0;
        }
        return 1 + countNodes(node->left) + countNodes(node->right);
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

    cout << "Inorder traversal after insertion: ";
    tree.inorder(tree.root);
    cout << "\n";

    cout << "Total nodes: " << tree.countNodes(tree.root) << "\n";
    cout << "Black height: " << tree.blackHeight(tree.root) << "\n";
    cout << "Is valid RB tree? " << (tree.isValidRBTree() ? "YES" : "NO") << "\n";

    return 0;
}
