#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    vector<Node*> children;
    int k;                                  // Maximum number of children

    Node(int val, int maxChildren) {
        data = val;
        k = maxChildren;
    }
};

class KTree {
public:
    Node* root;
    int k;

    KTree(int m) {
        root = NULL;
        k = m;
    }

    // Insert node under a parent value
    bool insert(int parentVal, int val) {
        if (root == NULL) {
            root = new Node(val, k);
            return true;
        }

        Node* parent = findNode(root, parentVal);
        if (parent == NULL) {
            cout << "Parent " << parentVal << " not found.\n";
            return false;
        }

        if (parent->children.size() >= k) {
            cout << "Parent " << parentVal << " already has " << k << " children.\n";
            return false;
        }

        Node* child = new Node(val, k);
        parent->children.push_back(child);
        return true;
    }

    Node* findNode(Node* node, int val) {
        if (node == NULL) {
            return NULL;
        }
        if (node->data == val) {
            return node;
        }
        for (auto child : node->children) {
            Node* temp = findNode(child, val);
            if (temp != nullptr) {
                return temp;
            }
        }
        return nullptr;
    }

    bool deleteNode(int val) {
        if (root == NULL) {
            return false;
        }

        if (root->data == val) {
            deleteSubtree(root);
            root = NULL;
            return true;
        }

        return deleteNodeHelper(root, val);
    }

    bool deleteNodeHelper(Node* node, int val) {
        for (int i = 0; i < node->children.size(); i++) {

            if (node->children[i]->data == val) {
                deleteSubtree(node->children[i]);
                node->children.erase(node->children.begin() + i);
                return true;
            } 
            else {
                if (deleteNodeHelper(node->children[i], val)) {
                    return true;
                }
            }
        }
        return false;
    }

    void deleteSubtree(Node* node) {
        for (auto child : node->children) {
            deleteSubtree(child);
        }
        delete node;
    }

    void preorder(Node* node) {
        if (node == NULL) {
            return;
        }
        cout << node->data << " ";
        for (auto child : node->children) {
            preorder(child);
        }
    }
};

int main() {
    KTree tree(3);
    tree.insert(0, 1); 
    tree.insert(1, 2);
    tree.insert(1, 3);
    tree.insert(1, 4);
    tree.insert(2, 5);
    tree.insert(2, 6);

    cout << "Preorder traversal: ";
    tree.preorder(tree.root);
    cout << endl;

    cout << "Deleting node 2: ";
    tree.deleteNode(2);
    tree.preorder(tree.root);
    cout << endl;

    return 0;
}
