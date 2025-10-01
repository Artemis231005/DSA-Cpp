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

    // Insert a value
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

    Node* minNode(Node* node) {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }

    void fixDelete(Node* x, Node* parent) {
        while ((x != root) && (x == NULL || x->color == BLACK)) {

            if (x == parent->left) {
                Node* w = parent->right;

                if (w != NULL && w->color == RED) {                                  // Case 1
                    w->color = BLACK;
                    parent->color = RED;
                    leftRotate(parent);
                    w = parent->right;
                }

                if ((w == NULL) || 
                    ((w->left == NULL || w->left->color == BLACK) && (w->right == NULL || w->right->color == BLACK))) {   // Case 2
                    if (w != NULL) {
                        w->color = RED;
                    }
                    x = parent;
                    parent = x->parent;
                } 
                else {
                    if (w->right == NULL || w->right->color == BLACK) {             // Case 3
                        if (w->left != NULL) {
                            w->left->color = BLACK;
                        }
                        if (w != NULL) {
                            w->color = RED;
                            rightRotate(w);
                            w = parent->right;
                        }
                    }

                    if (w != NULL) {
                        w->color = parent->color;                                  // Case 4
                        parent->color = BLACK;
                        if (w->right != NULL) {
                            w->right->color = BLACK;
                        }
                        leftRotate(parent);
                    }
                    x = root;
                }
            } 
            else {
                Node* w = parent->left;

                if (w != NULL && w->color == RED) {                                // Case 1
                    w->color = BLACK;
                    parent->color = RED;
                    rightRotate(parent);
                    w = parent->left;
                }

                if ((w == NULL) || 
                    ((w->left == NULL || w->left->color == BLACK) && (w->right == NULL || w->right->color == BLACK))) {  // Case 2
                    if (w != NULL) {
                        w->color = RED;
                    }
                    x = parent;
                    parent = x->parent;
                } 
                else {
                    if (w->left == NULL || w->left->color == BLACK) {              // Case 3
                        if (w->right != NULL) {
                            w->right->color = BLACK;
                        }
                        if (w != NULL) {
                            w->color = RED;
                            leftRotate(w);
                            w = parent->left;
                        }
                    }
                    
                    if (w != NULL) {
                        w->color = parent->color;                                  // Case 4
                        parent->color = BLACK;
                        if (w->left != NULL) {
                            w->left->color = BLACK;
                        }
                        rightRotate(parent);
                    }
                    x = root;
                }
            }
        }
        if (x != NULL) {
            x->color = BLACK;
        }
    }

    void deleteValue(int val) {
        Node* z = root;
        while (z != NULL) {
            if (val < z->data) {
                z = z->left;
            }
            else if (val > z->data) {
                z = z->right;
            }
            else {
                break;
            }
        }
        if (z == NULL) {
            return;
        }

        Node* y = z;
        Node* x;
        Node* xParent = NULL;
        Color yOriginalColor = y->color;

        if (z->left == NULL) {
            x = z->right;
            xParent = z->parent;
            transplant(z, z->right);
        } 
        else if (z->right == NULL) {
            x = z->left;
            xParent = z->parent;
            transplant(z, z->left);
        } 
        else {
            y = minNode(z->right);
            yOriginalColor = y->color;
            x = y->right;
            if (y->parent == z) {
                if (x != NULL) {
                    x->parent = y;
                }
                xParent = y;
            } 
            else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
                xParent = y->parent;
            }

            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }

        delete z;

        if (yOriginalColor == BLACK) {
            fixDelete(x, xParent);
        }
    }

    // Replace subtree u with v
    void transplant(Node* u, Node* v) {
        if (u->parent == NULL) {
            root = v;
        }
        else if (u == u->parent->left) {
            u->parent->left = v;
        }
        else {
            u->parent->right = v;
        }
        if (v != NULL) {
            v->parent = u->parent;
        }
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
};

int main() {
    RBTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(15);
    tree.insert(25);
    tree.insert(5);

    cout << "Inorder after insertion: ";
    tree.inorder(tree.root);
    cout << "\n";

    tree.deleteValue(20);
    tree.deleteValue(15);

    cout << "Inorder after deletion: ";
    tree.inorder(tree.root);
    cout << "\n";

    return 0;
}
