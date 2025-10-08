#include <iostream>
using namespace std;

const int MAX = 3;  // Order of B+ Tree (max keys in a node)

class Node {
public:
    int keys[MAX + 1];
    Node* child[MAX + 2];
    int count;
    bool leaf;

    Node(bool isLeaf = true) {
        leaf = isLeaf;
        count = 0;
        for (int i = 0; i < MAX + 2; i++)
            child[i] = NULL;
    }
};

class BPlusTree {
public:
    Node* root;

    BPlusTree() {
        root = new Node(true);
    }

    void traverse(Node* temp) {
        if (temp == NULL) {
            return;
        }
        for (int i = 0; i < temp->count; i++) {
            if (!temp->leaf) {
                traverse(temp->child[i]);
            }
            cout << temp->keys[i] << " ";
        }
        if (!temp->leaf) {
            traverse(temp->child[temp->count]);
        }
    }

    void traverse() {
        traverse(root);
    }

    Node* search(Node* temp, int key) {
        if (temp == NULL) {
            return NULL;
        }

        int i = 0;
        while (i < temp->count && key > temp->keys[i]) {
            i++;
        }
        if (i < temp->count && key == temp->keys[i]) {
            return temp;
        }
        if (temp->leaf) {
            return NULL;
        }
        return search(temp->child[i], key);
    }

    Node* search(int key) {
        return search(root, key);
    }

    void insert(int key) {
        if (root->count == MAX) {
            Node* newRoot = new Node(false);
            newRoot->child[0] = root;
            splitChild(newRoot, 0);
            int i = 0;

            if (key > newRoot->keys[0]) {
                i++;
            }
            insertNonFull(newRoot->child[i], key);
            root = newRoot;
        } else {
            insertNonFull(root, key);
        }
    }

    void insertNonFull(Node* temp, int key) {
        int i = temp->count - 1;
        if (temp->leaf) {
            while (i >= 0 && key < temp->keys[i]) {
                temp->keys[i + 1] = temp->keys[i];
                i--;
            }
            temp->keys[i + 1] = key;
            temp->count++;
        } else {
            while (i >= 0 && key < temp->keys[i]) {
                i--;
            }
            i++;
            if (temp->child[i]->count == MAX) {
                splitChild(temp, i);
                if (key > temp->keys[i]) {
                    i++;
                }
            }
            insertNonFull(temp->child[i], key);
        }
    }

    void splitChild(Node* parent, int i) {
        Node* y = parent->child[i];
        Node* z = new Node(y->leaf);
        int mid = MAX / 2;

        for (int j = mid + 1, k = 0; j < MAX; j++, k++) {
            z->keys[k] = y->keys[j];
        }
        z->count = MAX - mid - 1;
        y->count = mid;

        if (!y->leaf) {
            for (int j = mid + 1, k = 0; j <= MAX; j++, k++) {
                z->child[k] = y->child[j];
            }
        }

        for (int j = parent->count; j > i; j--) {
            parent->child[j + 1] = parent->child[j];
        }
        parent->child[i + 1] = z;

        for (int j = parent->count - 1; j >= i; j--) {
            parent->keys[j + 1] = parent->keys[j];
        }
        parent->keys[i] = y->keys[mid];
        parent->count++;
    }

    void remove(int key) {
        if (!root) {
            return;
        }
        remove(root, key);
        if (root->count == 0) {
            Node* temp = root;
            if (root->leaf) {
                root = NULL;
            }
            else {
                root = root->child[0];
            }
            delete temp;
        }
    }

    void remove(Node* temp, int key) {
        int idx = 0;
        while (idx < temp->count && temp->keys[idx] < key) {
            idx++;
        }

        if (idx < temp->count && temp->keys[idx] == key) {
            if (temp->leaf) {
                removeFromLeaf(temp, idx);
            }
            else {
                removeFromNonLeaf(temp, idx);
            }
        } else {
            if (temp->leaf) {
                return;
            }
            bool flag = (idx == temp->count);
            if (temp->child[idx]->count < (MAX + 1) / 2) {
                fill(temp, idx);
            }
            if (flag && idx > temp->count) {
                remove(temp->child[idx - 1], key);
            }
            else {
                remove(temp->child[idx], key);
            }
        }
    }

    void removeFromLeaf(Node* temp, int idx) {
        for (int i = idx + 1; i < temp->count; i++) {
            temp->keys[i - 1] = temp->keys[i];
        }
        temp->count--;
    }

    void removeFromNonLeaf(Node* temp, int idx) {
        int key = temp->keys[idx];

        if (temp->child[idx]->count >= (MAX + 1) / 2) {
            int pred = getPred(temp, idx);
            temp->keys[idx] = pred;
            remove(temp->child[idx], pred);
        } 
        else if (temp->child[idx + 1]->count >= (MAX + 1) / 2) {
            int succ = getSucc(temp, idx);
            temp->keys[idx] = succ;
            remove(temp->child[idx + 1], succ);
        } 
        else {
            merge(temp, idx);
            remove(temp->child[idx], key);
        }
    }

    int getPred(Node* temp, int idx) {
        Node* cur = temp->child[idx];
        while (!cur->leaf) {
            cur = cur->child[cur->count];
        }
        return cur->keys[cur->count - 1];
    }

    int getSucc(Node* temp, int idx) {
        Node* cur = temp->child[idx + 1];
        while (!cur->leaf) {
            cur = cur->child[0];
        }
        return cur->keys[0];
    }

    void fill(Node* temp, int idx) {
        if (idx != 0 && temp->child[idx - 1]->count >= (MAX + 1) / 2) {
            borrowFromPrev(temp, idx);
        }
        else if (idx != temp->count && temp->child[idx + 1]->count >= (MAX + 1) / 2) {
            borrowFromNext(temp, idx);
        }
        else {
            if (idx != temp->count) {
                merge(temp, idx);
            }
            else {
                merge(temp, idx - 1);
            }
        }
    }

    void borrowFromPrev(Node* temp, int idx) {
        Node* child = temp->child[idx];
        Node* sibling = temp->child[idx - 1];

        for (int i = child->count - 1; i >= 0; i--) {
            child->keys[i + 1] = child->keys[i];
        }
        if (!child->leaf) {
            for (int i = child->count; i >= 0; i--) {
                child->child[i + 1] = child->child[i];
            }
        }

        child->keys[0] = temp->keys[idx - 1];
        if (!child->leaf) {
            child->child[0] = sibling->child[sibling->count];
        }

        temp->keys[idx - 1] = sibling->keys[sibling->count - 1];
        child->count++;
        sibling->count--;
    }

    void borrowFromNext(Node* temp, int idx) {
        Node* child = temp->child[idx];
        Node* sibling = temp->child[idx + 1];
        child->keys[child->count] = temp->keys[idx];

        if (!child->leaf) {
            child->child[child->count + 1] = sibling->child[0];
        }

        temp->keys[idx] = sibling->keys[0];
        for (int i = 1; i < sibling->count; i++) {
            sibling->keys[i - 1] = sibling->keys[i];
        }
        if (!sibling->leaf) {
            for (int i = 1; i <= sibling->count; i++) {
                sibling->child[i - 1] = sibling->child[i];
            }
        }
        child->count++;
        sibling->count--;
    }

    void merge(Node* temp, int idx) {
        Node* child = temp->child[idx];
        Node* sibling = temp->child[idx + 1];
        child->keys[(MAX / 2)] = temp->keys[idx];

        for (int i = 0; i < sibling->count; i++) {
            child->keys[i + (MAX / 2) + 1] = sibling->keys[i];
        }
        if (!child->leaf) {
            for (int i = 0; i <= sibling->count; i++) {
                child->child[i + (MAX / 2) + 1] = sibling->child[i];
            }
        }
        for (int i = idx + 1; i < temp->count; i++) {
            temp->keys[i - 1] = temp->keys[i];
        }
        for (int i = idx + 2; i <= temp->count; i++) {
            temp->child[i - 1] = temp->child[i];
        }
        
        child->count += sibling->count + 1;
        temp->count--;
        delete sibling;
    }
};

int main() {
    BPlusTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(12);
    tree.insert(30);
    tree.insert(7);
    tree.insert(17);

    cout << "Traversal of B+ Tree: ";
    tree.traverse();

    cout << "\nDeleting 6: ";
    tree.remove(6);
    tree.traverse();

    cout << "\nDeleting 13: ";
    tree.remove(13);
    tree.traverse();

    cout << "\nDeleting 7: ";
    tree.remove(7);
    tree.traverse();

    cout << "\nDeleting 4: ";
    tree.remove(4);
    tree.traverse();
}
