#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int lthread;
    int rthread;

    Node(int val) {
        data = val;
        left = right = NULL;
        lthread = rthread = 1;              // initially both threads are true
    }
};

class TBT {
public:
    Node* root;

    TBT() {
        root = NULL;
    }

    Node* insert(Node* root, int val) {
        Node* temp = root;
        Node* parent = NULL;

        while (temp != NULL) {
            if (val == temp->data) {
                cout << "Duplicate Key not allowed" << endl;
                return root;
            }
            parent = temp;

            if (val < temp->data) {
                if (temp->lthread == 0) {
                    temp = temp->left;
                }
                else {
                    break;
                }
            } else {
                if (temp->rthread == 0) {
                    temp = temp->right;
                }
                else {
                    break;
                }
            }
        }

        Node* newNode = new Node(val);
        if (parent == NULL) {
            root = newNode;
        } 
        else if (val < parent->data) {
            newNode->left = parent->left;
            newNode->right = parent;
            parent->lthread = 0;
            parent->left = newNode;
        } 
        else {
            newNode->right = parent->right;
            newNode->left = parent;
            parent->rthread = 0;
            parent->right = newNode;
        }

        return root;
    }

    Node* inorderSuccessor(Node* temp) {
        if (temp->rthread == 1) {
            return temp->right;
        }

        temp = temp->right;
        while (temp->lthread == 0) {
            temp = temp->left;
        }
        return temp;
    }

    void inorderTraversal(Node* root) {
        if (root == NULL) {
            return;
        }

        Node* temp = root;
        while (temp->lthread == 0) {
            temp = temp->left;
        }

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = inorderSuccessor(temp);
        }
    }

    Node* deleteNode(Node* root, int key) {
        Node* parent = NULL;
        Node* temp = root;

        while (temp != NULL) {
            if (key == temp->data) {
                break;
            }
            parent = temp;
            if (key < temp->data) {
                if (temp->lthread == 0) {
                    temp = temp->left;
                }
                else {
                    temp = NULL;
                }
            } else {
                if (temp->rthread == 0) {
                    temp = temp->right;
                }
                else {
                    temp = NULL;
                }
            }
        }

        if (temp == NULL) {
            cout << "Key not found" << endl;
            return root;
        }

        // Case A: Node with two children
        if (temp->lthread == 0 && temp->rthread == 0) {
            Node* parsucc = temp;
            Node* succ = temp->right;
            while (succ->lthread == 0) {
                parsucc = succ;
                succ = succ->left;
            }
            temp->data = succ->data;
            temp = succ;
            parent = parsucc;
        }

        // Case B & C: Node with one or no child
        Node* child = NULL;
        if (temp->lthread == 0) {
            child = temp->left;
        }
        else if (temp->rthread == 0) {
            child = temp->right;
        }

        if (parent == NULL) {
            root = child;
        } else if (temp == parent->left) {
            if (child != NULL) {
                parent->left = child;
            }
            else {
                parent->lthread = 1;
                parent->left = temp->left;
            }
        } else {
            if (child != NULL) {
                parent->right = child;
            }
            else {
                parent->rthread = 1;
                parent->right = temp->right;
            }
        }

        if (child != NULL) {
            Node* s = inorderSuccessor(temp);
            Node* p = inorderPredecessor(temp);

            if (temp->lthread == 0) {
                p->right = s;
            }
            else if (temp->rthread == 0) {
                s->left = p;
            }
        }

        delete temp;
        return root;
    }

    Node* inorderPredecessor(Node* temp) {
        if (temp->lthread == 1) {
            return temp->left;
        }

        temp = temp->left;
        while (temp->rthread == 0) {
            temp = temp->right;
        }
        return temp;
    }
};

int main() {
    TBT tree;

    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 5);
    tree.root = tree.insert(tree.root, 16);
    tree.root = tree.insert(tree.root, 14);
    tree.root = tree.insert(tree.root, 17);

    cout << "Inorder traversal before deletion: ";
    tree.inorderTraversal(tree.root);
    cout << endl;

    tree.root = tree.deleteNode(tree.root, 10);

    cout << "Inorder traversal after deletion: ";
    tree.inorderTraversal(tree.root);
    cout << endl;

    return 0;
}
