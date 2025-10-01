#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int d) {
        data = d;
        left = right = NULL;
        height = 1;
    }
};

class AVLTree {
public:
    Node* root;

    AVLTree() {
        root = NULL;
    }

    int height(Node* node) {
        if (node == NULL) {
            return 0;
        } else {
            return node->height;
        }
    }

    int getBF(Node* node) {
        if (node == NULL) {
            return 0;
        } else {
            return height(node->left) - height(node->right);
        }
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    Node* insert(Node* node, int val) {
        if (node == NULL) {
            return new Node(val);
        }

        if (val < node->data) {
            node->left = insert(node->left, val);
        }
        else if (val > node->data) {
            node->right = insert(node->right, val);
        }
        else {
            return node;
        }

        node->height = 1 + max(height(node->left), height(node->right));
        int bf = getBF(node);

        if (bf > 1 && val < node->left->data) {
            return rightRotate(node);
        }

        if (bf < -1 && val > node->right->data) {
            return leftRotate(node);
        }

        if (bf > 1 && val > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (bf < -1 && val < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    Node* deleteNode(Node* root, int key) {
        if (root == NULL) {
            return root;
        }

        if (key < root->data) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->data) {
            root->right = deleteNode(root->right, key);
        }
        else {
            if ((root->left == NULL) || (root->right == NULL)) {
                Node* temp;
                if (root->left != NULL) {
                    temp = root->left;
                } else {
                    temp = root->right;
                }

                if (temp == NULL) {
                    temp = root;
                    root = NULL;
                } else {
                    *root = *temp;
                }
                delete temp;
            }
            else {
                Node* temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }

        if (root == NULL) {
            return root;
        }

        root->height = 1 + max(height(root->left), height(root->right));
        int bf = getBF(root);

        if (bf > 1 && getBF(root->left) >= 0) {
            return rightRotate(root);
        }

        if (bf > 1 && getBF(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (bf < -1 && getBF(root->right) <= 0) {
            return leftRotate(root);
        }

        if (bf < -1 && getBF(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
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
    AVLTree tree;
    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 40);
    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 25);

    cout << "Inorder before deletion: ";
    tree.inorderTraversal(tree.root);
    cout << endl;

    tree.root = tree.deleteNode(tree.root, 40);

    cout << "Inorder after deletion: ";
    tree.inorderTraversal(tree.root);
    cout << endl;

    return 0;
}
